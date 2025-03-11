#include <iostream>
#include <cassert>
#include <future>
#include <thread>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

struct Record {
    string s;
};

ostream& operator<<(ostream& os, const Record &r)
{
    return os << r.s;
}

template<typename T>
int wait_for_any(vector<future<T>>& vf, steady_clock::duration d)
{
    while (true) {
	for (int i = 0; i != vf.size(); ++i) {
	    if (!vf[i].valid()) continue;
	    switch (vf[i].wait_for(seconds{0})) {
	    case future_status::ready:
		return i;
	    case future_status::timeout:
		break;
	    case future_status::deferred:
		throw runtime_error("wait_for_all(): deferred future");
	    }
	}
	this_thread::sleep_for(d);
    }
}


template<typename Pred>
vector<Record*> find_all_rec(vector<Record>& vr, int first, int last, Pred pr)
{
    vector<Record*> res;
    vector<Record>::iterator p = vr.begin() + first;
    for (;(p = find_if(p, vr.begin() + last, pr)) != vr.begin() + last;
	 ++p)
	res.push_back(&*p);

    return res;
}

const int grain = 2;
template<typename Pred>
vector<Record*> pfind_all(vector<Record>& vr, Pred pr)
{
    assert(vr.size()%grain==0);
    vector<future<vector<Record*>>> res;
    
    for (int i = 0; i!=vr.size(); i+=grain)
	res.push_back(async(find_all_rec<Pred>,ref(vr),i,i+grain,pr));

    vector<Record*> v2;
    while (res.size()) {
	int i = wait_for_any(res, milliseconds{5});
	vector<Record*> p = res[i].get();
	for (auto& r : p)
	    v2.push_back(r);
	res.erase(res.begin()+i);
    }
	
    return v2;
}

int main()
{
    vector<Record> v = {{"abcd"}, {"lmno"}, {"qrst"}, {"efghi"}, {"lmno"}, {"qrst"}};

    vector<Record*> v2 = pfind_all(v, [](const Record& r){return r.s == "qrst";});
    for (auto& r : v2)
	cout << *r << ",";
    cout << '\n';
    
    return 0;
}

#include <iostream>
#include <cassert>
#include <future>
#include <thread>
#include <vector>
#include <algorithm>
using namespace std;

struct Record {
    string s;
};

ostream& operator<<(ostream& os, const Record &r)
{
    return os << r.s;
}

Record* find_rec(vector<Record>& vr, int first, int last, bool(*pr)(const Record&))
{
    vector<Record>::iterator p =
	std::find_if(vr.begin()+first,vr.begin()+last,pr);
    if (p == vr.begin()+last)
	return nullptr;
    return &*p;
}


const int grain = 1;
Record* pfind(vector<Record>& vr, bool(*pr)(const Record&))
{
    assert(vr.size()%grain==0);
    vector<future<Record*>> res;
    
    for (int i = 0; i!=vr.size(); i+=grain)
	res.push_back(async(find_rec,ref(vr),i,i+grain,pr));
    
    for (int i = 0; i!=res.size(); ++i)
	if (auto p = res[i].get())
	    return p;
    
    return nullptr;
}

int main()
{
    vector<Record> v = {{"abcd"}, {"efghi"}, {"lmno"}, {"qrst"}};

    Record *p = pfind(v, [](const Record& r){return r.s == "qrst";});
    cout << *p << '\n';
    
    return 0;
}

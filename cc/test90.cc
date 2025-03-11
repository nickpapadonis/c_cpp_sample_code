#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Record {
    int val;
};

auto rec_bef = [](const Record& r1, const Record& r2)
		  { return r1.val < r2.val; };

void f1(const vector<Record>& v)
{
    auto er = equal_range(v.begin(), v.end(), Record{1}, rec_bef);

    for (auto p = er.first; p != er.second; ++p)
	cout << p->val << " ";
    cout << endl;
}

bool comp(const Record& a, const Record& b)
{
    return a.val < b.val;
}

int main(int argc, char *argv[])
{
    vector<Record> v = {{0}, {1}, {5}, {1}, {0}};

    sort(v.begin(), v.end(), rec_bef);
    sort(v.begin(), v.end(), comp);
    
    f1(v);

    // pairs
    pair<int,int> a{0, 1};
    cout << a.first << " " << a.second << endl;
    // don't need to know type
    auto pp = make_pair(0, 1);
    cout << pp.first << " " << pp.second << endl;
    
    return 0;
}

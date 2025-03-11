#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

ostream& operator<<(ostream& os, const pair<int,int>& b)
{
    return os << b.first << ", " << b.second;
}

bool cmp(const pair<int,int>& a, pair<int,int>& b)
{
    return (a.first == b.first && a.second == b.second);
}

int main()
{
    vector<pair<int, int>> v {{0, 1}, {5, 6}, {1, 2}, {2, 3}, {1, 2}};
    vector<pair<int, int>> v2 {{1, 2}};
    vector<pair<int, int>>::iterator i;

    if ((i = find_end(v.begin(), v.end(), v2.begin(), v2.end()))!=v.end())
	cout << *i << endl;
    else
	cout << "not found";
#if 0
    i = v.begin();
    while ((i = find(i, v.end(), pair<int,int>{1, 2})) != v.end()) {
	cout << *i << endl;
	++i;
    }
    i = v.begin();
    while ((i = find_first_of(i, v.end(), v2.begin(), v2.end())) != v.end()) {
	cout << *i << endl;
	++i;
    }
    i = v.begin();
    while ((i = find_first_of(i, v.end(), v2.begin(), v2.end(), cmp)) != v.end()) {
	cout << *i << endl;
	++i;
    }
#endif
    
    return 0;
}

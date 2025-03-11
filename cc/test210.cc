#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v {0, 1, 2};
    vector<int> v2(v.size());

    transform(v.begin(), v.end(), v2.begin(),
	      [](int x){return x + 1;});

    for (auto& r : v2)
	cout << r;
    cout << endl;

    vector<int> v3 {1, 1};
    vector<int> v4 {1, 1};
    vector<int> vr(v3.size());

    transform(v3.begin(), v3.end(), v3.begin(), vr.begin(),
	      [](const int& x, const int& y){return x + y;});

    for (auto& r : vr)
	cout << r;
    cout << endl;

    vector<int> v5 {1, 1}; vector<int> v6 {2, 2};
    vector<int>::iterator res =
	transform(v5.begin(), v5.end(), v6.begin(), v5.begin(),
	      [](const int& x, const int& y){return x + y;});
    for (auto& r : v5)
	cout << r;
    cout << endl;

    if (res == v5.end())
	cout << "end" << endl;
    
    return 0;
}

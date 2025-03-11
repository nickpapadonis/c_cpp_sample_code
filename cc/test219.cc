#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    vector<int> v {1, 2, 3, 4};

    vector<int>::iterator p = remove(v.begin(), v.end(), 3);
    v.erase(p, v.end());
    p = remove_if(v.begin(), v.end(),
		  [](const int& x){return x > 3;});
    v.erase(p, v.end());

    for (auto& r : v)
	cout << r;
    cout << endl;

    vector<int> v2 {1, 2, 3, 4, 5, 6};
    vector<int> v3(v2.size());
    p = remove_copy(v2.begin(), v2.end(), v3.begin(), 4);
    v3.erase(p, v3.end());

    for (auto& r : v2)
	cout << r;
    cout << endl;

    vector<int> v4;
    auto bp = remove_copy(v2.begin(), v2.end(), back_inserter(v4), 6);

    for (auto& r : v4)
	cout << r;
    cout << endl;

    return 0;
}

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

template <class T>
bool f(T a, T b)
{
    return a < b;
}

int main()
{
    vector<int> l = {1, 0};

    sort(l.begin(), l.end(), f<int>);

    for (auto& r : l)
	cout << r;
    cout << endl;
    return 0;
}

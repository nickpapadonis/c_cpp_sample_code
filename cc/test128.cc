#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> f(const vector<int>& v)
{
    const int max = 5;
    vector<int> vg;
    
    for_each(v.begin(), v.end(),
	     [&](int x) {if (x > max) vg.push_back(x); });
    // & capture every local var by ref

    return vg;
}

int main(int argc, char *argv[])
{
    vector<int> v {0, 1, 6, 8};
    vector<int> v2;
    
    v2 = f(v);
    for (auto& p : v2)
	cout << p;
    cout << endl;

    return 0;
}

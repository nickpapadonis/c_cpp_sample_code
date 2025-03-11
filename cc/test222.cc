#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int main()
{
    vector<int> v {2, 1, 0};
    sort(v.begin(), v.end());
    do {
	for (auto& r : v)
	    cout << r;
	cout << endl;
    } while (next_permutation(v.begin(), v.end()));
    return 0;
}

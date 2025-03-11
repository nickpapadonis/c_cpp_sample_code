#include<iterator>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v0 {0, 1, 2, 2, 2, 3, 4, 5, 6, 8, 8};
    pair<vector<int>::iterator,
	 vector<int>::iterator> p = equal_range(v0.begin(),
						v0.end(),
						2);
    copy(p.first, p.second, ostream_iterator<int>(cout, ","));
    cout << endl;
    const int v = 7;
    vector<int>::iterator it = lower_bound(v0.begin(),
					   v0.end(),
					   v);
    if (it == v0.end())
	cout << "ve" << endl;
    vector<int>::iterator it2 = upper_bound(v0.begin(),
					   v0.end(),
					   v);
    copy(it, it2, ostream_iterator<int>(cout, ","));
    return 0;
}

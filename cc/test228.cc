#include<iterator>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v0 {0, 1, 2, 2, 2, 3, 4, 5, 6, 8, 8, 15, 20};

    const int v = 2;
    vector<int>::iterator it = lower_bound(v0.begin(),
					   v0.end(),
					   v);
    if (*it == 2 && it != v0.end())
	v0.insert(it, 1);

    it = lower_bound(v0.begin(), v0.end(), v);

    vector<int>::iterator it2 = upper_bound(v0.begin(),
					    v0.end(),
					    v);
    if (it2 != v0.end())
	v0.insert(it2, 3);

    pair<vector<int>::iterator,
	 vector<int>::iterator> erp = equal_range(v0.begin(), v0.end(),
						  15);
    cout << *erp.first << "," << *erp.second << endl;
    if (erp.first!=v0.end() && erp.second!=v0.end()) {
	v0.insert(erp.first, 14);
    }
    erp = equal_range(v0.begin(), v0.end(),
						  15);
    if (erp.first!=v0.end() && erp.second!=v0.end()) {
	v0.insert(erp.second, 16);
    }
   
    copy(v0.begin(), v0.end(), ostream_iterator<int>(cout, ","));
    return 0;
}

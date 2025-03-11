#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v0 {0, 1, 2};
    vector<int> v1 {0, 1, 3};

    if (equal(v0.begin(), v0.end(), v1.begin()))
	cout << "eq" << endl;
    
    pair<vector<int>::iterator, vector<int>::iterator> p
	= mismatch(v0.begin(), v0.end(), v1.begin());
    if (p.first != v0.end()) {
	cout << "mm: " << *p.first << ", " << *p.second << endl;
    }

    vector<int> v2 {0, 1, 2, 3, 4, 5, 6, 6, 6};
    vector<int> v3 {3, 4, 5};
    vector<int>::iterator i;
    if ((i = search(v2.begin(),v2.end(),v3.begin(),v3.end()))
	!= v2.end()) {
	for (vector<int>::iterator i2 = v3.begin();
	     i2 != v3.end(); ++i2)
	    cout << *i++;
	cout << endl;
    }

    if ((i = search_n(v2.begin(), v2.end(), 3, int{6})) != v2.end())
	for (int j = 0; j < 3; ++j)
	    cout << *(i + j);
    cout << endl;
	
    return 0;
}

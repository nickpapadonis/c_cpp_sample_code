#include<iterator>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v0 {0, 1, 1, 2, 3, 4, 5, 6, 6, 6};
    vector<int>::iterator it =
	lower_bound(v0.begin(), v0.end(), 1);
    copy(it, v0.end(), ostream_iterator<int>(cout, ","));
    cout << endl;
    it = upper_bound(v0.begin(), v0.end(), 5,
		     [](const int& a, const int& b){return a<b;});
    copy(it, v0.end(), ostream_iterator<int>(cout, ","));
    cout << endl;
    cout << "bs: " << binary_search(v0.begin(), v0.end(), 5) << endl;
    cout << "bs: " << binary_search(v0.begin(), v0.end(), 8) << endl;
    
    return 0;
}

#include<iterator>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v0 {9, 7, 6, 5, 2, 1, 3, 21, 6, 9};
    vector<int>::iterator it = find(v0.begin(), v0.end(),
				    21);
    copy(it, v0.end(), ostream_iterator<int>(cout, ","));
    return 0;
}

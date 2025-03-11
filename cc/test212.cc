#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

template<class It>
void pseq(It b, It e)
{
    for (It i = b;
	 i != e; ++i)
	cout << *i << ",";
    cout << endl;
}

int main()
{
    vector<int> v {9, 8, 2, 12, 12, 13, 9};
    sort(v.begin(), v.end());
    vector<int> v2;
    unique_copy(v.begin(), v.end(), back_inserter(v2));
    cout << endl;
    unique_copy(v.begin(), v.end(), ostream_iterator<int>(cout));
    cout << endl;
    pseq(v2.begin(), v2.end());
    vector<int>::iterator it = unique(v.begin(), v.end());
    pseq(v.begin(), it);
    it = remove(v.begin(), v.end(), 12);
    pseq(v.begin(), it);
    vector<int> v3;
    remove_copy(v.begin(), v.end(), back_inserter(v3), 12);
    pseq(v3.begin(), v3.end());
    v.erase(remove(v.begin(), v.end(), 13), v.end());
    pseq(v.begin(), v.end());
    reverse(v.begin(), v.end());
    pseq(v.begin(), v.end());
    return 0;
}

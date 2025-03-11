#include <set>
#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>
using namespace std;

int main()
{
    set<int> s = {2, 3, 1};
    set<int> s2 = {1};
    set<int> s3;
    vector<int> s4;
    
    copy(s.begin(), s.end(), ostream_iterator<int>(cout, ","));
    cout << endl;
    set_difference(s.begin(), s.end(), s2.begin(), s2.end(),
		     inserter(s3, s3.end()));

    set_difference(s.begin(), s.end(), s2.begin(), s2.end(),
		     inserter(s4, s4.end()));

    copy(s3.begin(), s3.end(), ostream_iterator<int>(cout, ","));
    cout << endl;
    copy(s4.begin(), s4.end(), ostream_iterator<int>(cout, ","));
		     
    return 0;
}

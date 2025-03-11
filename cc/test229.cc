#include<iterator>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v {3, 3, 5, 5, 10, 10};
    // first element which does not compare less
    // if all elements in range compare less then .end()
    vector<int>::iterator it = lower_bound(v.begin(), v.end(), 2);
    cout << "lb: " << *it << " pos: " << it - v.begin() << endl;
    v.insert(it, 1);
    // first element in range which is compares greater
    // if no element in range compare greater then .end()
    it = upper_bound(v.begin(), v.end(), 10);
    cout << "ub: " << *it << " pos: " << it - v.begin() << endl;
    v.insert(it, 11);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ","));
    
    return 0;
}

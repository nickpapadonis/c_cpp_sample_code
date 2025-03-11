#include<iterator>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v0 {9, 7, 6, 5, 2, 1, 3, 21, 6, 9};
    vector<int> v1 {v0};
    partial_sort(v0.begin(), v0.begin()+4, v0.end());
    nth_element(v1.begin(), v1.begin()+4, v1.end());
    copy(v0.begin(), v0.end(), ostream_iterator<int>{cout, ","});
    cout << endl;
    copy(v1.begin(), v1.end(), ostream_iterator<int>{cout, ","});
    return 0;
}

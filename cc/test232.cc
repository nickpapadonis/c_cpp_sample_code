#include<vector>
#include<iostream>
#include<iterator>
using namespace std;

int main()
{
    vector<int> v0 {6, 6, 6};
    vector<int> v1;

    copy(v0.begin(), v0.end(), inserter(v1, v1.end()));
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, ","));
    return 0;
}

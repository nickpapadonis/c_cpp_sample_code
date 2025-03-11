#include <iostream>
#include <numeric>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
    vector<int> v {1, 1, 2, 2, 3, 3};
    vector<int> v2;

    partial_sum(v.begin(), v.end(), inserter(v2, v2.end()),
		[](const int& x, const int& y){return x*y;});
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, ","));
    
    return 0;
}

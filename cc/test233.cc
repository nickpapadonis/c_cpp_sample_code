#include <functional>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
using namespace std;

int main()
{
    vector<int> v {0, 1, 1, 2};
    vector<int> v2;
    
    unique_copy(v.begin(), v.end(), inserter(v2, v2.end()), equal_to<int>{});
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, ","));
    
    return 0;
}

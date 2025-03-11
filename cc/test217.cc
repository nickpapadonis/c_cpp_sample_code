#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v {1, 1, 1};
    int count = 0;
    
    for_each(v.begin(), v.end(), [&count](const int& x){count += x;});

    cout << count << endl;

    vector<int> v2 {1, 2, 3};
    vector<int> v3;
    copy_if(v2.begin(), v2.end(), back_inserter(v3), [](const int& x){return x > 1;});
    for (auto& r : v3)
	cout << r;
    cout << endl;
    
    return 0;
}

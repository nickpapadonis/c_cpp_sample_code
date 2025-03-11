#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    vector<int> v0 {0, 1, 2};
#if 0    
    vector<int> v1;
    auto i = transform(v0.begin(), v0.end(), back_inserter(v1),
	      [](const int& x){return x + 1;});
#endif
    vector<int> v1(v0.size());
    vector<int>::iterator i = transform(v0.begin(), v0.end(), v1.begin(),
					[](const int& x){return x + 1;});
    if (i == v1.end())
	cout << "end" << endl;
    for (auto& r : v1)
	cout << r;
    cout << endl;

    return 0;
}

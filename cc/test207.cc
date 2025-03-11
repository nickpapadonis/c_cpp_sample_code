#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v {0, 2, 4, 6};
    vector<int> v2;

    for_each(v.begin(), v.end(), [&v2](int x){if (x > 2) {v2.push_back(x);}});

    if (all_of(v.begin(), v.end(), [](int x){return x >= 0;}))
	cout << "all >= 0" << endl;
    if (any_of(v.begin(), v.end(), [](int x){return x > 2;}))
	cout << "any > 2" << endl;
    if (none_of(v.begin(), v.end(), [](int x){return x > 6;}))
	cout << "none > 6" << endl;
    cout << count(v.begin(), v.end(), int{4}) << endl;
    cout << count_if(v.begin(), v.end(), [](int x) { return x > 2; }) << endl;
    return 0;
}

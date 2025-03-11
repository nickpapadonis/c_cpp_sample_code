#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    vector<int> v0 {0, 1, 2};
    vector<int> v1(v0.size());

    copy(v0.begin(), v0.end(), v1.begin());
    for (auto& r : v1)
	cout << r;
    cout << endl;

    reverse_copy(v0.begin(), v0.end(), v1.begin());
    for (auto& r : v1)
	cout << r;
    cout << endl;

    vector<int>::iterator e = copy_if(v0.begin(), v0.end(), v1.begin(), [](int x){return x > 0;});
    for (vector<int>::iterator i = v1.begin();
	 i != e; ++i)
	cout << *i;
    cout << endl;

    vector<int> z0 {1, 2, 3};
    vector<int> z1(z0.size());
    vector<int>::iterator i = move(z0.begin(), z0.end(), z1.begin());
    if (i == z1.end())
	cout << "end";

    cout << endl;
    copy(v0.begin(), v0.end(), ostream_iterator<int>(cout));
    cout << endl;
    
    vector<int> v7;
    copy(v0.begin(), v0.end(), back_inserter(v7));
    for (auto& r : v7)
	cout << r;
    cout << endl;

    cout << endl;
    vector<int> v9 {2, 4, 6, 8, 10};
    copy_if(v9.begin(), v9.end(), ostream_iterator<int>(cout),
	 [](const int& x){return x > 6;});
    cout << endl;

    return 0;
}

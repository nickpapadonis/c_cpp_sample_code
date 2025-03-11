#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    vector<int> v {2, 9, 3, 1, 7};

    vector<int>::iterator it = partition(v.begin(), v.end(),
					 [](const int& x){return x < 5;});

    vector<int>::iterator it2;
    for (it2 = v.begin(); it2 != it; ++it2)
	cout << *it2;
    cout << endl;
    for (it2 = it; it2 != v.end(); ++it2)
	cout << *it2;
    cout << endl;
    
    return 0;
}

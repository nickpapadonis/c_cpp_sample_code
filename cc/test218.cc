#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    vector<int> v {1, 2, 3, 4};
    vector<int> v2;
    remove_copy_if(v.begin(), v.end(), back_inserter(v2),
		   [](const int& x){return x>2;});
    for (auto& r : v2)
	cout << r;
    cout << endl;
    
    return 0;
}

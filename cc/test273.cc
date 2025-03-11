#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> m = {{1, 2, 3},
			     {4, 5, 6},
			     {7, 8, 9}};

    vector<vector<int>> mt;
    
    for (int i = 0; i < m[0].size(); ++i) {
	vector<int> v;
	for (int j = 0; j < m.size(); ++j) {
	    v.push_back(m[j][i]);
	}
	mt.push_back(v);
    }

    for (auto& r : mt) {
	for (auto& c : r) {
	    cout << c << ",";
	}
	cout << "\n";
    }
    
    return 0;
}

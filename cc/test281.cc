#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>>
mm(const vector<vector<int>>& m0,
   const vector<vector<int>>& m1)
{
    int m = m0.size();
    int n0 = m0[0].size();
    int n1 = m1.size();
    int p = m1[0].size();

    if (n0 != n1) {
	cout << "error in size" << '\n';
	return {{}};
    }

    vector<vector<int>>
	mr(m, vector<int>(n0));

    for (int i = 0; i < m; ++i) {
	for (int j = 0; j < p; ++j){
	    mr[i][j] = 0;
	    for (int k = 0; k < n0; ++k) {
		mr[i][j] += m0[i][k] * m1[k][j];
	    }
	}
    }

    return mr;
}

int main()
{
    // 2x3 m0.size() x m0[0].size()
    vector<vector<int>> m0 =
	{{1, 2, 3},
	 {4, 5, 6}};
    // 3x2 m1.size() x m1[1].size()
    vector<vector<int>> m1 =
	{{7, 8},
	 {9, 10},
	 {11, 12}};

    vector<vector<int>> mr = mm(m0, m1);

    for (auto& r : mr) {
	for (auto& c : r) {
	    cout << c << ",";
	}
	cout << '\n';
    }
    
    return 0;
}

#include<vector>
#include<iostream>
#include<sstream>
#include<cmath>
#include<limits>
using namespace std;

void merge_sort(vector<int>& A, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    vector<int> L(n1 + 1);
    vector<int> R(n2 + 1);
    for (int i = 0; i < n1; ++i)
	L[i] = A[p + i];
    for (int i = 0; i < n2; ++i)
	R[i] = A[q + i + 1];
    L[n1] = numeric_limits<int>::max();
    R[n2] = numeric_limits<int>::max();
    int i = 0, j = 0;
    for (int k = p; k <= r; ++k) {
	if (L[i] <= R[j]) {
	    A[k] = L[i];
	    i += 1;
	} else {
	    A[k] = R[j];
	    j += 1;
	}
    }
}

void merge(vector<int>& A, int p, int r)
{
    if (p < r) {
	int q = floor((p + r) / 2);
	merge(A, p, q);
	merge(A, q+1, r);
	merge_sort(A, p, q, r);
    }
}

int main(int argc, char *argv[])
{
    vector<int> il;
    for (int i=1; i<argc; i++) {
	istringstream v{argv[i]};
	int ii;
	v >> ii;
	il.push_back(ii);
    }

    merge(il, 0, il.size() - 1);
    
    for (auto& r : il)
	cout << r << ",";
    cout << '\n';
    
    return 0;
}

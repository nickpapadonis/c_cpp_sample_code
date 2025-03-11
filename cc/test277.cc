#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void insertion(vector<int>& A)
{
    for (int j = 1; j < A.size(); ++j) {
	int key = A[j];
	int i = j - 1;
	while (i > -1 && A[i] > key) {
	    A[i + 1] = A[i];
	    i = i - 1;
	}
	A[i + 1] = key;
    }
}

int main(int argc, char* argv[])
{
    vector<int> A;
    for (int i = 1; i < argc; ++i) {
	istringstream iss{argv[i]};
	int ii;
	iss >> ii;
	A.push_back(ii);
    }
    
    insertion(A);
    for (auto& r : A)
	cout << r << ",";
    cout << '\n';
    
    return 0;
}

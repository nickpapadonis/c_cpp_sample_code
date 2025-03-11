#include<iostream>
#include<sstream>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
	return 1;

    istringstream ss {argv[1]};
    int ub;
    ss >> ub;

    // prime is a number > 1, and not a product
    // of two smaller numbers
    for (int n = 2; n <= ub; ++n) {
	bool fprime = true;
	for (int x = 2; x < n; ++x) {
	    if (n % x == 0) {
		fprime = false;
		break;
	    }
	}
	if (fprime)
	    cout << n << ",";
    }

    return 0;
}

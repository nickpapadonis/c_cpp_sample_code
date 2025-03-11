#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    vector<int> v;
    if (argc <= 1)
	return 1;
    for (int i = 1; i < argc; i++)
	v.push_back(atoi(argv[i]));

    vector<int> v2 {0, 1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6};

    for (vector<int>::iterator i = v2.begin();
	 (i = search(i, v2.end(), v.begin(), v.end())) != v2.end();
	 ++i) {
	for (vector<int>::iterator j = i;
	     j < i + (v.end() - v.begin());
	     ++j)
	    cout << *j;
	cout << endl;
    }
    
    return 0;
}

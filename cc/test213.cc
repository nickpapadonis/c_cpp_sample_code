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

    for (vector<int>::iterator i = v.begin();
	 (i = find(i, v.end(), int{7})) != v.end();
	 ++i)
	cout << *i;
    cout << endl;

    for (vector<int>::iterator i = v.begin();
	 (i = find_if(i, v.end(),
		      [](vector<int>::value_type const &v){return v == 7;})) != v.end();
	 ++i)
	cout << *i;
    cout << endl;

    return 0;
}

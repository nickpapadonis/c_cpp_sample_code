#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct X {
    string name;
    int id;
};

int main(int argc, char *argv[])
{
    vector<X> v = {{"wasted", 3},
		   {"alpha", 9}};

    sort(v.begin(), v.end(),
	 [](const X& a, const X& b)
	     { return a.name < b.name; });


    for (auto& p : v)
	cout << p.name << endl;
    
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct X {
    int i;
    bool operator==(const X& b) {return i == b.i;}
};

ostream& operator<<(ostream& os, const X& x)
{
    return os << x.i;
}

int main()
{
    vector<X> v {{0}, {2}, {4}};
    vector<X>::iterator i;

    // Uses operator==
    const X x{2};
    if ((i = find(v.begin(), v.end(), x)) != v.end())
        cout << *i << endl;

    if ((i = find_if(v.begin(), v.end(),
		     +[](const X& x){return x.i == 2;}))
        != v.end())
        cout << *i << endl;

    // #3, Example with pointers, we must use find_if()
    //     because find() relies on == , which would
    //     not work as intended for pointers.
    vector<X*>::iterator i2;
    vector<X*> v2 {new X{2}, new X{4}};
    if ((i2 = find_if(v2.begin(), v2.end(),
		      +[](const X* x){return x->i == 2;}))
        != v2.end())
        cout << **i2 << endl;
    

    return 0;
}

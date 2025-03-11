// clang++ -g -fno-elide-constructors -std=c++11 -Wall -pedantic test195.cc && ./a.out
// direct and copy initialization info
#include <iostream>
using namespace std;

// explicit disables copy initialization, where
// implicit conversions can take place

// copy assignment depends on
//  - move constructor - move assignment
struct X {
    int i;
    X(int ii) : i{ii} {}
    X(const X& x) : i{x.i} {} 
    X(X&& x) : i{x.i} {x.i = 0;}
    X& operator=(const X& x)
	{X tmp{x}; swap(*this, tmp); return *this;}
    X& operator=(X&& x) {swap(i, x.i); return *this;}
};

int main(void)
{
    X x{1};  // direct init, constructor
    X x2 = 1; // copy init, constructor then move constructor
    
    X xx{x}; // direct init copy constructor
    X xxx{X{1}}; // direct init move constructor

    // allows implicit conversions
    X x4 = x; // copy initialization, copy constructor
    X x5 = X{1}; // copy initiailization, move constructor

    x4 = x; // copy assignement
    x5 = X{1}; // move assignment
    x2 = 3; // move assignment
}

#include<iostream>
#include<string>
using namespace std;
// g++ -pedantic -Wall -std=c++11 -fno-elide-constructors test149.cc && ./a.out

void P(const string& s)
{
    cout << s << endl;
}

class X {
    int i;
public:
    X() : i{} { P("oc"); }
    X(int xx) : i(xx) { P("oci"); }
    
    X(const X& a) : i{a.i} { P("cc"); }
    X& operator=(const X& a) {
	P("ca");
	if (this == &a) { return *this; }
	X tmp{a};
	swap(tmp, *this);
	return *this;
    }
    
    X(X&& a) : i{move(a.i)} { P("mc"); a.i = 0; }
    X& operator=(X&& a) {
	P("ma");
	swap(i, a.i);
	return *this;
    }
};

X f(X& xx) 
{
    return xx; // copy constructor f_{xx}
}

X f2(X xx) // copy constructor xx{arg}
{
    return xx; // move constructor f2_{move(xx)}
}

X& f3(X& xx)
{
    return xx;
}

X f4(const X& xx) 
{
    return xx; // copy constructor f_{xx}
}

X f5(const X xx) // move const
{
    return xx; // copy constructor
}

int main(int argc, char *argv[])
{
    X xx, xx2; // ordinary constructors
    X xx11 = 1; // implicit integer constructor

    cout << "(0)" << endl;
    X xx9 {xx2}; // copy constructor
    cout << "(1)" << endl;
    X xx10 = xx9; // copy constructor
    cout << "(2)" << endl;
    X xx3 = X(6); // ord. cons, move constructor
    cout << "(3)" << endl;
    xx2 = f(xx); // move assignment
    cout << "(4)" << endl;
    xx2 = f2(xx); // move assignment
    cout << "(5)" << endl;
    xx2 = f3(xx); // copy assignment, invokes swap
    cout << "(5b)" << endl;
    X& xx7 = f3(xx); // nothing
    cout << "(6)" << endl;
    xx = f3(xx); // copy assignment, but is self-assign do nothing
    cout << "(7)" << endl;
    xx = f4(99); // ordi cons input, move assignment
    cout << "(8)" << endl;
    xx = f5(99); // ordi cons input, move assignment
    cout << "(9)" << endl;
    xx2 = 99; // ordi cons input, move assignment
    return 0;
}

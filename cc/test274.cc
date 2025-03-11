#include<iostream>
using namespace std;

class X {
public:
    virtual void f0() {cout << "X:f0()" << '\n'; f1(); }
    virtual void f1() {cout << "X:f1()" << '\n'; }
};

class Y : public X {
public:
    virtual void f0() {X::f0(); cout << "Y:f0()" << '\n'; f1(); }
    virtual void f1() {X::f1(); cout << "Y:f1()" << '\n'; }
};

int main()
{
    Y y;
    X* xp = &y;
    xp->f0();
    
    return 0;
}

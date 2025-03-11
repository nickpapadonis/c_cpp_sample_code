#include<iostream>
using namespace std;

struct A {
    void fz() {cout << "A:fz()" << '\n';}
};

struct X0 : public virtual A {
    void f0() {cout << "X0:f0()" << '\n';}
};

struct X1 : public virtual A {
    void f1() {cout << "X1:f1()" << '\n';}
};

struct Y : public X0, public X1 {
};
    
int main()
{
    Y y;
    y.fz();
    return 0;
}

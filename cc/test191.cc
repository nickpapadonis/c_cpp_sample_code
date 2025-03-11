#include <iostream>
using namespace std;
struct nullpt_t {
    template<class T>
    inline operator T*() const { return 0; }

    template<class C, class T>
    inline operator T C::*() const { return 0; }
};
nullpt_t nullpt;

struct C {
    void f() {cout << "here" << endl;}
};

int main(void)
{
    int *ptr = nullpt;       
    void (C::*m)() = nullpt;
    m = &C::f;
    C c;
    (c.*m)();
    // now assign m to member function f()?
}

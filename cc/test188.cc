#include <iostream>
using namespace std;

void f(int) {}

template<class T, class TT> char ff(T t, TT d)
{
    f(d); 
    return g(t,d);
}

namespace N {
    class X { };
    char g(X,int) {cout << "g0" << endl; return 0;}
}

namespace N {
    char g(X,double) {cout << "g1" << endl; return 0;}
}

auto x1 = ff(N::X{},double{1}); // POI is at end of TU for ADL
// but for compatability this is POI

auto x2 = ff(N::X{},double{2});

int main(int argc, char *argv[])
{
    return 0;
}

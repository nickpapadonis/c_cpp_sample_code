// g++ -pedantic -Wall -std=c++11 -fno-elide-constructors -g test145.cc && ./a.out
#include <iostream>
using namespace std;

struct X {
    int x;
    X() : x{0} { cout << "def cons" << endl; }
    X(const X& xx) : x{xx.x} { cout << "copy cons" << endl; }
    X(X&& xx) : x{xx.x} { xx.x = 0; cout << "move cons" << endl; }
    X& operator=(const X& xx) { cout << "assign op" << endl; return *this; }
    X& operator=(X&& xx) { xx.x = 0; cout << "move assign" << endl; return *this; }
};

int main(int argc, char *argv[])
{
    X x = X();
    return 0;
}

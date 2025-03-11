#include <iostream>
using namespace std;

namespace N {
    class A {
	/* ... */
    };
    char f(A) {cout << "f(A)" << endl; return 0;}
}

char f(int) {cout << "f(int)" << endl; return 0;}
char f(double) {cout << "f(double)" << endl; return 0;}

template<typename T> char g(T t)
{
    return f(t);
}

class Q {};

char c1 = g(N::A{});
char c8 = g(Q{});
char c2 = g(2);
char c3 = g(2.1);

char f(Q) {cout << "f(Q)" << endl; return 0;} // ADL ::Q

int main(int argc, char *argv[])
{
    return 0;
}

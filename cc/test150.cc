#include<iostream>
#include<vector>
using namespace std;

struct X {
    int x;
    X() : x(0) {}
    X(int xx) : x(xx) {}
    friend ostream& operator<<(ostream& os, const X& a) {
	return os << a.x;
    }
};

int main(int argc, char *argv[])
{
    X x;
    cout << x << endl; // addr of X x() will never be NULL
    X x2{};
    cout << x2 << endl; // ok, prints 0 correctly
    X x3(9);
    cout << x3 << endl; // ok, prints 9 correctly
}

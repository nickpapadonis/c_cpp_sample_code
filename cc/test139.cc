#include <iostream>
using namespace std;

class X {
public:
    void f(void);
    class X_error0 {
	int n;
    public:
	X_error0(int nn) {n = nn;}
    };
};

void X::f(void)
{
    throw X::X_error0{1};
}

int main(int argc, char *argv[])
{
    X xx;
    try {
	xx.f();
    } catch (X::X_error0) {
	cout << "caught" << endl;
    }
    return 0;
}

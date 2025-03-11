#include <iostream>
using namespace std;

class Q {};

template <class T>
T operator+(T&, T&);

template <>
Q operator+(Q& a, Q& b) {Q tmp{a}; cout << "a" << endl; return a;}
// prec: operator overload > template function
Q operator+(Q& a, Q& b) {Q tmp{a}; cout << "b" << endl; return a;}

#if 0
template <>
int operator+(double& a, double& b) {double tmp{a}; return a;}
int operator+(double& a, double& b) {double tmp{a}; return a;}
#endif

    

int main(int argc, char *argv[])
{
    Q a, b;
    Q c = a + b;
    
    return 0;
}

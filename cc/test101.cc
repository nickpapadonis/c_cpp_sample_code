#include <iostream>
#include <complex>
using namespace std;

int main(int argc, char *argv[])
{
    complex<double> i = { 0, 3.14 };
    complex<double> j{0, 3.14};
    complex<double> m(0, 3.14); 

    // default initializer
    complex<double> f1;
    complex<double> f2{};
    complex<double> f3 = {};

    int z0;
    decltype(j) z1 = 1;
    
    return 0;
}

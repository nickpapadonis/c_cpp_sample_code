#include <iostream>
using namespace std;

unsigned int fibr(unsigned int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibr(n - 1) + fibr(n - 2);
}

constexpr unsigned int ftbl[] { 0, 1, 1, 2, 3, 5, 8, 13 };
constexpr unsigned int fib(size_t n)
{
    return (n < sizeof(ftbl)/sizeof(*ftbl)) ? ftbl[n] : fib(n-2) + fib(n-1);
}


int main(int argc, char *argv[])
{
    if (argc == 2) {
        if (string(argv[1]) == "r") {
            unsigned long x = fibr(44);
	    cout << x << endl;
        }
    } else {        
        constexpr unsigned long x = fib(44);
	cout << x << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;
// g++ -pedantic -Wall -std=c++11 -fno-elide-constructors test152.cc && ./a.out

struct X {
    int x;
    X(int xx) : x{xx} {}
};

struct Y {
    int x;
    explicit Y(int xx) : x{xx} {}
};

void f0(const X& xx)
{
}

void f1(const Y& xx)
{
}

int main(int argc, char *argv[])
{
    f0(0);

    // f1(0); error
    // Y y = 0; error
    f1(Y(0));
    Y y = Y(0);

    vector<int> v = vector<int>(10);
    for (auto& r : v)
	cout << r;
    cout << endl;
    
    return 0;
}

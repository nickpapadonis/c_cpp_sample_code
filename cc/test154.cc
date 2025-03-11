#include <iostream>
using namespace std;

struct Y {
    Y() { cout << "Y()" << endl; }
};

struct X : Y {
    X() { cout << "X()" << endl; }
};


int main(int argc, char *argv[])
{
    X x;
    return 0;
}

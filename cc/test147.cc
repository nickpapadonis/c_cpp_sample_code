#include <iostream>
#include <string>
#include <cstdlib>
#include "test147.h"
using namespace std;

struct X {
    X(string ss) : s{ss} {}
    ~X() { cout << "~X() " << s << endl; }
    string s;
};

X xx{"static"};

int main(int argc, char *argv[])
{
    X x{"local"};
    ff();
    return 0;
}

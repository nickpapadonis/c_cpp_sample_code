#include <iostream>
#include <string>
using namespace std;

class X {
public:
    union {
        int i;
        string s;
    };
    X(string ss) { new(&s) string{ss}; };
    ~X() { s.~string(); };
};

int main(int argc, char *argv[])
{
    X xx{"abc"};

    return 0;
}

#include <iostream>
#include <functional>
using namespace std;

using CFT = int(int a);
void fq(CFT f0)
{
    cout << f0(1) << endl;
}

void fq2(int (*f0)(int a))
{
    cout << f0(1) << endl;
}

void f(function<int(int a)> f0)
{
    cout << f0(1) << endl;
}

class F {
public:
    int operator()(int a) { return a; }
};

int main(int argc, char *argv[])
{
    f([](int a) {return a;});
    f(F());
    fq([](int a) {return a;});
    fq2([](int a) {return a;});
    
    return 0;
}

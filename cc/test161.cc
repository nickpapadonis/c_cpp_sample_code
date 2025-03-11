#include <iostream>
#include <map>
using namespace std;
// Pointers to Function Members
// BB RPC ?

class X {
public:
    int f0(int x) {return x;}
    int f1(int x) {return ++x;}
};

void call(void)
{
    X xx;
    map<string,X*> var = {{"x0", &xx}};
    map<string,int (X::*)(int)> op =
	{{"f0", &X::f0}, {"f1", &X::f1}};

    string var_ = "x0", op_ = "f1";
    int val_ = 9;
    cout << (var[var_]->*op[op_])(val_) << endl;
    op_ = "f0";
    cout << (var[var_]->*op[op_])(val_) << endl;
}

void statick(void)
{
    X xx;
    
    int (X::*s)(int) = &X::f0;
    cout << (xx.*s)(1) << endl;

    X *xx2 = new X;
    cout << (xx2->*s)(2) << endl;
}

int main(int argc, char *argv[])
{
    call();

    statick();

    return 0;
}

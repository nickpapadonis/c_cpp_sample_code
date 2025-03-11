#include <iostream>
#include <vector>
#include <functional>
using namespace std;

static vector<function<void(int)>> cbl;
static vector<function<int(int)>> cblr;

class GT {
public:
    int operator()(int x) {return x;}
};

void f()
{
    auto op = [](int x) {cout << x << endl;}; 
    cbl.push_back(op);

    for (auto& p : cbl)
        p(1);

    auto op2 = [](int x) {return x;};
    cblr.push_back(op2);
    cblr.push_back(GT());
    for (auto& p : cblr)
        cout << p(99) << endl;
}

void g()
{
    double (*p1)(double) = [](double a) { return a; };
    cout << p1(2.0) << endl;
}

int main(int argc, char *argv[])
{
    f();
    g();
    
    return 0;
}

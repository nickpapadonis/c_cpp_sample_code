#include <iostream>
using namespace std;

class A {
    int i;
public:
    A(int ii) : i{ii} {i=1;}
    virtual void w0(void) = 0;
    virtual ~A() {}
};

class B0 : virtual public A {
public:
    virtual void f0(void) = 0;
    void w0(void) {cout << "B0::w0()" << endl;}
};

class B1 : virtual public A {
public:
    virtual void f1(void) = 0;
    void w0(void) {cout << "B1::w0()" << endl;}
};

class S : public B0, public B1 {
public:
    S() : A(0) {}
    void f0(void) {cout << "f0()" << endl;}
    void f1(void) {cout << "f1()" << endl;}
    void w0(void) {cout << "S::w0()" << endl;}
};

void use_b0(B0* bb)
{
    bb->f0();
}
void use_b1(B1* bb)
{
    bb->f1();
}

int main(int argc, char *argv[])
{
    S ss{};
    B0* b0 = &ss;
    b0->w0();

    use_b0(&ss); use_b1(&ss);
    return 0;
}

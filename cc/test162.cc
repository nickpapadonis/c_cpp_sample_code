#include <memory>
#include <iostream>
using namespace std;
// P623 Localizing Object Creation
// Implementation Inheritence

class A {
public:
    virtual void a0(void) = 0;
    virtual ~A() {};
    int i;
};

class B : public A {
public:
    virtual void b0(void) = 0;
    virtual ~B() {};
};

//////

class Sys0 {
public:
    void c0(void) {cout << "Sys0::c0()" << endl;}
};

class B_impla0 : public B, protected Sys0 {
public:
    void a0(void) {d0();}
    void b0(void) {d0();}
private:
    void d0(void) {c0();}
};

class Sys1 {
public:
    void c0(void) {cout << "Sys1::c0()" << endl;}
};

class B_impla1 : public B, protected Sys1 {
public:
    void a0(void) {d0();}
    void b0(void) {d0();}
private:
    void d0(void) {c0();}
};

class Factory {
public:
    virtual B* b() = 0;
};

class FactorySys0 : public Factory {
public:
    B* b() {return new B_impla0;}
};

class FactorySys1 : public Factory {
public:
    B* b() {return new B_impla1;}
};

void user(Factory& f)
{
    unique_ptr<A> pa {f.b()};
    pa->a0();
    unique_ptr<B> pb {f.b()};
    pb->a0(); pb->b0();
}

FactorySys0 factorySys0;
FactorySys1 factorySys1;

void driver(void)
{
    user(factorySys0);
    user(factorySys1);
}

int main(int argc, char *argv[])
{
    driver();
    return 0;
}

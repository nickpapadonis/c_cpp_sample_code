#include <iostream>
using namespace std;
// Dynamic Casting p659

class C1 {
public:
    virtual ~C1() = default;
};
class B0 : public C1 {
};
class C0 {
public:
    virtual ~C0() = default;
};
class B1 : public C0 {
};
class A : public B0, protected B1 {
};
class A1 : public B0, public B1 {
};

class Z {
};
class A2 : public B0, public Z
{
};

int main(int argc, char *argv[])
{
    A aa{};
    // downcast, needs polymorphic type with virtual fn
    if (auto p = dynamic_cast<A*>((C1*)&aa))
        cout << "<A*>&C1" << endl;
    // downcast, B0 is implcity polomorphic
    if (auto p = dynamic_cast<A*>((B0*)&aa))
        cout << "<A*>&B0" << endl;
    // upcast
    if (auto p = dynamic_cast<C1*>(&aa))
        cout << "<C1*>&A" << endl;
    // cross cast, not allowed becauses B1 is protected base
    if (auto p = dynamic_cast<B0*>((B1*)&aa))
        cout << "<B0*>&B1" << endl;
    else
	cout << "<B0*>&B1 = null" << endl;
    if (auto p = dynamic_cast<C1*>((C0*)&aa))
        cout << "<C1*>&C0" << endl;
    else
	cout << "<C1*>&C0 = null " << endl;

    A1 aa1{};
    // cross cast, allowed B1 is public
    if (auto p = dynamic_cast<B0*>((B1*)&aa1))
        cout << "<B0*>&B1" << endl;
    else
	cout << "<B0*>&B1 = null" << endl;
    if (auto p = dynamic_cast<C1*>((C0*)&aa1))
        cout << "<C1*>&C0" << endl;
    else
	cout << "<C1*>&C0 = null " << endl;

    // downcast, the target class need not be polymorphic
    A2 a2{};
    if (auto p = dynamic_cast<Z*>((B0*)&a2))
        cout << "<Z*>&B0" << endl;

    return 0;
}

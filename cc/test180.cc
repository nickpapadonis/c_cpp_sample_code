#include <vector>
using namespace std;

template <class T>
struct X {
    template <class Z>
    void f0(Z); // does not work for virtual
    virtual void f1a(int);
    virtual void f1b(double);
};

template <class T>
template <class Z>
void X<T>::f0(Z a) {}

template <class T>
void X<T>::f1a(int a) {}
template <class T>
void X<T>::f1b(double) {}


int main(int argc, char *argv[])
{
    X<int> x0;
    return 0;
}

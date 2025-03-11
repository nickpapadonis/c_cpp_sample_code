#include <iostream>
using namespace std;

template<typename T>
class B {
protected:
    T *e;
};
template<typename T>
class A : public B<T> {
public:
#if 1
    using B<T>::e;
    T* f0(void) { return e; }
#else
    T* f0(void) { return this->e; }
#endif
};


int main(int argc, char *argv[])
{
    A<int> a; a.f0();
}

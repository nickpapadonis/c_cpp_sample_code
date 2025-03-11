#include <iostream>
using namespace std;

// Primary Template
// Template arguments must be type and order of
// the parameter list.  Template parameter values are
// arguments passed to the class template at instantiation.
//
// The more specilized versions are chosen.
#if 1
template<class T1, class T2, int I>
class A {
public:
    void f0();
};
#else
// only use specialized
template<class T1, class T2, int I>
class A;
#endif

#if 0 // error: does not specialize any parameters, define primary
template<class T1, class T2, int I>
class A<T1, T2, I> {
public:
    void f0();
};
#endif

// Template parameter values are the arguments
// passed to the primary template.
template<class T1, class T2, int I>
void A<T1, T2, I>::f0()
{
    cout << "x" << endl;
}

// Partial specialization. Deduces parameter value from template arguments.
template<int I>
class A<int, int, I> {
public:
    void f0();
};
template<int I>
void A<int, int, I>::f0()
{
    cout << "A<int, int, I>" << endl;
}

template<class T, class T2>
class A<T, T2, 2> { };

#if 1
template<>
class A<int, int, 4> {
public:
    void f0();
};

// Explicit full specialization
void A<int, int, 4>::f0()
{
    cout << "z" << endl;
}
#else
template<>
void A<int, int, 4>::f0()
{
    cout << "z" << endl;
}
#endif

// parameter values deduced from template arguments
template<class T, int I>
class A<T, T*, I> {
public:
    A();
};

// parameter values passed as template arguments, based
// on parameter values from class definition.
template<class T, int I>
A<T, T*, I>::A() {cout << "A()" << endl;}

template<class T>
class A<int, T*, 5> {};

template<class T, class T2, int I>
class A<T*, T2, I> { public: A(); };
  
template<class X, class T, int I>
class A<X, T*, I> { public: A(); };

template<class T, class T2, int I>
A<T*, T2, I>::A() { cout << "n" << endl; }

template<class X, class T, int I>
A<X, T*, I>::A() { cout << "m" << endl; }

int main(int argc, char *argv[])
{
    A<double, int*, 1> a;
    A<double*, int, 1> a2;

    template class A<int, int, 0>;
    
    return 0;
}

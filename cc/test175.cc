#include <iostream>
using namespace std;

template <class T>
struct Z {};

//template <class... Ts> struct Y {};
template <class T>
struct Y : public Z<T> {
    void f0(void);
};

template <>
struct Y<int> : public Z<int> {
    void f0(void);
};

template <class T>
void Y<T>::f0(void)
{
    cout << "Y<T>::f0()" << endl;
}

//template <>
void Y<int>::f0(void)
{
    cout << "Y<int>::f0()" << endl;
}

int main(int argc, char *argv[])
{
    Y<int> y0;
    y0.f0();
    return 0;
}

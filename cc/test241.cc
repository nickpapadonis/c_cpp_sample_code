#include <utility>
#include <iostream>
using namespace std;

template<typename T>
T& forwardz(typename remove_reference<T>::type& t) noexcept {
    return static_cast<T&>(t);
}
template<typename T>
T&& forwardz(typename remove_reference<T>::type&& t) noexcept {
    static_assert(!is_lvalue_reference<T>::value,"forward of lvalue");
    return static_cast<T&&>(t);
}

void f1(int &x){cout << "f1:&" << endl;}
void f1(int &&x){cout << "f1:&&" << endl;}
void f0(int &x){cout << "f0:&" << endl;f1(forward<int&>(x));}
void f0(int &&x){cout << "f0:&&" << endl;f1(forward<int&&>(x));}

int main()
{
    int x = 1;
    f0(forwardz<int>(x));
    f0(forwardz<int>(1));

    return 0;
}

#include <iostream>
using namespace std;

// primary class template
template <class... Ts>
struct tpl {tpl();};

template <class... Ts>
tpl<Ts...>::tpl() {cout << "tpl<Ts...>()" << endl;}

// full explcit specialization of class template for empty args
#define CLASSTP
#ifdef CLASSTP
template <>
struct tpl<> {tpl();};
#endif
// full explicit specilization template parameter required
//  when class template is not specialized
#ifndef CLASSTP
template <>
#endif
tpl<>::tpl() {cout << "tpl<>2()" << endl;}

// 'class T' has higher precedence than 'class... Ts'
template <class T>
struct tpl<T> {tpl();};
template <class T>
tpl<T>::tpl() {cout << "tpl<T>()" << endl;}

template <class T, class... T2>
struct tpl<T,T2...> {tpl();};
template <class T, class... T2>
tpl<T,T2...>::tpl() {cout << "tpl<T,T2...>()" << endl;}

int main(int argc, char *argv[])
{
    tpl<> t;
    tpl<int> t2;
    tpl<int,int> t3;
    tpl<int,int,int> t4;
    return 0;
}

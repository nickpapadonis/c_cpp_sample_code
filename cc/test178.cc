#include <iostream>
#include <string.h>
using namespace std;

template <class T> struct X;
//template <class T> struct X { X(); };
//template <class T> X<T>::X() { };

template <class T> struct X<T*> { };
template <> struct X<int> { };
//template <> struct X<int>;

#if 0
template<typename T> bool lesss(T a, T b);
#else
template<typename T> bool lesss(T a, T b)
{
    return a<b;
}
#endif


#if 1
template<>
bool lesss<const char*>(const char* a, const char* b)
{
    return strcmp(a, b) == -1 ? true : false;
}
#else
template<>
bool lesss(const char* a, const char* b)
{
    return strcmp(a, b) == -1 ? true : false;
}
#endif

#if 0
template<>
bool lesss<int, int>(int a, int b)
{
    return a < b;
}
#else
template<>
bool lesss(int a, int b)
{
    return a < b;
}
#endif

int main(int argc, char *argv[])
{
    X<int> xi;
#if 0
    cout << lesss<const char*>("a", "b") << endl;
    cout << lesss<int, int>(1, 0) << endl;
#else
    cout << lesss("a", "b") << endl;
    cout << lesss(0, 1) << endl;
#endif
    return 0;
}

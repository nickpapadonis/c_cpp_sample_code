#include <type_traits>
#include <iostream>

#if 1 // works
template <class T,
	  typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
void do_stuff(T& t) {
    std::cout << "do_stuff integral\n";
}
#endif

#if 0 // works
template <class T,
	  typename std::enable_if<std::is_integral<T>::value, T>::type* = static_cast<T*>(0)>
void do_stuff(T& t) {
    std::cout << "do_stuff integral\n";
}
#endif


struct S {};
int main(int argc, char *argv[])
{
    int i = 1;
    do_stuff(i);
    return 0;
}

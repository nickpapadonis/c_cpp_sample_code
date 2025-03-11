#include <type_traits>
#include <iostream>

#if 1
template <class T,
	  typename std::enable_if<std::is_integral<T>::value, int>::type* = nullptr>
void do_stuff(T& t) {
    std::cout << "do_stuff integral\n";
}
#endif

#if 0 // understood
template <class T>
typename std::enable_if<std::is_integral<T>::value,
                                 void>::type
do_stuff(T& t) {
    std::cout << "do_stuff integral\n";
}
#endif

struct S {};
int main(int argc, char *argv[])
{
    int i = 1;
    do_stuff<int, nullptr>(i);
    //do_stuff<S>(S{});
    return 0;
}

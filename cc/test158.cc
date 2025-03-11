#include <iostream>
using namespace std;
// variadic template

template<typename T>
T adder(T v) {
    return v;
}

template<typename T, typename... Types>
T adder(T first, Types... args) {
    return first + adder(args...);
}

int main(int argc, char *argv[])
{
    cout << adder(1, 2, 3) << endl;
    return 0;
}

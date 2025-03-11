#include <iostream>
using namespace std;

template<typename T>
T adder(T v) {
  return v;
}

template<typename T, typename... Args>
T adder(T first, Args... args) {
  return first + adder(args...);
}

int main(int argc, char *argv[])
{
    cout << adder(1, 2, 3, 8, 7) << endl;
    cout << adder<int, int, int>(1, 1, 1) << endl;
    cout << adder<string, string>("a", "b") << endl;
    return 0;
}

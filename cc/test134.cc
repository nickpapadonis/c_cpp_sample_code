#include <iostream>
// g++ -pedantic -Wall -std=c++17 test134.cc && ./a.out

template<typename T>
class F{
    T t;
public:
    F(const T &lambda):t(lambda){}
    void call() {t();}
};

int main() {
    F f([]() {std::cout << "It works!!!\n"; });
    f.call();
}

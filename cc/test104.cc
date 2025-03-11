#include <iostream>
using namespace std;

template<class T, class U>
auto f1(const T& a, const U& b) -> decltype(T{} + U{})
{
    decltype(T{} + U{}) res;
    res = a + b;
    return res;
}

int main(int argc, char *argv[])
{
    auto res = f1<int,double>(1, 1.1);
    cout << res << endl;
    
    return 0;
}

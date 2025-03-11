#include <vector>
#include <iostream>
using namespace std;

template<typename T>
using Value_type = typename T::value_type;

template <class T>
void f(T& v)
{
    vector<int>::value_type xx;
    typename T::value_type x = v[0];
    Value_type<T> xxx;
    cout << x << endl;
}

int main(int argc, char *argv[])
{
    vector<int> v = {0};
    f(v);
    return 0;
}

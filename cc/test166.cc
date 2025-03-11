#include <iostream>
#include <algorithm>
using namespace std;

template<typename Iter, typename Val>
Val accumulate2(Iter first, Iter last, Val s, Val (*op)(Val, Val))
{
    while (first!=last) {
        s = op(s,*first);
        ++first;
    }
    return s;
}

template<typename Iter, typename Val, typename Oper>
Val accumulate(Iter first, Iter last, Val s, Oper op)
{
    while (first!=last) {
        s = op(s,*first);
        ++first;
    }
    return s;
}

int add(int a, int b)
{
    return a + b;
}

int main(int argc, char *argv[])
{
    int a[] = {1, 2};
    int v0 = accumulate(a, a+2, 0, [](int _v0, int _v1){return _v0 + _v1;});
    cout << v0 << endl;
    int v1 = accumulate2(a, a+2, 0, &add);
    cout << v1 << endl;
    int v2 = accumulate2(a, a+2, 0, +[](int _v0, int _v1){return _v0 + _v1;});
    cout << v2 << endl;
}

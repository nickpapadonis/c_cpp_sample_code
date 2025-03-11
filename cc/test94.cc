#include <valarray>
#include <iostream>
using namespace std;

template <typename T>
valarray<T> f(valarray<T>& a, valarray<T>& b)
{
    return a + b;
}

int main(int argc, char *argv[])
{
    valarray<int> va0 = {1, 1, 1};
    valarray<int> va1 = {1, 1, 1};

    valarray<int> va2 = f(va0, va1);
    valarray<int> va3 = va2 * va2;

    valarray<int> va4 = va0 * 3;
    
    for (auto p : va2)
	cout << p << ", ";
    cout << endl;
    for (auto p : va3)
	cout << p << ", ";
    cout << endl;
    for (auto p : va4)
	cout << p << ", ";
    cout << endl;
    
    return 0;
}

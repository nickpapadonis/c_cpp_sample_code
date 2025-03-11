#include <iostream>
using namespace std;

template<typename T>
class Matrix;
template<typename T>
class Vector;
template<typename T>
Vector<T> operator*(const Matrix<T>& m, const Vector<T>& v);

template<typename T>
class Vector
{
    T v[4];
public:
    friend Vector<T> operator*<>(const Matrix<T>&, const Vector&);
};

template<typename T>
class Matrix {
    Vector<T> v[4];
public:
    friend Vector<T> operator*<>(const Matrix&, const Vector<T>&);
};

template<typename T>
Vector<T> operator*(const Matrix<T>& m, const Vector<T>& v)
{
    Vector<T> vv;
    return vv;
}

int main(int argc, char *argv[])
{
    Matrix<int> m; Vector<int> v;
    Vector<int> x = m * v;
}

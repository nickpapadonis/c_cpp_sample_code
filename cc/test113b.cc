#include <iostream>
#include <vector>
#include <utility>
#include <type_traits>
using namespace std;

class X {
public:
    X() : v{new vector<int>(0)} { }
    X(const X&); // 3 lval copy-constructor
    X(X&&); // 5 rval/move copy-constructor
    X& operator=(const X& rhs); // 3 lval assign. op.
    X& operator=(X&& rhs); // 5 rval/move assign. op.
    ~X() {delete v;} // 3 destructor
    X(initializer_list<int> li) : v{ new vector<int>(li) } { }
    friend ostream& operator<<(ostream&, const X&);
private:
   vector<int> *v;
};

X::X(const X& a)
{
    cout << "copy constructor" << endl;
    for (auto p : *(a.v))
        v->push_back(p);
}

X::X(X&& a) : v{a.v}
{
    cout << "rval ref constructor" << endl;
    a.v = nullptr;
}

X& X::operator=(const X& rhs)
{
    cout << "assignment operator" << endl;
    delete v;
    v = new vector<int>();
    for (auto p : *(rhs.v))
        v->push_back(p);
    return *this;
}

X& X::operator=(X&& rhs)
{
    cout << "rval ref assignment op" << endl;
    swap(v, rhs.v);
    return *this;
}

ostream& operator<<(ostream& os, const X& x)
{
    for (auto& p : *(x.v))
	os << p << ",";
    os << endl;
    return os;
}

template<class T>
void swap_0(T& a, T& b)
{
    T tmp {static_cast<T&&>(a)}; 
    a = static_cast<T&&>(b); 
    b = static_cast<T&&>(tmp); 
}

template<class T, class U>
void swap_(T&& a, U&& b)
{
    typename std::remove_reference<T>::type tmp {std::move(a)};
    a = std::move(b);
    b = std::move(tmp); 
}

// overload the function call
template<class T>
void swap_1(T&& a, T& b)
{
    swap_(std::forward<T>(a), b);
}

template<class T>
void swap_1(T& a, T&& b)
{
    swap_(a, std::forward<T>(b));
}

template<class T>
void swap_1(T& a, T& b)
{
    swap_(a, b);
}

template<class T, class U, class = std::enable_if_t<std::is_same<std::remove_reference_t<T>, std::remove_reference_t<U>>::value>>
void swap_2(T&& a, U&& b)
{
    std::remove_reference_t<T> tmp {std::move(a)};
    a = std::move(b);
    b = std::move(tmp); 
}

X f0()
{
    return X(); // copy-elision no move called
}

void f2()
{
    cout << endl << "f2()" << endl;
    X x1 = {0, 1, 2};
    X x2 = {3, 4, 5};
    swap_1(x1, x2);
    cout << x1;

    X x3{move(X{4, 5, 6})};
    cout << x3;
}

int main(int argc, char *argv[])
{
    cout << "copy-elision no move called" << endl;
    X x1(f0());
    cout << "move()" << endl;
    X x2(move(x1));
    cout << "static_cast<T&&>" << endl;
    X x3(static_cast<X&&>(x1));

    // swap forces move
    cout << endl;
    X x4, x5;
    cout << "swap" << endl;
    swap(x4, x5);
    cout << "swap_0" << endl;
    swap_0(x4, x5);
    cout << "swap_1" << endl;
    swap_1(x4, x5); // same
    cout << "swap_2" << endl;
    swap_2(x4, x5);
    
    // std::move is used to indicate that an object t may be
    // "moved from", i.e. allowing the efficient transfer of
    // resources from t to another object.

    f2();

    return 0;
}

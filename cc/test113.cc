#include <iostream>
#include <vector>
using namespace std;

class X {
public:
    X() : v{new vector<int>(0)} { }
    X(const X&); // 3 lval copy-constructor
    X(X&&); // 5 rval/move copy-constructor
    X& operator=(const X& rhs); // 3 lval assign. op.
    X& operator=(X&& rhs); // 5 rval/move assign. op.
    ~X() {delete v;} // 3 destructor
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

X f0()
{
    return X(); // copy-elision no move called
    // return move(X());
}

template<class T>
void swap_0(T& a, T& b)
{
    T tmp {static_cast<T&&>(a)}; 
    a = static_cast<T&&>(b); 
    b = static_cast<T&&>(tmp); 
}

// move produces an rval reference
template<class T>
void swap_1(T& a, T& b)
{
    T tmp {move(a)};
    a = move(b);
    b = move(tmp); 
}

// overload the function call
template<class T> void swap_1(T&& a, T& b)
{
    T tmp {move(a)};
    a = move(b);
    b = move(tmp); 
}

template<class T> void swap_1(T& a, T&& b)
{
    T tmp {move(a)};
    a = move(b);
    b = move(tmp); 
}
    
void f1()
{
    vector<int> v = {1, 2, 3};

    swap_1(v, vector<int>{4, 5, 6});
}

int main(int argc, char *argv[])
{
    cout << "copy-elision no move called" << endl;
    X x1(f0());
    cout << "move()" << endl;
    X x2(std::move(x1));
    cout << "static_cast<T&&>" << endl;
    X x3(static_cast<X&&>(x1));

    cout << "Swap..." << endl;
    X x4, x5;
    cout << "swap_0" << endl;
    swap_0(x4, x5);
    cout << "swap_1" << endl;
    swap_1(x4, x5); // same
    
    // std::move is used to indicate that an object t may be
    // "moved from", i.e. allowing the efficient transfer of
    // resources from t to another object.
    
    return 0;
}

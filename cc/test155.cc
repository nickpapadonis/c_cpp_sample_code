// g++ -pedantic -Wall -std=c++11 -fno-elide-constructors -g test155.cc && ./a.out
// clang++ -pedantic -Wall -Werror -std=c++11 -Wdeprecated -fno-elide-constructors test155.cc && ./a.out
#include <iostream>
#include <utility>
using namespace std;

template<class T>
class Handle
{
    T* p;
public:
    Handle(T* pp) : p{pp} { }
    T& operator*() { return *p; }
    Handle(const Handle& a) : p{new T{*a.p}} { }
    Handle& operator=(const Handle& a) {
	Handle tmp {a};
	swap(*this, tmp);
	return *this;
    }
    Handle(Handle&& a) : p{a.p} { a.p = nullptr; }
    Handle& operator=(Handle&& a) { swap(p, a.p); return *this;}
    ~Handle() { delete p; }
};

int main(int argc, char *argv[])
{
    Handle<int> h0 {new int{7}};
    Handle<int> h1 {h0}; // error : no copy constructor
    cout << *h0 << endl;
    cout << *h1 << endl;
    Handle<int> h2 {new int{9}};
    h1 = h2;
    cout << *h1 << endl;
}

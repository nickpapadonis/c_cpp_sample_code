#include <iostream>
using namespace std;
// g++ -pedantic -Wall -fno-elide-constructors test148b.cc && ./a.out

class X {
    int i;
public:
    X() : i{} {}
    X(int xx) : i{xx} {}

#if 1 // defaults work
    X(const X& a) : i{a.i} {cout << "cc" << endl;}
    X& operator=(const X& a) {
	cout << "ca" << endl;
	X temp {a};
	swap(*this, temp);
	return *this;
    }

    X(X&& a) : i{move(a.i)} {cout << "mc" << endl; a.i = 0;}
    X& operator=(X&& a) {cout << "ma" << endl; swap(i, a.i); return *this;}
#endif 
    bool operator!=(const X& x) {return i != x.i;}
    bool operator<(const X& x) {return i < x.i;}
    bool operator>(const X& x) {return i > x.i;}
    X& operator++() {i++; return *this;}
    X& operator--() {i--; return *this;}
    X& operator+=(const X& x) {i += x.i; return *this;}
    X& operator-=(const X& x) {i -= x.i; return *this;}
    X operator+(const X& x) {X tmp{*this}; tmp += x; return tmp;}
    X operator-(const X& x) {X tmp{*this}; tmp -= x; return tmp;}
    friend ostream& operator<<(ostream& os, const X& x) {
	return os << x.i;
    }
    friend istream& operator>>(istream& is, X& x) {
	return is >> x.i;
    }

    X& operator+=(const int xi) {i += xi; return *this;}
    X& operator-=(const int xi) {i -= xi; return *this;}
    X operator+(const int xi) {X tmp{*this}; tmp += xi; return tmp;}
    X operator-(const int xi) {X tmp{*this}; tmp -= xi; return tmp;}
};

int main(int argc, char *argv[])
{
    X xx9{0}; // dc
    X xx10 = {0}; // il
    
    X xx0 = X{1}; // mc
    X xx12{X{1}}; // mc
    xx0 = X{0}; // ma
    X xx1{xx0}; // cc
    xx1 = xx0; // ca
#if 0
    X xx0{1};
    X xx1{2};
    X xx2 = xx0 + xx1;
    cout << xx2 << endl;;
    xx2 += 3;
    cout << xx2 << endl;
    X xx3 = xx2 + 3;
    cout << xx3 << endl;
    X xx4{xx3};
    cout << xx4 << endl;
    X xx5{}; xx5 = xx4;
    cout << xx5 << endl;
    X xx6{X{69}};
    cout << xx6 << endl;
#endif
#if 0    
    X xx7;
    cin >> xx7;
    cout << xx7;
#endif
}

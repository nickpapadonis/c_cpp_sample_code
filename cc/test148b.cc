#include <iostream>
#include <vector>
using namespace std;

class X {
    int i;
public:
    X() : i{0} {}
    X(int xx) : i{xx} {}
    
    X(const X& a) : i{a.i} {}
    X& operator=(const X& a) {
	X temp {a};
	swap(*this, temp);
	return *this;
    }

    X(const X&& a) : i{move(a.i)} {}
    X& operator=(X&& a) {swap(i, a.i); return *this;}

    friend bool operator!=(const X& a, const X& b);
    friend bool operator<(const X& a, const X& b);
    friend bool operator>(const X& a, const X& b);
    friend X& operator++(X& a);
    friend X& operator--(X& a);
    friend X& operator+=(X& a, const X& b);
    friend X& operator-=(X& a, const X& b);
    friend X operator+(const X& a, const X& b);
    friend X operator-(const X& a, const X& b);

    friend ostream& operator<<(ostream& os, const X& x);
    friend istream& operator>>(istream& is, X& x);

    friend X& operator+=(X& a, const int xi);
    friend X& operator-=(X& a, const int xi);
    friend X operator+(const X& a, const int xi);
    friend X operator-(const X& a, const int xi);
};

bool operator!=(const X& a, const X& b) {return a.i != b.i;}
bool operator<(const X& a, const X& b) {return a.i < b.i;}
bool operator>(const X& a, const X& b) {return a.i > b.i;}
X& operator++(X& a) {a.i++; return a;}
X& operator--(X& a) {a.i--; return a;}
X& operator+=(X& a, const X& b) {a.i += b.i; return a;}
X& operator-=(X& a, const X& b) {a.i -= b.i; return a;}
X operator+(const X& a, const X& b) {X tmp{a}; tmp += b.i; return tmp;}
X operator-(const X& a, const X& b) {X tmp{a}; tmp -= b.i; return tmp;}

ostream& operator<<(ostream& os, const X& x) {
    return os << x.i;
}
istream& operator>>(istream& is, X& x) {
    return is >> x.i;
}

X& operator+=(X& a, const int xi) {a.i += xi; return a;}
X& operator-=(X& a, const int xi) {a.i -= xi; return a;}
X operator+(const X& a, const int xi) {X tmp{a}; tmp += xi; return tmp;}
X operator-(const X& a, const int xi) {X tmp{a}; tmp -= xi; return tmp;}

int main(int argc, char *argv[])
{
    X xx0{1};
    X xx1{2};
    X xx2 = xx0 + xx1;
    cout << xx2 << endl;;
    xx2 += 3;
    cout << xx2 << endl;
    X xx3 = xx2 + 3;
    cout << xx3 << endl;
}

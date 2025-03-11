#include <iterator>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct X {
    int i;
    X(int ii) : i{ii} {}
    X(const X& x) : i{x.i} {} 
    X(X&& x) : i{x.i} {x.i = 0;}
    X& operator=(const X& x)
	{X tmp{x}; swap(*this, tmp); return *this;}
    X& operator=(X&& x) {swap(i, x.i); return *this;}
};
ostream& operator<<(ostream& os, const X& b)
{
    return os << b.i;
}

void f0()
{
    // Use constructor method
    vector<X> v {X(0), X(1), X(2)};
    vector<X> v2 {make_move_iterator(v.begin()),
		  make_move_iterator(v.end())};
    cout << endl << "f0: v orig (should be moved from)" << endl;
    copy(v.begin(), v.end(), ostream_iterator<X>(cout, ","));
    cout << endl << "f0: v2 copy output" << endl;
    copy(v2.begin(), v2.end(), ostream_iterator<X>(cout, ","));
    cout << endl;
}

void f1()
{
    vector<X> v {X(0), X(1), X(2)};
    vector<X> v2;
    copy(make_move_iterator(v.begin()),
	 make_move_iterator(v.end()), back_inserter(v2));
    cout << endl << "f1: v orig (should be moved from)" << endl;
    copy(v.begin(), v.end(), ostream_iterator<X>(cout, ","));
    cout << endl << "f1: v2 copy output" << endl;
    copy(v2.begin(), v2.end(), ostream_iterator<X>(cout, ","));
    cout << endl;
}

int main()
{
    f0(); f1();
    return 0;
}

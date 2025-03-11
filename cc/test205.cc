#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

struct X {
    string name;
    bool operator<(const X&) const;
};
bool X::operator<(const X& b) const
{
    return name < b.name;
}
ostream& operator<<(ostream& os, const X& x)
{
    return os << x.name;
}
ostream& operator<<(ostream& os, const pair<X,int> &p)
{
    return os << p.first << ", " << p.second;
}

template<class T>
void print_cont(T m)
{
    for (typename T::iterator i = m.begin();
	 i != m.end(); ++i) {
	cout << *i << endl;
    }
}

void f0()
{
    vector<pair<X,int>> v
	{pair<X,int>{{"efg"}, 1}, pair<X,int>{{"bcd"}, 2}};
    map<X, int> m {v.begin(), v.end()};
    cout << m[X{"bcd"}] << endl;
    cout << m[X{"efg"}] << endl;
    cout << m[X{"hij"}] << endl;
    pair<map<X, int>::iterator, bool> p;

    // value_type is a pair
    p = m.insert({{"lmn"}, 9});
    cout << p.first->first << ", " << p.first->second << ": " <<
	p.second << endl;

    vector<pair<X, int>> v2
	{pair<X, int>({"zyx"}, 69)};
    m.insert(v2.begin(), v2.end());

    map<X,int>::iterator i = m.find(X{"efg"});
    m.erase(i);
    m.erase(X{"zyx"});
    print_cont(m);
}

struct Y {
    string name;
};
struct Y_less {
    bool operator()(const Y&, const Y&) const;
};
bool Y_less::operator()(const Y& a, const Y& b) const
{
    return a.name < b.name;
}
bool Y_less_fn(const Y& a, const Y& b)
{
    return a.name < b.name;
}
void f1()
{
    map<Y, int, Y_less> m;
    map<Y, int, bool(*)(const Y&, const Y&)> m2;
}

void f2()
{
    vector<X> vx {X{"abc"}, X{"def"}};
    set<X> sx {vx.begin(), vx.end()};
    sx.insert(X{"jkl"});

    set<X>::iterator i;
    if ((i = sx.find(X{"abc"})) != sx.end())
	sx.erase(i);
    print_cont(sx);
}

int main()
{
    f2();
    return 0;
}

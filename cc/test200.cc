#include <unordered_map>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

struct X {
    X(string n) : name{n} {}
    string name;
    bool operator==(const X& b0) const { return name == b0.name; }
};
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

namespace std {
    template<>
    struct hash<X> {
	size_t operator()(const X&) const;
    };
    size_t hash<X>::operator()(const X& a) const
    {
	return hash<string>{}(a.name);
    }
    template<>
    struct equal_to<X> {
	bool operator()(const X&, const X&) const;
    };
    bool equal_to<X>::operator()(const X& a, const X& b) const
    {
	return a.name == b.name;
    }
}

size_t hashX(const X& a)
{
    return hash<string>{}(a.name);
}

void f0()
{
    unordered_map<X,int,hash<X>> m({{X{"a"}, 1}, {X{"b"}, 2}},
				   100, hash<X>{});
    X x{"abc"};
    m[x] = 9;
    vector<pair<X,int>> v {{X{"z"}, 99}, {X{"p"}, 26}};
    m.insert(v.begin(), v.end());
    m.insert({X{"h"}, 21});
    m.insert(pair<X,int>{X{"l"}, 8});
    unordered_map<X,int,hash<X>>::iterator i;
    if ((i = m.find({X{"l"}})) != m.end())
	m.erase(i);
    print_cont(m);
}

int main()
{
    f0();
//    unordered_map<X,int> m {X{"a"}, X{"b"}};

//    unordered_map<X,int,function<size_t(const X&)>> m(100, &hashX);
//    unordered_map<X,int,size_t(*)(const X&)> m(100, &hashX);
}


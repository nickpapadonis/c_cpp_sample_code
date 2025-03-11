#include <iostream>
#include <unordered_map>
#include <functional>
#include <iostream>
using namespace std;

struct X {
    X(string n) : name{n} {}
    string name;
    bool operator==(const X& b0) const { return name == b0.name; }
};

namespace std {
    template<>
    struct hash<X> {
	size_t operator()(const X&) const;
    };
    size_t hash<X>::operator()(const X& a) const
    {
	return hash<string>{}(a.name);
    }
}

int main()
{
    unordered_map<X,int> m {{X{"a"}, 1}, {X{"b"}, 2}};
    X x{"b"};
    int i = m[x];
    cout << i << endl;
}


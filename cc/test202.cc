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
        cout << a.name << endl;
        return hash<string>{}(a.name);
    }
}

size_t hashX(const X& a)
{
    return hash<string>{}(a.name);
}

int main()
{
//    unordered_map<X,int,hash<X>> m(100, hash<X>{});
//    unordered_map<X,int,function<size_t(const X&)>> m(100, &hashX);
    unordered_map<X,int,size_t(*)(const X&)> m(100, &hashX);
    X x{"abc"};
    m[x] = 1;
    int i = m[x];
    cout << i << endl;
}

#include <iostream>
using namespace std;

bool cmp0(const string&, const string&)
{
    return true;
}

template<class Key>
class lt {
    Key shift;
public:
    lt() {}
    lt(Key _shift) : shift{_shift} {}
    inline bool operator()(const Key& v0, const Key& v1) {
	return v0 < v1;
    }
};

template<typename Key, class V, typename Compare = std::less<Key>>
class map {
public:
    map() { }
    map(Compare c) :cmp{c} { } 
    Compare cmp {};
    bool f0() {return cmp(string{}, string{});}
};
    
int main(int argc, char *argv[])
{
    using Cmp = bool (*)(const string&, const string&);
    map<string,int,Cmp> m4 {cmp0};
    map<string,int,Cmp> m6 {+[](const string& s0, const string& s1){return true;}};
    auto cmp = +[](const string& s0, const string& s1){return true;};
    map<string,int,decltype(cmp)> m8{cmp};
    map<string,int,lt<string>> m5{lt<string>{string{""}}};
    return 0;
}

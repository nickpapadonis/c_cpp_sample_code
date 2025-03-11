#include <iostream>
#include <vector>
using namespace std;

template<class V>
class X {
public:
    X();
    V& f0(const V&);
    const V& f1(const V&);
    V& operator[](const V&);
    template<class Z>
    friend ostream& operator<<(ostream&, const X<Z>&);
private:
    vector<V> v;
};

template<class V>
X<V>::X()
{
    v.push_back(0);
    v.push_back(1);
}

// input :    const int& x = arg;   
// output :   int& f0(const int& x) = return z
template<class V>
V& X<V>::f0(const V& x)
{
    return v[x];
}

template<class V>
const V& X<V>::f1(const V& x)
{
    return v[x];
}

template<class V>
V& X<V>::operator[](const V& x)
{
    return v[x];
}

template<typename Z>
ostream& operator<<(ostream& os, const X<Z>& x)
{
    for (auto& p : x.v)
	os << p << ",";
    return os;
}

int main(int argc, char *argv[])
{
    X<int> x0;
    int& t = x0.f0(0);
    cout << x0 << endl;
    t = 5;
    cout << x0 << endl;
    x0.f0(0) = 6;
    cout << x0 << endl;
    // x0.f1(1) = 7; // read only
    x0[1] = 9;
    cout << x0 << endl;

    int *pi = &x0[1];
    *pi = 0;
    cout << x0 << endl;

    cout << x0.operator[](0) << endl;
    cout << x0[0] << endl;
    x0.operator[](0) = 1;
    cout << x0.operator[](0) << endl;
    
    int var = 1;
    int& r = var;
    int x = r;

    cout << "x: " << x << endl;

    r = 2; // var = 2

    cout << "var: " << var << endl;

    int var2 = 1;
    const int& rc = var2;
    // rc = 2; // error : assignment ro ref
    
    // double& dr = 1; // error : const lvalue needed
    const double& cdr {1}; // OK

    double temp = double{1};
    const double& cdr2 {temp};
     
    cout << "cdr2 " << cdr2 << endl;
     
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
class GT {
private:
    vector<T>& vo; // vector<T> * const vo_p; vector<T>& vo = *vo_p
    T max;
public:
    GT(vector<T>& vo_, T max_) : vo{vo_}, max{max_} {}
    void operator()(const T& x) {if (x > max) vo.push_back(x);}
};

template <class T>
vector<T> f2(const vector<T>& v)
{
    vector<T> vo;
    
    for_each(v.begin(), v.end(),
	     GT<T>(vo, 5));

    return vo;
}


template <class T>
vector<T> f(const vector<T>& v)
{
    const int max = 5;
    vector<T> vg;
    
    for_each(v.begin(), v.end(),
	     [&vg](const T &x) {if (x > max) vg.push_back(x); }); 

    return vg;
}

int main(int argc, char *argv[])
{
    vector<int> v {0, 1, 6, 8};
    vector<int> v2;
    
    v2 = f(v);
    for (auto& p : v2)
	cout << p;
    cout << endl;

    v2 = f2(v);
    for (auto& p : v2)
	cout << p;
    cout << endl;

    return 0;
}

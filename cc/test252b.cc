#include <iostream>
#include <random>
#include <map>
#include <functional>
using namespace std;

class rand_int {
public:
    rand_int(int lo, int hi) : p{lo,hi}, re{rd()} {}
    int operator()() const { return r(); }
private:
    uniform_int_distribution<>::param_type p;
    random_device rd;
    default_random_engine re;
    function<int()> r = bind(uniform_int_distribution<>{p}, re);
};

int main()
{
    map<int,int> m;
    rand_int ri{0,9};
    for (int i=0; i < 100; ++i) {
        m[ri()]++;
    }

    for (map<int,int>::iterator it = m.begin();
         it != m.end(); ++it)
        cout << it->first << ", " << it->second << '\n';

    return 0;
}

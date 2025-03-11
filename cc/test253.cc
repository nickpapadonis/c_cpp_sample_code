#include <iostream>
#include <random>
#include <map>
using namespace std;

int main()
{
    random_device rd;
    default_random_engine gen(rd());
    uniform_int_distribution<int> p{0,9};

    map<int,int> m;
    for (int i=0; i < 100; ++i) {
        m[p(gen)]++;
    }

    for (map<int,int>::iterator it = m.begin();
         it != m.end(); ++it)
        cout << it->first << ", " << it->second << '\n';
    
    return 0;
}

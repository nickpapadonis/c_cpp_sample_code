#include <iostream>
#include <random>
#include <map>
using namespace std;

int main()
{
    random_device rd;
    default_random_engine gen;
    uniform_int_distribution<int> p{0,9};
    
    map<int,int> m;
    const int ntries = 10000;
    for (int i=0; i < ntries; ++i) {
	m[p(gen)]++;
    }

    for (map<int,int>::iterator it = m.begin();
	 it != m.end(); ++it)
	cout << it->first << " " << string(it->second*100/ntries, '*') << '\n';
    
    return 0;
}

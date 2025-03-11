#include <iostream>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
    map<string, int> m;

    m["a"] = 1;
    m["b"] = 2;
    
    cout << m.begin()->first << endl;
    auto p = m.end(); --p;
    cout << p->first << endl;

    return 0;
}

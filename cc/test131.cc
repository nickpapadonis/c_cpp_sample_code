#include <iostream>
#include <utility>
using namespace std;

template <class U, class V>
ostream& operator<<(ostream &os, const pair<U, V> &p)
{
    return os << p.first << "," << p.second;
}

int main(int argc, char *argv[])
{
    pair<int, string> p {1, "one"};

    cout << p << endl;
    
    return 0;
}

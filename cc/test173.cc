#include <list>
#include <iostream>
using namespace std;
struct X {
    int a;
    bool operator<(const X&);
};

bool X::operator<(const X& x)
{
    return a > x.a;
}

int main(int argc, char *argv[])
{
    list<X> xl0 = {X{2}, X{0}, X{1}};
    xl0.sort();
    for (auto& p : xl0)
	cout << p.a;
    cout << endl;
    return 0;
}

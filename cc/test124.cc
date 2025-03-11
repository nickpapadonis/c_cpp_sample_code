#include <iostream>
#include <string>
using namespace std;

void g(const string& a, string& b)
{
}

void f(string& a, string& b)
{
    const string& s1 = a + b;
    string s2 = a + b;

    g(s1, s2);
}

void i(const int *p)
{
}

void h()
{
    int x;
    i(&x);
}

int main(int argc, char *argv[])
{
    string s1, s2;

    f(s1, s2);

    h();
    
    return 0;
}

#include <iostream>
using namespace std;

void fp(char* p)
{
    while (*p)
        cout << ++*p;
}

void fr2(char& r)
{
    char* p = &r;
    while (*p)
        cout << ++*p;
}


int main(int argc, char *argv[])
{
    char s[] = "abc";
    char *p = s;

    fp(p);
    fr2(*p);
    
    return 0;
}


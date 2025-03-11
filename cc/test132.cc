#include <iostream>
#include <functional>
#include <string.h>
using namespace std;

void rev2(char *b, char *e)
{
    while (1 < e - b)
	swap(*b++, *--e);
}

void rev(char *b, char *e)
{
    if (1 < e - b) {
	swap(*b, *--e);
	rev(++b, e);
    }
}

void f(char *b, char *e)
{
    function<void(char* b, char* e)> rev =
	[&](char* b, char* e) {
	    if (1<e-b) {
		swap(*b,*--e); rev(++b,e);
	    }
	};
    rev(b, e);
}

int main(int argc, char *argv[])
{
    char a[] = "ab";

    rev(a, a + strlen(a));
    cout << a << endl;

    f(a, a + strlen(a));
    cout << a << endl;

    string b = "cd";
    rev(&b[0], &b[0] + b.size());
    cout << b << endl;

    rev2(&b[0], &b[0] + b.size());
    cout << b << endl;

    return 0;
}


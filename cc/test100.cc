#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc, char *argv[])
{
    int a[] = {0, 1};
    int (*p)[] = (int (*)[]) &a;

    // all are the same address to array's firt elem
    printf("a %p\n", (void*) a);
    printf("&a %p\n", (void*) &a);
    printf("&a[0] %p\n", (void*) &a[0]);
    printf("p %p\n", (void*) p);

    // all are the first element
    cout << (*p)[0] << endl;
    cout << **p << endl;

    // second element
    (**p)++;
    cout << **p << endl;
    
    return 0;
}

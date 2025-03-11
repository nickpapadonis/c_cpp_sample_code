#include <iostream>

int main(int argc, char *argv[])
{
    int a[] = {0, 1};
    const int * const p1 = a;
    const int *p2 = a;

    // p1++; // error
    // *p1 = 3; // error
    p2++;    
    // *p2 = 3; // error

    printf("%d\n", *p1);
    printf("%d\n", *p2);
    
    return 0;
}

#include <iostream>

int f(int x)
{
    return x;
}

int f2(int (*)(int));

int f2(int (*f)(int), int z)
{
    return f(z);
}

int main(int argc, char *argv[])
{
    int (*fptr)(int) = &f;
    int y = fptr(1);
    printf("y = %d\n", y);
    
    int (*fptr2)(int) = f;
    int z = fptr2(1);
    printf("z = %d\n", z);

    int h = f2(&f, 2);
    printf("h = %d\n", h);
    
    return 0;
}

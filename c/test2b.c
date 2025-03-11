#include <stdio.h>

struct A {
     int a;
     int b;
};

int f(void *[], int (*)(void *, void *));

int f(void *v[], int (*cmp)(void *a, void *b))
{
     return cmp(v[0], v[1]);
}

int cmpA(void *a0, void *a1)
{
     struct A *a = (struct A *) a0;
     struct A *b = (struct A *) a1;
     
     if (a->a < b->a)
	  return -1;
     else if (a->a > b->a)
	  return 1;
     return 0;
}

int main(int argc, char *argv[])
{
     struct A a = {1, 1}, b = {0, 0};
     void *v[] = {(void *) &a, (void *) &b};

     int res = f(v, &cmpA);

     printf("res = %d\n", res);
     
     return 0;
}

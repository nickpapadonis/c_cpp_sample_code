#include <stdio.h>

void f(int x)
{
  printf("&x = %p\n", &x);
  x = x++;
  int *px = &x;
  printf("px = %p\n", px);
}

int main(int argc, char *argv[])
{
  f(0);
  return 0;
}

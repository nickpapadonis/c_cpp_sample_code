#include <stdio.h>

int main(int argc, char *argv[])
{
  int a[10];

  int *p = &a[0];

  printf("sizeof(int) = %d\n", sizeof(int));
  printf("p %p\n", p);

  long d = &a[4] - &a[0];
  printf("d %d\n", d);
  p = &a[0] + (&a[4] - &a[0]) / 2;

  printf("p %p\n", p);
  
  return 0;
}

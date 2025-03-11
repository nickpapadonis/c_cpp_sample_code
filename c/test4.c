#include <stdio.h>

int main(int argc, char *argv[])
{
  int a[] = {1, 2, 3, -1};

  int *pa1 = &a[0];
  int *pa2 = a;

  printf("pa1 %p\n", pa1);
  printf("pa2 %p\n", pa2);

  while (*pa1 != -1)
    printf("%d ", *pa1++);
  printf("\n");
  
  return 0;
}

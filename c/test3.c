#include <stdio.h>

int main(int argc, char *argv[])
{
  int a[][2] = {{1, 2}, {3, 4}};

  int (*p)[2] = a;

  /* pointers to int */
  printf("&a[0][0] %p\n", &a[0][0]);
  printf("&a[0][1] %p\n", &a[0][1]);
  printf("&a[1][0] %p\n", &a[1][0]);
  printf("&a[1][1] %p\n", &a[1][1]);
  printf("\n");
  
  /* points to first int */
  printf("a %p\n", a);
  printf("p %p\n", p);
  printf("*p %p\n", *p);
  printf("\n");

  /* points to (int a[x]) */
  printf("(p + 0) %p\n", (p + 0));
  printf("(p + 1) %p\n", (p + 1));
  printf("\n");

  /* int (*p)[2] = a */
  /* address of first obj */
  printf("*(p + 0) %p\n", *(p + 0));
  printf("*(p + 0) + 1 %p\n", *(p + 0) + 1);
  /* address of second obj */
  printf("*(p + 1) %p\n", *(p + 1));
  printf("*(p + 1) + 1 %p\n", *(p + 1) + 1);

  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      printf("*(*(p + %d) + %d) = %d\n", i, j, *(*(p + i) + j));

  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      printf("*(*(a + %d) + %d) = %d\n", i, j, *(*(a + i) + j));

}

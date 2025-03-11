#include <stdio.h>

int main(int argc, char *argv[])
{
  int *b[3];
  int b0[] = {0, 1, -1};
  int b1[] = {2, 3, -1};
  b[0] = b0;
  b[1] = b1;
  b[2] = 0;

  int **pb = b;
  
  printf("b[0][0] = %d\n", b[0][0]);
  printf("b[0][1] = %d\n", b[0][1]);
  printf("b[1][0] = %d\n", b[1][0]);
  printf("b[1][1] = %d\n", b[1][1]);

  int *i, j;
  while (i = (*pb++))
    while ((j = *i++) != -1)
      printf("%d ", j);
  printf("\n");
  
  return 0;
}

#include <stdio.h>

int main(int argc, char *argv[])
{
  char *b[2];

  b[0] = "ab";
  b[1] = "cd";

  printf("%s %s\n", b[0], b[1]);
  printf("%c %c %c %c\n", b[0][0], b[0][1], b[1][0], b[1][1]);

  int *c[2];
  int c0[] = {0, 1};
  int c1[] = {2, 3};
  c[0] = c0;
  c[1] = c1;

  printf("%d %d %d %d\n", c[0][0], c[0][1], c[1][0], c[1][1]);
  
  return 0;
}

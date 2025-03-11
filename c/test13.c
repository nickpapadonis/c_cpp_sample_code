#include <stdio.h>

int main(int argc, char *argv[])
{
  char *a[] = {"abc", "def", 0};
  char **b = a;

  printf("%c\n", a[0][1]); /* b */
  printf("%c\n", *(*(a + 0) + 1)); /* b */
  printf("%c\n", *(*(b + 0) + 1)); /* b */

  char c[][15] = {"abc", "def"};
  printf("%c\n", c[0][1]); /* b */
  printf("%c\n", *(*(c + 0) + 1)); /* b */
  
  return 0;
}

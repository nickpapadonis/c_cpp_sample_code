#include <stdio.h>

void f(char a[])
{
  a[0] = 'x';
}

int main(int argc, char *argv[])
{
  char a[] = "abcd";
  char *b = "abcd";
  char *c = a;
  
  printf("%c\n", a[0]);
  a[0] = 'x';
  printf("%c\n", a[0]);

  f(b);
  
  printf("%c\n", c[0]);
  c[0] = 'x';
  printf("%c\n", c[0]);

    return 0;
}

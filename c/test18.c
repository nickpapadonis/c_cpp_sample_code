#include <stdio.h>

struct s1 {
  char *s;
};

int main(int argc, char *argv[])
{
  struct s1 s1 = {"abcd"};
  char c;

  while (c = *s1.s++) {
    printf("%c", c);
  }
  printf("\n");
  
  return 0;
}

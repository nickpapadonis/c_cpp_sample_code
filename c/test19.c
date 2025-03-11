#include <stdio.h>

struct s1 {
  char *s;
};

int main(int argc, char *argv[])
{
  struct s1 s1[2];
  struct s1 *p = s1;
  char c;
  
  s1[0].s = "ab";
  s1[1].s = "cd";

  for (int i = 0; i < 2; i++) {
    c = *p++->s;
    printf("%c", c);
  }
  printf("\n");
  
  return 0;
}
  

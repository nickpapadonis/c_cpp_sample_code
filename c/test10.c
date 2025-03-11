#include <stdio.h>

void ps1(char *s)
{
  printf("0 ps1 %p\n", s);
}

void ps2(char s[])
{
  printf("0 ps2 %p\n", s);
}

int main(int argc, char *argv[])
{
  /* allocates array on stack */
  char s1[] = "abc";
  /* allocates array in data */
  char *s2 = "def";

  printf("p s1 %p\n", s1);
  printf("p s2 %p\n", s2);

  ps1(s1);
  ps2(s1);
  ps1(s2);
  ps2(s2);
  
  return 0;
}

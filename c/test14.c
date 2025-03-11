#include <stdio.h>

int main(int argc, char *argv[])
{
  printf("argv p %p\n", argv);
  printf("*argv p %p\n", *argv);

  int i = 0;
  int targc = argc;
  while (argc-- > 0)
    printf("%s%s", *(argv + i++), (argc < 1) ? "" : " ");
  printf("\n");

  argc = targc;
  while (--argc > 0)
    printf("%s%s", *++argv, (argc > 1) ? " " : "");
  printf("\n");

  return 0;
}

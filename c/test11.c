#include <stdio.h>

void pl(char *lines[])
{
     printf("lines %p\n", lines);
}

int main(int argc, char *argv[])
{
  char *lines[] = {"ab", "cd", "ef", "gh", 0};

  pl(lines);
  
  /* pointer to (char *) first element */
  printf("lines %p\n", lines);
  printf("&lines[0] %p\n", &lines[0]);

  /* pointer to each (char *) element */
  for (int i = 0; i < 4; i++)
    printf("lines + %d %p\n", i, lines + i);

  /* deref each ptr to (char *) */
  for (int i = 0; i < 4; i++)
    printf("lines + %d %s\n", i, *(lines + i));

  char **lp = lines;
  for (int i = 0; i < 4; i++)
    printf("lp++ %p\n", lp++);

  lp = lines;
  while (*lp != 0)
    printf("*lp++ = %s\n", *lp++);

  lp = lines;
  while (*lp != 0) {
    char *c = *lp++;
    while (*c != 0)
      printf("%c", *c++);
    printf("\n");
  }
  
  return 0;
}

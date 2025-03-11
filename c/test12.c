#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char *lp1[] = {"ab", "cd", 0};
  char *lp2[10];
  int nline = 0;

  while (*(lp1 + nline)) {
    *(lp2 + nline) = (char *) malloc(strlen(*(lp1 + nline)));
    strcpy(*(lp2 + nline), *(lp1 + nline));
    nline++;
  }

  for (int i = 0; i < nline; i++)
    printf("%s\n", *(lp2 + i));
  
  return 0;
}

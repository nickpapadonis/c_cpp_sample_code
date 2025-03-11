#include <stdio.h>

int main(int argc, char *argv[])
{
  char c;
  while(--argc > 0 && (*((*++argv) + 0) == '-'))
    while (c = *++*argv)
      switch (c)
	{
	case 'x':
	  printf("%c\n", c);
	  break;
	case 'y':
	  printf("%c\n", c);
	  break;
	default:
	  printf("illegal %c\n", c);
	  argc = 0;
	  break;
	}
}

#include <stdio.h>

const char *error(int i)
{
     switch (i) {
     case 0:
	  return "Error 0";
     default:
	  return 0;
     }
}
	
int main(int argc, char *argv[])
{
     const char *p;
     if ((p = error(0)))
	  printf("%s\n", p);
     else
	  printf("invalid error\n");

     return 0;
}

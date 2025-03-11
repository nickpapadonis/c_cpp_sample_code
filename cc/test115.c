#include <stdio.h>

int main(int argc, char *argv[])
{
     char *p = "abc";
     
     while (*p)
	  printf("%c", *p++);

     return 0;
}

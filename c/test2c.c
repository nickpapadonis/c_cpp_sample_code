#include <stdio.h>

void f(char a[])
{
     for (int i=0; a[i]!=0; i++)
	  printf("%c", a[i]);
     printf("\n");

     char *p = (char *) a;
     while (*p != 0)
	  printf("%c", *p++);
     printf("\n");

     for (char *p = a; *p != 0; p++)
	  printf("%c", *p);
     printf("\n");
}

int main(int argc, char *argv[])
{
     char a[] = "abcd";

     f(a);
     
     return 0;
}

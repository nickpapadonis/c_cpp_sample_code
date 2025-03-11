#include <stdio.h>

enum f_t {E_A, E_B};

const char *f(enum f_t s) {
     switch (s) {
     case E_A:
	  return "String A";
	  break;
     case E_B:
	  return "String B";
	  break;
     }

     return "";
}

int main(int argc, char *argv[])
{
    const char *a = "abcd";

    while (*a)
	 printf("%c", *a++);
    printf("\n");

    printf("%s\n", f(E_A));
    printf("%s\n", f(E_B));
    
    return 0;
}

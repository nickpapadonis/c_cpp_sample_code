#include <stdio.h>

static int b[] = {3, 4, 5};
#define BELEMS (sizeof(b) / sizeof(b[0]))
     
int main(int argc, char *argv[])
{
     int a[] = {0, 1, 2};

     for (int i = 0; i != sizeof(a) / sizeof(a[0]); ++i)
	  printf("%d ", a[i]);
     printf("\n");

     for (int *p = a; p != a + (sizeof(a) / sizeof(a[0])); ++p)
	  printf("%d ", *p);
     printf("\n");

     for (int i=0; i < BELEMS; i++)
	  printf("%d ", b[i]);
     printf("\n");
     
     return 0;
}

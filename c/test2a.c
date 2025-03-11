#include <stdio.h>

int main(int argc, char *argv[])
{
     int *a[10];
     int **p = a;

     int i0 = 0, i1 = 1;
     
     for (int i=0; i<10; ++i) {
	  if ((i % 2) == 0)
	       *(p + i) = &i0;
	  else if ((i % 2) == 1)
	       *(p + i) = &i1;
     }

     for (int i=0; i<10; ++i) {
	  int z = **(p + i);
	  printf("z = %d\n", z);
     }
     
     return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void insertion(int *A, int sz)
{
     int i, j, key;
     for (j = 1; j < sz; ++j) {
	  key = A[j];
	  i = j - 1;
	  while (i > -1 && A[i] > key) {
	       A[i + 1] = A[i];
	       i--;
	  }
	  A[i + 1] = key;
     }
}

int main(int argc, char *argv[])
{
     int A[200];
     int j = 0;
     for (int i = 1; i < argc; ++i) {
	  A[j++] = atoi(argv[i]);
     }

     insertion(A, j);

     int i;
     for (i = 0; i < j; i++)
	  printf("%d,", A[i]);
     printf("\n");
	       
     return 0;
}

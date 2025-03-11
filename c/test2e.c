#include <stdio.h>

void f0(int a[][2])
{
     for (int i=0; a[i][0] != -1; i++) {
	  for (int j=0; j<2; j++) {
	       printf("%d", a[i][j]);
	  }
     }
     printf("\n");
}

int main(int argc, char *argv[])
{
     int b[3][2] = {{0, 1}, {2, 3}, {-1, -1}};
     f0(b);

     return 0;
}

#include <stdio.h>

struct X {
     int a;
     double b;
};

static struct X p[] = {{0, 1.0},
		       {1, 2.0}};
#define P_SIZE (sizeof(p)/sizeof(p[0]))

int main(int argc, char *argv[])
{
     for (int i=0; i<P_SIZE; ++i) {
	  printf("p.a = %d\n", p[i].a);
	  printf("p.b = %.2f\n", p[i].b);
     }
     
     return 0;
}

#include <stdlib.h>
#include <string.h>

struct X {
     int x, y;
};

void init_x(struct X *p)
{
     bzero(p, sizeof(*p));
}

int main(int argc, char *argv[])
{
     struct X *px = (struct X *)
	  malloc(sizeof(struct X) * 20);
     struct X *last = px + 20;

     for (struct X *p = px; p != last; ++p)
	  init_x(p);
     
     return 0;
}

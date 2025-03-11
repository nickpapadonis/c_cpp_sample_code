#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
     const int maxr = 10;
     srand((unsigned) time(NULL));
     int r = (int)(((double)(rand())/RAND_MAX) * maxr);
     printf("r = %d\n", r);
     return 0;
}

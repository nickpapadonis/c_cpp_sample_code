#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int *p = (int *) malloc(sizeof(int));
    printf("%p\n", (void *) p);
    free(p); p = 0;
    printf("%p\n", (void *) p);
    return 0;
}

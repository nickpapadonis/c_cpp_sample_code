#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmpfunc (const void *a, const void *b) {
     const char **ia = (const char **)a;
     const char **ib = (const char **)b;
     return (strcmp(*ia, *ib));
}

int main()
{
    const char *as[] = {"Grieg", "Williams", "Bach", "Handel" };

    qsort(as, sizeof(as)/sizeof(*as), sizeof(*as), cmpfunc);
    
    for (int i=0; i < sizeof(as)/sizeof(*as); ++i) {
	printf("%s\n", as[i]);
    }

    char s[] = "zyxa";
    // const char *s2 = "zyxa"; // NO in data section
    qsort(s, strlen(s), sizeof(*s), (int(*)(const void*,const void*))strcmp);
    printf("%s\n", s);
    
    return 0;
}

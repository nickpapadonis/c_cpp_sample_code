#include <stdio.h>
#include <string.h>

int main()
{
    const char* as[] = {"Grieg", "Williams", "Bach", "Handel" };
    qsort(as, sizeof(as)/sizeof(*as), sizeof(*as), (int(*)(const void*, const void*)) strcmp);
    for (int i=0; i < sizeof(as)/sizeof(*as); ++i) {
	printf("%s\n", as[i]);
    }
	
    return 0;
}

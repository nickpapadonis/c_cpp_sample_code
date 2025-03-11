#include <stdio.h>
#include <string.h>

int main(void)
{
     const char *p = 0;
     printf("%s", p);
     const char *p2 = "";
     printf("%s", p2);
     return 0;
}

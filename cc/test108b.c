#include <stdio.h>

int main(int argc, char *argv[])
{
    char b[] = "defg";
    char c[] = "hijk";
    
    char *bp = (char *) b;
    char *cp = (char *) c;
    while (*bp)
	 *bp++ = *cp++;

    bp = b;
    while (*bp)
	 printf("%c", *bp++);

    return 0;
}

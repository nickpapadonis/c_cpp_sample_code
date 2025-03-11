#include <stdio.h>
#include <stdlib.h>

void pbits(unsigned char c)
{
     int i=8-1;
     while (i >= 0)
	  printf("%d", (c >> i--) & 1);
     printf("\n");
}

int main(int argc, char *argv[])
{
     unsigned char c = 0xFF;

     c ^= 0x11;
     pbits(c);
     c = ~c;
     pbits(c);

     // 00110000
     c = 0x3 << 4;
     pbits(c);
     c = ~c; // clear
     pbits(c);

     return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

struct A {
     char a;
     int b;
     char c;
     short d;
};

struct B {
     char a;
     int b;
     char c;
     short d;
} __attribute__ ((packed));

// $ od -t x1z temp.bin

int main(int argc, char *argv[])
{
     FILE *fp;

     fp = fopen("temp.bin", "w");

     struct B b = {'a', 0xA5A7A8A9, 'b', (short) 0xFAFB};
     printf("&b.a = %p\n", (void*) &b.a);
     printf("&b.b = %p\n", (void*) &b.b);
     printf("&b.c = %p\n", (void*) &b.c);
     printf("&b.d = %p\n", (void*) &b.d);

     // write out in big endian
     b.b = htonl(b.b);
     b.d = htons(b.d);

     if (fwrite(&b, sizeof(b), 1, fp) != 1)
	  printf("Error fwrite\n");

     fclose(fp);
     
     fp = fopen("temp.bin", "r");
     if (fread(&b, sizeof(b), 1, fp) != 1)
	  printf("Error fread\n");
     b.b = ntohl(b.b);
     b.d = ntohs(b.d);

     fclose(fp);
     
     printf("&b.a = 0x%x\n", b.a);
     printf("&b.b = 0x%x\n", b.b);
     printf("&b.c = 0x%x\n", b.c);
     printf("&b.d = 0x%x\n", b.d);

     // not bzeroed
     struct A a = {'a', 0xA5A7A8A9, 'b', (short) 0xFAFB};
     printf("&a.a = %p\n", (void*) &a.a);
     printf("&a.b = %p\n", (void*) &a.b);
     printf("&a.c = %p\n", (void*) &a.c);
     printf("&a.d = %p\n", (void*) &a.d);

     fp = fopen("temp2.bin", "w");
     if (fwrite(&a, sizeof(a), 1, fp) != 1)
	  printf("Error fwrite\n");

     fclose(fp);

     
     exit(0);
}

#include <stdio.h>
#include <stdlib.h>

struct B {
     char a;
     int b;
     char c;
     short d;
} __attribute__ ((packed));

int main(int argc, char *argv[])
{
     FILE *fp;
     fp = fopen("temp.bin", "w");

     struct B b = {'a', 0xA5A5A6A7, 'b', (short) 0xABAC};

     if (fwrite(&b, sizeof(b), 1, fp) != 1)
          printf("Error fwrite\n");

     exit(0);
}

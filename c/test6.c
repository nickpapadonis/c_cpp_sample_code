#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char *a[] = {"ab", "cd", 0}; /* init in the data section */
  char **p = a;

  /* 64-bit pointers of locations of each element
   * on the stack
   */
  printf("&a[0] = %p\n", &a[0]);
  printf("&a[1] = %p\n", &a[1]);

  /* address of each char *, 3 bytes each
   * in the data section
   */
  printf("a[0] = %p\n", a[0]);
  printf("a[1] = %p\n", a[1]);
  
  while (*p != 0)
    printf("%s\n", *p++);

  char b[][3] = {"ef", "gh", ""};
  /* 64-bit pointers of locations of each element
   * on the stack
   */
  printf("&b[0] = %p\n", &b[0]);
  printf("&b[1] = %p\n", &b[1]);

  /* pointer to each row
   * addresses are on the stack
   */
  printf("b[0] = %p\n", b[0]);
  printf("b[1] = %p\n", b[1]);

  char (*pb)[3] = b;
  while (strcmp(*pb, "") != 0)
    printf("%s\n", *pb++);
  
  return 0;
}

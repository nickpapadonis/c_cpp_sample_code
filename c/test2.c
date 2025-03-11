#include <stdio.h>

int main(int argc, char *argv[])
{
  /* array of (char *) ptrs, with (char *) init in data section */
  char *a[] = {"abc", "def", 0};

  char **p = a; /* ptr to first obj */
  char **p2 = &a[0]; /* ptr to first obj */
  int i;
    
  /* same, address of first element, which points to a (char *) */
  printf("a = %p\n", a);
  printf("(a + 0) = %p\n", (a + 0));
  printf("&a[0] = %p\n", &a[0]); /* &(*(a + 0)) */
  printf("\n");
  /* same, address of second element, which points to a (char *) */
  printf("(a + 1) = %p\n", (a + 1));
  printf("&a[1] = %p\n", &a[1]); /* &(*(a + 1)) */
  printf("\n");
  
  /* dereference to value of (char *) */
  printf("*(a + 1) p = %p\n", *(a + 1)); /* pts to data section (char *) "def" */
  /* print the (char *) */
  printf("*(a + 1) s = %s\n", *(a + 1)); /* def */
  printf("\n");

  printf("**a = %c\n", **a); /* a */
  printf("*(*(a + 0) + 0)= %c\n", **a); /* a */

  printf("*(*(a + 1) + 1) = %c\n", *(*(a + 1) + 1)); /* e */

  printf("*(*a + 1) = %c\n", *(*a + 1)); /* b */
  printf("*a = %s\n", *a); /* abc */

  printf("*a[1] = %c\n", *a[1]); /* d */
  printf("*(a[1] + 1) = %c\n", *(a[1] + 1)); /* e */
  printf("*(*(a + 1) + 2) = %c\n", *(*(a + 1) + 2)); /* f */

#if 0
  printf("p = %p\n", p); /* 0xXX */
  printf("p2 = %p\n", p2); /* 0xXX */
  
  while (*p != 0)
    printf("%s\n", *p++);

  p = a;
  for (i = 0; *(p + i) != 0; i++)
    printf("%s\n", *(p + i));

  for (i = 0; a[i] != 0; i++)
    printf("%s\n", a[i]);
#endif
  
  return 0;
}

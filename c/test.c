#include <stdio.h>


int main(int argc, char *argv[])
//int main(int argc, char **argv)  
{
  int i;
  char arr2[] = "def";
  
  /* These all reference same object */
  printf("&arr2 = %p\n", &arr2); /* ptr to array on stack */
  printf("\n");
  printf("arr2 = %p\n", arr2); /* ptr to first obj (char) of array on stack, ptr to d */
  printf("&arr2[0] = %p\n", &arr2[0]); /* ptr to first obj (char) of array on stack, ptr to d */
  printf("&(*(arr2 + 0)) = %p\n", &(*(arr2 + 0))); /* same */
  printf("\n");

  /* char arr2[] = "def"; */
  /* These both the same object */
  printf("*arr2 = %c\n", *arr2); /* deref ptr to first char */
  printf("*(arr2 + 0) = %c\n", *(arr2 + 0)); /* same */
  printf("arr2[0] = %c\n", arr2[0]); /* deref ptr to first char */
  printf("*(&arr2[0]) = %c\n", *(&arr2[0]));  /* same */
  printf("\n");

  printf("*(arr2 + 1) = %c\n", *(arr2 + 1)); /* same */
  printf("arr2[1] = %c\n", arr2[1]); /* deref ptr to first char */
  printf("*(&arr2[1]) = %c\n", *(&arr2[1]));  /* same */
  printf("\n");
  
  /* ---- */

  /* ptr to a char, it's variable so can be reassigned a value */
  char *arr1 = "abc";
  printf("&arr1 = %p\n", &arr1); /* ptr to (char *) obj on stack */
  
  /* These both reference same object */
  printf("arr1 = %p\n", arr1); /* ptr to first char obj in data */
  printf("*(&arr1) = %p\n", *(&arr1)); /* same */
  printf("&arr1[0] = %p\n", &arr1[0]); /* ptr to first char obj in data */
  printf("&(*(arr1 + 0)) = %p\n", &(*(arr1 + 0)));
  
  /* These all reference same object */
  printf("*arr1 = %c\n", *arr1); /* deref ptr to first char */
  printf("arr1[0] = %c\n", arr1[0]); /* deref ptr to first char */
  printf("*(&arr1[0]) = %c\n", *(&arr1[0]));
  printf("\n");

  /* iterate through pointer to each char */
  while (*arr1 != '\0')
    printf("%c ", *arr1++);
  printf("\n");

  /* iterate through array of pointers to chars */
  for (i = 0; i < argc; i++) {
    printf("argv[%d] = %s\n", i, argv[i]);
  }

  /* now for command line args */
  /* char *argv[] */
  {
    char **aptr = argv;
    while (argc > 0) {
      printf("%s\n", *aptr++);
      argc--;
    }
  }
  
  return 0;
}


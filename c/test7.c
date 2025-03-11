#include <stdio.h>

int main(int argc, char *argv[])
{
  printf("argv = %p\n", argv);

  for (int i = 0; i < argc; i++)
    printf("argv + %d = %p\n", i, argv + i);
  
  /* print locations of array elements */
  for (int i = 0; i < argc; i++)
    printf("&argv[%d] = %p\n", i, &argv[i]);

  for (int i = 0; i < argc; i++)
    printf("*(argv + %d) = %p\n", i, *(argv + i));

  /* print pointers held in array elements */
  for (int i = 0; i < argc; i++)
    printf("argv[%d] = %p\n", i, argv[i]);

  /* print string passing address of string array */
  for (int i = 0; i < argc; i++)
    printf("argv[%d] = %s\n", i, argv[i]);

  /* pointer to first element of array */
  char **p = argv;
  printf("**p = %p\n", p);
  
  /* print pointers to each char * */
  int targc = argc;
  while (targc > 0) {
    printf("*p++ = %s\n", *p++);
    --targc;
  }

  /* iterate by pointer to each char * */
  p = argv;
  targc = argc;
  while (targc > 0) {
    char *s = *p++;
    while (*s != '\0') /* print each char until 0 */
      printf("%c", *s++);
    printf("\n");
    --targc;
  }

  /* iterate by pointer to each char * */
  p = argv;
  while (*p != 0) {
    char *s = *p++;
    while (*s != '\0') /* print each char until 0 */
      printf("%c", *s++);
    printf("\n");
    --targc;
  }

  /* char *argv[] is a variable not an array
   * therefore we can increment it
   */
  while (*argv != 0)
    printf("*argv++ %s\n", *argv++);
  
  return 0;
}

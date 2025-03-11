#include <stdio.h>

int main(int argc, char *argv[])
{
  int (*a)[2];
  int a0[2][2] = {{0, 1}, {2, 3}};
    
  a = a0;

  printf("%d\n", a[0][0]); /* 0 */
  printf("%d\n", a[0][1]); /* 1 */
  printf("%d\n", a[1][0]); /* 2 */
  printf("%d\n", a[1][1]); /* 3 */
  
  printf("%d\n", (*a)[0]); /* 0 */
  printf("%d\n", (*a)[1]); /* 1 */
  printf("%d\n", (*(a + 1))[0]); /* 2 */
  printf("%d\n", (*(a + 1))[1]); /* 3 */

  printf("%d\n", *((*a) + 0)); /* 0 */
  printf("%d\n", *((*a) + 1)); /* 1 */
  printf("%d\n", *((*(a + 1)) + 0)); /* 2 */
  printf("%d\n", *((*(a + 1)) + 1)); /* 3 */
  
  return 0;
}

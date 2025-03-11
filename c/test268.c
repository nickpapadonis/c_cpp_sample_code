#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void *a, const void *b)
{
     const char **a_ = (const char **) a;
     const char **b_ = (const char **) b;
     return strcmp(*a_, *b_);
}

int main(int argc, char *argv[])
{
     int i;
     char **a;
     if (argc < 1)
	  return 1;
     
     int scount = argc - 2;
     
     a = malloc(sizeof(char*) * scount);

     char **ap0 = a;
     char **ap = a;
     char **ap2 = a;
     
     for (i = 1; i < argc; ++i) {
	  *ap0 = malloc(sizeof(char) * strlen(argv[i]) + 1);
	  strcpy(*ap0++, argv[i]);
     }

     qsort(ap, scount, sizeof(*a), &comp) ;

     for (i = 0; i < scount; ++i)
	  printf("%s\n", *ap++);

     char **key = &argv[argc - 1];
          
     char **it = bsearch(key, ap2, scount, sizeof(*ap2), &comp);

     if (it != 0)
	  printf("found: %s\n", *it);

     return 0;
}

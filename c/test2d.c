#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
#define MDA1_R 2
#define MDA1_C 3
     int mda1[MDA1_R][MDA1_C] = {{0, 1, 2}, {3, 4, 5}};
     int mda2[][MDA1_C] = {{0, 1, 2}, {3, 4, 5}};
                            
     for (int r=0; r<MDA1_R; r++) {
          for (int c=0; c<MDA1_C; c++) {
               printf("%d", *((int *) mda1 + MDA1_C * r + c));
          }
     }
     printf("\n");
     
     int (*mda1p)[MDA1_C] = mda1;
     for (int i=0; i<MDA1_R; ++i) {
          for (int j=0; j<MDA1_C; ++j)
               printf("%d", *(*(mda1p + i) + j));
     }
     printf("\n");

#define MDA3_X 2
#define MDA3_Y 2
#define MDA3_Z 2
     int mda3[MDA3_X][MDA3_Y][MDA3_Z] = { {{0, 1}, {2, 3}},
					  {{4, 5}, {6, 7}} };

     for (int i=0; i<MDA3_X; ++i) {
          for (int j=0; j<MDA3_Y; ++j) {
               for (int k=0; k<MDA3_Z; ++k) {
                    printf("%d",
			   *((int *) mda3 +
			     MDA3_Y * MDA3_Z * i + MDA3_Z * j + k));
               }
          }
     }
     printf("\n");


     int (*mda3p)[MDA3_Y][MDA3_Z] = mda3;
     for (int i=0; i<MDA3_X; ++i) {
          for (int j=0; j<MDA3_Y; ++j) {
               for (int k=0; k<MDA3_Z; ++k) {
                    printf("%d", *(*(*(mda3p + i) + j) + k));
               }
          }
     }

     const int r = 2, c = 3;
     int **matrix = (int **) malloc(r * sizeof(int *));
     matrix[0] = (int *) malloc(r * c * sizeof(int));
     
     return 0;
}

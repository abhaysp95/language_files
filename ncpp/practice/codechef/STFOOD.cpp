#include <iostream>
#include <math.h>

int
main(void)
{
  int T = 0;
  scanf("%d", &T);
  while (T--) {
    int row = 0;
    scanf("%d", &row);
    int mat[row][3];
    for (size_t i = 0; i < row; i++)
      for (size_t j = 0; j < 3; j++)
        scanf("%d", &mat[i][j]);
        // scanf("%d", (mat + i)[j]);

    /* for (size_t i = 0; i < row; i++) {
      printf("%d", mat[i][0]);
      for (size_t j = 1; j < 3; j++) {
        printf(", %d", mat[i][j]);
      }
      printf("\n");
    } */

    int maxp = 0;
    for (size_t i = 0; i < row; i++) {
      int np = floor(mat[i][2] / (mat[i][0] + 1));
      if (np == 0) continue;
      int pr = np * mat[i][1];
      maxp = maxp < pr ? pr : maxp;
    }
    printf("%d\n", maxp);
  }
  exit(0);
}

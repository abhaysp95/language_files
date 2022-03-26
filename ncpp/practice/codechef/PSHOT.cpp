#include <stdio.h>
#include <stdbool.h>

char res[(unsigned long)1e9 + 1];

bool get_shot(size_t a, size_t b, size_t left) {
  if (a > b) {
    if (a > (b + left)) {
      return true;
    }
  }
  return false;
}

int
main(void) {
  int T = 0;
  scanf("%d", &T);
  while (T--) {
    size_t N = 0;
    scanf("%zu\n", &N);
    fgets(res, 2*N+1, stdin);
    size_t a = 0, b = 0, i = 0;
    while (i < 2 * N) {
      if (res[i] == '1') a++;
      if (res[i + 1] == '1') b++;
      i+=2;
      size_t left = ((2 * N) - i) / 2;
      if (get_shot(a, b, left) || get_shot(b, a, left)) {
        printf("%zu\n", i);
        continue;
      }
    }
  }
}

/** input:
2
3
101011
3
100001
*/

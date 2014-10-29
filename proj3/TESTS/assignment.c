#include <stdio.h>

int add(int a, int b) {
  int result = a;
  int k = 0;
  while (k<b) {
    result++;
    k++;
  }
  return result;
}

int main(int argc, char **argv) {
  int max, x;
  int sum = 0, y;
  int j, k;
  for (k=1; k<=argc; k++) {
    for (j=1; j<=k; j++) {
      sum = add(sum, 1);
    }
    y = argc;
    x = y + argc;
    x++;
  }
  while (k>0) k--;
  printf("sum: %d\ny: %d\n", sum, y);
}

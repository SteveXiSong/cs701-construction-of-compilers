#include <stdio.h>

int main() {
  int x, y;
  scanf("%d", &x);
  while (x<10) {
    if (x==5) {
      y=x;
    } else {
      y = x*2;
    }
  }
}

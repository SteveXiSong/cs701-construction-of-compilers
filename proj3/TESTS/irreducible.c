#include <stdio.h>

int main() {
  int x, y, a, b;
  scanf("%d", &x);
  scanf("%d", &y);
  if (x>y) {
  L1:
    a = x + y;
    if (x == y*2) goto END;
  L2:
    b = y - x;
    goto L1;
  } else {
    goto L2;
  }
 END:
  return 0;
  
}

#include <stdio.h>

int main() {
  int a, x, y, z;
  scanf("%d", &a);
 H:
  if (a==y) goto DONE;
  scanf("%d", &x);
  if (x==0) {
    scanf("%d", &y);
    if (y==0) goto H;
    else goto T;
  } else {
    scanf("%d", &y);
    if (y == 10) {
      z = 20;
      goto H;
    } else {
      goto T;
    }
  }

 T:
  printf("%d\n", z);
  goto H;

 DONE:
  printf("bye\n");
}

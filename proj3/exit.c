#include <stdio.h>

void foo(char *msg) {
  printf("%s\n", msg);
  exit(1);
}

int main() {
  int x;
  scanf("%d", &x);
  if (x==0) foo("bad input");
  printf("good input\n");
}

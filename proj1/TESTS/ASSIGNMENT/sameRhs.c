#include <stdio.h>

int main() {
  int g1, g2;
  int a, b, c, w, x, y, z;
  scanf("%d", &g1);
  g2 = g1;
  a = g2 + 33;
  scanf("%d", &x);  /* other instruction (in same basic block) */
  b = g2 + 33;      /* redundant */
  scanf("%d", &y);  /* other instruction (in same basic block) */
  c = g2 + 33;      /* redundant */
  scanf("%d", &z);  /* other instruction (in same basic block) */
  g1 = a+b+c;
  printf("g1: %d\ng2: %d\na: %d\nb: %d\nc: %d\n", g1, g2, a, b, c);
}

#include <stdio.h>

int main() {
  int w, x, y, z;
  scanf("%d", &x);
  w = x;
  if (x<0) {
    y = x*2;
    goto L1;
  } else {
    y = x*3;
    goto L1;
  }

 L1: if (x == y) goto L2;  /* Head of loop that DOES have inv exps but NO
			    * preheader
			    */
  
  z = w * 2;   /* LOOP INV */
  y++;
    goto L1;
 L2: return(y);
}

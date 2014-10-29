/* Test that we look for loop-inv instructions in the
   header as well as the body
*/

int main(int argv, char **argc) {
  int x, y, z;
  x = argv;
  y = x+1;
 L:
  z = y+2;  /* INV AND IN LOOP HEADER */
  x++;
  if (x < 5) goto L;
  x++;
  if (x<10) goto L;
}

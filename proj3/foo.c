#include<stdio.h>

/*****************
 *
 *              [1]
 *               |
 *             /   \
 *            [2]  [3]
 *             \    /
 *              [4]
 *               |
 *              [5]------|
 *               |       |
 *              [6]-------
 *               |
 *              [7]
 *
 */

int func(int );

int main(){
    int a = 0, b=1, c=2;
    if( a == 0)
        b += 1; //b=2
    else
        c += 1; //c=3
    a +=1;      //a=2
    while( a-- != 0){
        b --;
    }
    c--;
	return 0;
}

int func(int para){
	if(para > 1)
		para =0;
	else
		para = 1;

	return para;
}

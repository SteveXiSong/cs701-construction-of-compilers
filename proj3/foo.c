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
        while( b != 0){
            c--;
        }
    }

    while(b!=0){
        b--;
        if(b>0)
            continue;
        else
            b+=2;
        c=0;
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

void loopInv(){
    int inv = 0;
    int flag = 1;
    while( flag ){
        inv = 1;
        flag = 0;
    }
    return ;
}

#include<stdio.h>
int main(){
	int a , b, c;
	a = 1;
	c = 3;
	if( 1 ){
		a = 2;
	}else{
		a = 3;	
	}
		b = a;
	while( c!=0 ){
		a = 4;
		if( c >1)
			a = 5;
		else 
			b = a;
	}	
	return 0;
}

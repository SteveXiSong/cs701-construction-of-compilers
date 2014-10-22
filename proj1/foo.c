#include<stdio.h>

int func(int );

int main(){
	int i = 0;
	for(i =0; i< 10; i++)
	{}

	int ret = func(i);
	
	printf("this is test for LLVM (%d) ret(%d)\n", i, ret);
	return 0;
}

int func(int para){
	if(para > 1)
		para =0;	
	else
		para = 1;

	return para;
}

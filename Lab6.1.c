#include <stdio.h>

int main(){
	float num1=7.2, num2=3.1;
	float *fptr = &num1;
	printf("%x\n",fptr);
	printf("%x\n\n\n",*fptr);
	fptr = &num2;
	printf("%p\n",fptr);
	printf("%p\n\n\n",*fptr);
	return 0;
}

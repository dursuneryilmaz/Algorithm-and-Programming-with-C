#include "stdafx.h"
#include <stdio.h>
#include<stddef.h>
int main() {
	int oddNum[10] = { 1,3,5,7,9,11,13,15,17,19}, i;                  //a
	int *iPtr;																  //b
	for (i = 0; i<10; i++) {
		printf("oddNum[%d] = %d\n", i, oddNum[i]);				//c		
	}												
	iPtr = oddNum;										//d
	printf("\n\n");
	for (i = 0; i<10; i++) {
		printf("oddNum[%d]=%d\n",i,*(iPtr+i));					//e		
	}
	printf("\n\n");
	for (i = 0; i<10; i++) {
		printf("oddNum[%d]=%d\n", i, *(oddNum + i));		//f				
	}
	printf("\n\n");
	for (i = 0; i<10; i++) {
		printf("oddNum[%d]=%d\n", i, iPtr[i]);				//g		
	}
	printf("%d\n",*(iPtr+5));							//
	printf("%x\n", &*(iPtr + 5));
	
	iPtr = &oddNum[9];

	printf("%x\n", &*(iPtr - 3));                      //
	printf("%d\n", *(iPtr - 3));
	getchar();
	return 0;
}
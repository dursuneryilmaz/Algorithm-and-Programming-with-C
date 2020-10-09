#include "stdafx.h"

int main(){
	int *zPtr;
	int *aPtr = NULL;
	void *sPtr = NULL;
	int number;
	int z[5] = { 1, 2, 3, 4, 5 };
	sPtr = z;
	
	zPtr= &number;
	++zPtr;
	number = zPtr[2];
	
	for (size_t i = 0; i <=5; ++i) {
	printf("%d", zPtr[i]);
	}

	sPtr = &number;
	
	getchar();
    return 0;
}


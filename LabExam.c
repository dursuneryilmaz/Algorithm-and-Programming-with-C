#include "stdafx.h"
#include <stdio.h> 
#pragma warning(disable: 4996)

struct studentData{
	char name[30];
	char sName[30];
	int age;
};

void printFile();

int main(void)
{
	FILE *fPtr = fopen("test.txt", "w+");
	struct studentData getData;
	int i;
	printf("Please enter name,surname,age:\n");
	for (i = 0; i < 3; i++){
		scanf("%s %s %d", getData.name, getData.sName, &getData.age);
	    fprintf(fPtr,"%s %s %d\n",getData.name,getData.sName,getData.age);
	}
	printf("\n\n");
	fclose(fPtr);

	printFile();

	getchar();
	getchar();
}

void printFile(){
	FILE *getPtr = fopen("test.txt", "r");
	struct studentData printData;
	int i;
	printf("Printing all records:\n");

	while (!feof(getPtr)){
		
		fscanf(getPtr, "%s %s %d\n", printData.name, printData.sName, &printData.age);
		printf("%s %s %d\n", printData.name, printData.sName, printData.age);
	}

	fclose(getPtr);
}

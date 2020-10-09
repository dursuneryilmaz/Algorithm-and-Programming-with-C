#include <stdio.h>

int main (){
	FILE *fPtr = fopen("payables.dat","ab");
    int account ,amount;
    char company;
    
	fprintf(fPtr, "%d%s%d\n", account, company, amount);
	
	fopen("receive.dat", "r+");
	
	FILE *recPtr = fPtr;
	fscanf(recPtr, "%d%s%d\n", &account, company, &amount);
	
	FILE *tfPtr;
	if ((tfPtr = fopen("tools.dat", "r+")) != NULL){
	}
	FILE *cfPtr;
	if ((cfPtr = fopen("courses.dat", "a")) != NULL){
	}
	return 0;
}
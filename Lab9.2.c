#include <stdio.h>

struct studentData{
	char name[20];
	char surName[20];
	int idNum;
	float midMark;
	float finMark;
};

int main (){
	
	FILE *fPtr = fopen("lab9.txt","ab");
	struct studentData stdnt;
		
	int s;
	int offset=3;
		  
    for(s=0; s<5; s++){
    	if(s==0){		
			printf("Please enter student number,name,surname,midterm mark and final exam mark:\n");
		}
		fscanf(stdin,"%d%21s%21s%lf%lf", &stdnt.idNum , stdnt.name , stdnt.surName , &stdnt.midMark , &stdnt.finMark);
   		fwrite(&stdnt,sizeof(struct studentData),1,fPtr);
    }
	
 	int result = fseek(fPtr, (offset - 1) *sizeof(struct studentData),SEEK_SET);
	fread(&stdnt, sizeof(struct studentData), 1, fPtr);
	if(result == 0){
		printf("\n%-15d%-21s%-21s%-10.2f%-10.2f" ,stdnt.idNum , stdnt.name , stdnt.surName , stdnt.midMark , stdnt.finMark);
    }

	fclose(fPtr);
	return 0;
}
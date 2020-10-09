#include "stdafx"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#pragma warning (disable:4996)

struct studentData{
	int idNum;
	char Name[15];
	char sName[15];
	float exGrade;
};
	
void mainManu();					
void newRegister();					
void searchById();				   	
void searchByName();
void updateRegister();
void deleteRegister();
void listRegister();				
void exit();

int main(){	
	FILE *fPtr = fopen("studentlist.txt","ab");
	fclose(fPtr);
	mainManu();
	
	return 0;
}

void mainManu(){
	int choise;
	printf("-----------------------------------------");
	printf("\n\t\tStudent Grade\n\t\tManagment System\n");
	printf("1.New Register\n2.Search by ID Number\n3.Search by Name\n4.Update a Resgiter\n5.Delete a Resgiter\n6.List Resgiter\n7.Exit\n");
	printf("-----------------------------------------\n");
	printf("Please select a process:");
		
	scanf("%20d",&choise);
	switch(choise){
		case 1:
			newRegister();
			break;
		case 2:
			searchById();
			break;
		case 3:
			searchByName();
			break;
		case 4:
			updateRegister();
			break;
		case 5:
			deleteRegister();
			break;
		case 6:
			listRegister();
			break;
		case 7:
			printf("Exited successfully!!");
			break;
		default:
			printf("Please select a exist process!!");
			break;	
		}
}

void newRegister(){
	r_add:
    FILE *fPtr = fopen("studentlist.txt","ab");
    struct studentData newStdnt;
    
	printf("\n-----------------------------------------\n");
    printf("ID Number::");
    scanf("%20d",&newStdnt.idNum);
	printf("Name::");
    scanf("%15s",newStdnt.Name);
    printf("Surname::");
    scanf("%15s",newStdnt.sName);
    printf("Grade:");
    scanf("%f",&newStdnt.exGrade);

	fwrite(&newStdnt,sizeof(struct studentData),1,fPtr);
	
	fclose(fPtr);
	
	int add;
	printf("\nRegister added succesfully...\nAdd(1) or BackToMainmanu(2) Exit(0):");
	scanf("%20d",&add);
	
	if(add == 1 ){
		goto r_add;
	}
	if(add == 2){
		system("cls");
		mainManu();	
	}
}

void searchById(){
	new_search:
	FILE *fPtr = fopen("studentlist.txt","r");
	struct studentData idStdnt;
	
	int number;
	printf("-----------------------------------------\n");	
	printf("Enter the idnumber for search:");
	scanf("%20d",&number);
	
	while(!feof(fPtr)){
		fread(&idStdnt, sizeof(struct studentData), 1, fPtr);
			if(idStdnt.idNum == number){
				printf("-----------------------------------------\n");	
				printf("\n%-12s%-12s%-12s%-10s\n","Number","Name","Surname","Grade");
				printf("%-12d%-12s%-12s%-10.2f%\n" ,idStdnt.idNum , idStdnt.Name , idStdnt.sName , idStdnt.exGrade);
				printf("-----------------------------------------\n");	
				printf("Founded successufully!!");
			}
			else{
				goto new_search;
			}
	}
	fclose(fPtr);
	
	int add;
	printf("\nSearch(1) or BackToMainmanu(2) Exit(0):");
	scanf("%20d",&add);
	
	if(add == 1 ){
		goto new_search;
	}
	if(add == 2){
		system("cls");
		mainManu();	
	}
}

void searchByName(){
	new_search2:
	FILE *fPtr = fopen("studentlist.txt","r");	
	struct studentData nameStdnt;
	
	char findName[15];
	printf("-----------------------------------------\n");
	printf("Enter a name for search client:");
	scanf("%15s",findName);


	 while(!feof(fPtr)){ 
		fread(&nameStdnt, sizeof(struct studentData), 1, fPtr);
		if( strcmp(nameStdnt.Name,findName) == 0){
			printf("\n%-12s%-12s%-12s%-10s\n","Number","Name","Surname","Grade");
			printf("%-12d%-12s%-12s%-10.2f%\n" ,nameStdnt.idNum , nameStdnt.Name , nameStdnt.sName , nameStdnt.exGrade);
			printf("-----------------------------------------\n");	
			printf("Founded successufully!!");
		}
		else{
			goto new_search2;
		}
	}
	
	fclose(fPtr);
	
	int add;
	printf("\nRegister added succesfully...\nAdd(1) or BackToMainmanu(2) Exit(0):");
	scanf("%20d",&add);
	
	if(add == 1 ){
		goto new_search2;
	}
	if(add == 2){
		system("cls");
		mainManu();	
	}
}

void updateRegister(){
	r_update:
	FILE *fPtr = fopen("studentlist.txt","ab+");
	FILE *upPtr = fopen("studentlist1.txt","w+");	
	struct studentData updateStdnt;
	
	printf("-----------------------------------------\n");
	printf("41.Update with id\n42.Update with name / surname\n");
	int up_choise;
	printf("\nPlease select a methot:");
	scanf("%20d",&up_choise);
	printf("-----------------------------------------\n");
	switch(up_choise){
		case 41:
			printf("Enter the idnumber for update:");
			int id;
			scanf("%20d",&id);
	
			while(!feof(fPtr)){ 
				fread(&updateStdnt, sizeof(struct studentData), 1, fPtr);
				if(updateStdnt.idNum == id){
					printf("\n%-12s%-12s%-12s%-10s\n","Number","Name","Surname","Grade");
					printf("%-12d%-12s%-12s%-10.2f%\n" ,updateStdnt.idNum , updateStdnt.Name , updateStdnt.sName , updateStdnt.exGrade);
					
					printf("-----------------------------------------\n");
					printf("Updated ID Number::");
					scanf("%20d",&updateStdnt.idNum);
					printf("Updated Name::");
					scanf("%15s",updateStdnt.Name);
					printf("Updated Surname::");
					scanf("%15s",updateStdnt.sName);
					printf("Updated Grade:");
					scanf("%f",&updateStdnt.exGrade);
					printf("\n\n");
				}
			fwrite(&updateStdnt,sizeof(struct studentData),1,upPtr);	
			}
			break;
		case 42:
			printf("Enter a name or surname for update:");
			char f_name[15];
			scanf("%15s",&f_name);
	
			while(!feof(fPtr)){ 
				fread(&updateStdnt, sizeof(struct studentData), 1, fPtr);
				if(strcmp(updateStdnt.Name,f_name) == 0 || strcmp(updateStdnt.sName,f_name)== 0) {
					printf("\n%-12s%-12s%-12s%-10s\n","Number","Name","Surname","Grade");
					printf("%-12d%-12s%-12s%-10.2f%\n" ,updateStdnt.idNum , updateStdnt.Name , updateStdnt.sName , updateStdnt.exGrade);
						
					printf("-----------------------------------------\n");
					printf("Updated ID Number::");
					scanf("%20d",&updateStdnt.idNum);
					printf("Updated Name::");
					scanf("%15s",updateStdnt.Name);
					printf("Updated Surname::");
					scanf("%15s",updateStdnt.sName);
					printf("Updated Grade:");
					scanf("%f",&updateStdnt.exGrade);
					printf("\n\n");
				}
				fwrite(&updateStdnt,sizeof(struct studentData),1,upPtr);
			}
			break;
		default:
			printf("Please select a exist process!!");
			goto r_update;	
			break;		
	}				
	fclose(fPtr);
	fclose(upPtr);
	
	remove("studentlist.txt");
	rename("studentlist1.txt","studentlist.txt");

	int add;
		printf("\nRegister updated succesfully...\nUpdate(1) or BackToMainmanu(2) Exit(0):");
		scanf("%20d",&add);
	if(add == 1 ){
		goto r_update;
	}
	if(add == 2){
		system("cls");
		mainManu();	
	}
}

void deleteRegister(){
	r_delete:
	FILE *fPtr = fopen("studentlist.txt","ab");
	FILE *delPtr = fopen("studentlist1.txt","w+");	
	struct studentData deleteStdnt;
	
	printf("-----------------------------------------\n");
	printf("51.Delete with id\n52.Delete with name / surname\n");
	int up_choise;
	printf("\nPlease select a methot:");
	scanf("%20d",&up_choise);
	printf("-----------------------------------------\n");
	switch(up_choise){
		case 51:
			printf("Enter the idnumber for delete:");
			int id;
			scanf("%20d",&id);
	
			while(!feof(fPtr)){ 
				fread(&deleteStdnt, sizeof(struct studentData), 1, fPtr);
				if(deleteStdnt.idNum == id){
					printf("\n%-12s%-12s%-12s%-10s\n","Number","Name","Surname","Grade");
					printf("%-12d%-12s%-12s%-10.2f%\n" ,deleteStdnt.idNum , deleteStdnt.Name , deleteStdnt.sName , deleteStdnt.exGrade);
					fread(&deleteStdnt, sizeof(struct studentData), 1, fPtr);	
				}
			fwrite(&deleteStdnt,sizeof(struct studentData),1,delPtr);
			}
			break;
		case 52:
			printf("Enter a name or surname for update:");
			char f_name[15];
			scanf("%15s",&f_name);
	
			while(!feof(fPtr)){ 
				fread(&deleteStdnt, sizeof(struct studentData), 1, fPtr);
				if(strcmp(deleteStdnt.Name,f_name) == 0 || strcmp(deleteStdnt.sName,f_name)== 0) {
					printf("\n%-12s%-12s%-12s%-10s\n","Number","Name","Surname","Grade");
					printf("%-12d%-12s%-12s%-10.2f%\n" ,deleteStdnt.idNum , deleteStdnt.Name , deleteStdnt.sName , deleteStdnt.exGrade);
					fread(&deleteStdnt, sizeof(struct studentData), 1, fPtr);
				}
			fwrite(&deleteStdnt,sizeof(struct studentData),1,delPtr);
			}
			break;
		default:
			printf("Please select a exist process!!");
			goto r_delete;	
			break;		
	}				
	fclose(fPtr);
	fclose(delPtr);
	
	remove("studentlist.txt");
	rename("studentlist1.txt","studentlist.txt");

	int add;
		printf("\nRegister updated succesfully...\nUpdate(1) or BackToMainmanu(2) Exit(0):");
		scanf("%20d",&add);
	if(add == 1 ){
		goto r_delete;
	}
	if(add == 2){
		system("cls");
		mainManu();	
	}
}

void listRegister(){
	new_list:
	FILE *fPtr = fopen("studentlist.txt","r");
	struct studentData listStdnt;
	
	printf("-----------------------------------------\n");
	printf("\n%-12s%-12s%-12s%-10s\n","Number","Name","Surname","Grade");	
	
	while(!feof(fPtr)){ 
		fread(&listStdnt, sizeof(struct studentData), 1, fPtr);
		printf("%-12d%-12s%-12s%-10.2f%\n" ,listStdnt.idNum , listStdnt.Name , listStdnt.sName , listStdnt.exGrade);	
		//fseek(fPtr, -1 *sizeof(struct studentData),SEEK_END);
		//long ftell(FILE *fPtr);
	}
	fclose(fPtr);
	
	int add;
	printf("\nAgain(1) or BackToMainmanu(2) Exit(0):");
	scanf("%20d",&add);
	
	if(add == 1 ){
		goto new_list;
	}
	if(add == 2){
		system("cls");
		mainManu();	
	}		
}
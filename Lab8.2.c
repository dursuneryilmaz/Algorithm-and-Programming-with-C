#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	char strings[5][30]={};
	char findThat[5]= "tion";
	
	int i,j,a=0;
	int x[5];
	for(i=0;i<5;i++){
		printf("### Enter a string: ");
		for(j=0;j<1;j++){
			scanf("%29s",&strings[i][0]);
			x[i]=strlen(strings[i])-4;
		}	
	}

	printf("The strings ending with \"tion\";\n");
	for(i=0;i<5;i++){
		if(strcmp(&strings[i][x[i]],"tion") == 0){
			printf("%s\n",strings[i]);
		}
	}
	return 0;
}
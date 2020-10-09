#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	
	char s[10];
	strncpy(s,"hello",5);
	printf("%s\n",s);

	printf("%c",'a');

	char c[12];
	strncpy(c,"welcome home",12);

	if(strcmp(s,c) == 0){
		puts("the strings are equal");
	}
	return 0;
}

	
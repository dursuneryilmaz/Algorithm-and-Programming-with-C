#include <stdio.h>
#include <conio.h>
#include <string.h>

int lengthOfString(char *s);
int main(){
	char s[100];
	int Size_t;
	printf("Enter a string: ");
	gets(s);

	Size_t = lengthOfString(s);

	printf("Size of the entered string is: %d", Size_t);

	_getch();
	return 0;
}

int lengthOfString(char *s){
	int length = 0;
	while (s[length] != '\0'){
		length++;
	}
	return length;
}





	
	



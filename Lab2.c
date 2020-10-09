#include <stdio.h>

 int main () {
 	int number, i, remainder , aliquat=0;
 	printf("Enter a number\n");
 	scanf("%d",&number);
 	
 	if(number>0){
		if(number != 1){
			for(i=2 ; i<number ; i++ ){
			remainder=number%i;
				if(remainder==0){
				aliquat++;		
				}
				else{
	
				}
			}
	
			if(aliquat==0)
				printf("%d is Prime\n",number);
	
			else	
				printf("%d is not Prime\n",number); 
		}
		else{
			printf("%d is not prime\n",number);
		}
 	}
 	else{
 	    printf("%d is not prime\n",number);
 	}
    return 0;
}

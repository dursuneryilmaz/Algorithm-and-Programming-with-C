#include <stdio.h>

int main(){
    double cel=30,fah;
    printf("Celsius\tFahreneit\n") ;
       for(cel=30 ; cel<=50 ; cel++){
			fah = ((1.8)*cel)+32;
			printf("%.2f\t%.2f\n",cel,fah);
       }
	return 0;
}

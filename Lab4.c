#include <stdio.h>

int main(){

    int c,i,a=1;
    double cost,day,sum_hour=0,sum_cost=0;
    printf("Please enter the number of cars:");
    scanf("%d",&c);
    int array[c];
    printf("Enter the hour of rented %d cars:",c);

    for(i=0 ; i<c ; i++){
        scanf("%d",&array[i]);
	}
    printf("Car\tHour\tCharge\n");

    for(i=0 ; i<c ; i++){

        if(array[i]<=8){
        cost=25+array[i]*(0.50);
		}
        if(array[i]>8){
         cost=25+(array[i])*(0.50)+(array[i]-7)*5;
		}
        if(array[i]==24){
         cost=(50*a)+(array[i]*0.50);
		}
        if(array[i]>24){
        day = (array[i])/24;
            if(day>=1){
              a=2;
            }
            if(day>2){
              a=3;
            }
         cost=(50*a)+(array[i]*0.50);
		}
    printf("%d\t%d\t%.2f\n",i+1,array[i],cost);
    sum_hour=sum_hour+array[i];
    sum_cost=sum_cost+cost;
	}
    printf("TOTAL\t%.1f\t%.2f\n",sum_hour,sum_cost);
	return 0;
}

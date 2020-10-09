#include <stdio.h>
#include <stdlib.h>

int main(){

    int row,col,row2,col2,i,j,k,sonuc;
    printf("Enter the number of rows for the first matrix:");
    scanf("%d",&row);
    printf("Enter the number of columns for the first matrix:");
    scanf("%d",&col);

    printf("\n\n");

    printf("Enter the number of rows for the second matrix:");
    scanf("%d",&row2);
    printf("Enter the number of columns for the second matrix:");
    scanf("%d",&col2);

    int mat[row][col],mat2[row2][col2],result[row][col2]={0};
    
	if(col==row2){
		printf("\nEnter the element of first matrix\n");
		for(i=0 ; i<row ; i++){
			for(j=0 ; j<col ; j++){
				printf("Enter element [%d][%d] : ",i,j);
				scanf("%d",&mat[i][j]);
			}
		}

		printf("\nEnter the element of second matrix\n");
		for(i=0 ; i<row2 ; i++){
			for(j=0 ; j<col2 ; j++){
				printf("Enter element [%d][%d] : ",i,j);
				scanf("%d",&mat2[i][j]);
			}
		}
		printf("\n\n");

		for(i=0 ; i<row ; i++){
			for(j=0; j<col2 ; j++){
				for(k=0 ; k<col ; k++){
					result[i][j]+= ((mat[i][k]) * (mat2[k][j]));  
				}
			}
		}
	
		printf("\n\n");
		printf("\nResult matrix is\n");
		for(i=0 ; i<row ; i++){
			for(j=0 ; j<col2 ; j++){
				printf("%d\t",result[i][j]);
			}
            printf("\n");
		}	
	}
	else{
		printf("\nThis two matris cannot product...");
	}
	return 0;
}

#include <stdio.h>

#define L 10 

void main(){
	int sm[L][L];
	//Matrix sm has to be inputed , the user has to enter rows and columns , after user has to input elemets to index based on above said rows and columns
	printf("Enter Number of rows and columns : ");
	int r , c;
	scanf("%d %d",&r,&c);
	printf("Enter the matrix : \n");
	
	//read the Matrix by index based on [row][column]
	for(int i=0 ; i<r ; i++){
		for(int j=0 ; j<c ; j++){
			scanf("%d",&sm[i][j]);
		}
	}
	
	//create a triplet matrix of maximum rows of L^2
	int tr[L*L][3];
	
	//variable to find number of non-zero values
	int count = 0;
	
	//variable to keep track of index of triplet matrix
	int k=1;
	
	
	tr[0][0] = r;
	tr[0][1] = c;
	
	//This loop iterates through every elemet of sm and then assign non-zero elemets and their indexes to the triplet 
	for(int i=0 ; i<r ; i++){
		for(int j=0 ; j<c ; j++){
			if(sm[i][j] != 0){
				tr[k][0] = i;
				tr[k][1] = j;
				tr[k][2] = sm[i][j];
				k++;
				count++;			
			}
		}	
	}
	
	
	
	printf("Triple representation \n");
	printf("%d\t%d\t%d\n",tr[0][0],tr[0][1],count);
	for(int i=1 ; i<=count ; i++){
		for(int j=0 ; j<3 ; j++){
			printf("%d\t",tr[i][j]);
		}
		printf("\n");
	}
	
	
}

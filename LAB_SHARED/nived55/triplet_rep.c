#include <stdio.h>

#define L 10 

void main(){
	int sm[L][L];
	
	printf("Enter Number of rows and columns : ");
	int r , c;
	scanf("%d %d",&r,&c);
	printf("Enter the matrix : \n");
	

	for(int i=0 ; i<r ; i++){
		for(int j=0 ; j<c ; j++){
			scanf("%d",&sm[i][j]);
		}
	}

	int tr[L*L][3];

	int count = 0;

	int k=1;
	
	
	tr[0][0] = r;
	tr[0][1] = c;
	
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

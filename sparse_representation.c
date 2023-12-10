#include <stdio.h>

int generateSparse(int arr[m][n] , int m , int
    int k=1;  

    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            scanf("%d" , &SM[i][j]);
        }
    }
}

void main(){

    int m,n;

    printf("Enter the row and column of the matrix : ");
    scanf("%d%d" , &m , &n);

    int SM[m][n]

    printf("Enter the matrix : \n");
    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            scanf("%d" , &SM[i][j]);
        }
    }

    int triplet_size = generateSparse(SM , m , n);


}
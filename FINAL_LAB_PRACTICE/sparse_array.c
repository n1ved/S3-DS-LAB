#include <stdio.h>

void main(){
    int m , n;
    printf("Enter order of matrix : ");
    scanf("%d%d",&m,&n);
    int sm[m][n];
    printf("Enter Sparse Matrix :\n");
    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            scanf("%d" , &sm[i][j]);
        }
    }

    int tr[(m*n)/3][3];

    tr[0][0] = m;
    tr[0][1] = n;

    int x = 0;

    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            if(sm[i][j] != 0){
                x++;
                tr[x][0] = i;
                tr[x][1] = j;
                tr[x][2] = sm[i][j];
            }
        }
    }

    tr[0][2] = x;

    for(int i=0 ; i<=x ; i++){
        for(int j=0 ; j<3 ; j++){
            printf("%d\t",tr[i][j]);
        }
        printf("\n");
    }
}
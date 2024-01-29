// PSEUDOCODE
/*
    PROGRAM POLYREP
    STRUCT POLY
        DECLARE INTEGER COEF
        DECLARE INTEGER EXP
    END STRUCT
    PROCEDURE MAIN
        DECLARE ARRAY OF POLY NEWPOLY
        INPUT SIZE N
        FOR I FROM 0 TO N
            INPUT I th COEF OF NEWPOLY
            INPUT I th EXP OF NEWPOLY
        ENDFOR
        FOR I FROM 0 TO N-1
            PRINT (NEWPOLY[I].COEF)x^(NEWPOLY[I].EXP)+
        ENDFOR
        PRINT (NEWPOLY[N-1].COEF)x^(NEWPOLY[N-1].EXP)
    END PROCEDURE
    END PROGRAM
*/


#include <stdio.h>

struct poly{
    int coef;
    int exp;
};

void main(){
    struct poly newPoly[10];
    int n;
    printf("Enter number of terms in polynomial : ");
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++){
        printf("Enter term coefficent : ");
        scanf("%d",&newPoly[i].coef);
        printf("Enter term exponent : ");
        scanf("%d",&newPoly[i].exp);
    }
    for(int i=0 ; i<n-1 ; i++){
        printf("%dx^%d+",newPoly[i].coef , newPoly[i].exp);
    }
    printf("%dx^%d\n",newPoly[n-1].coef , newPoly[n-1].exp);
}
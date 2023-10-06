#include <stdio.h>

struct poly{
    int coef;
    int exp;
};

int readPoly(struct poly p[10]){
    int n;
    printf("Enter the number of terms : ");
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++){
        printf("Enter Exponent : ");
        scanf("%d" , &p[i].exp);
        printf("Enter Coeffcient : ");
        scanf("%d" , &p[i].coef);
    }
    return n;
}

void printPoly(struct poly p[10] , int n){
    printf("%dx^%d" , p[0].coef , p[0].exp);
    for(int i=1 ; i<n ; i++)
        printf(" + %dx^%d" , p[i].coef , p[i].exp);
    printf("\n");
}

void addPoly(struct poly p1[10] , struct poly p2[10] , int s1 , int s2 ){
    struct poly p3[20];
    int i=0 , j =0 , k= 0;

    while(i<s1 && j<s2){
        if(p1[i].exp == p2[j].exp){
            p3[k].exp = p1[i].exp;
            p3[k].coef = p1[i].coef + p2[j].coef;
            i++;
            j++;
            k++;
        }
        else if(p1[i].exp >= p2[j].exp){
            p3[k].exp = p1[i].exp;
            p3[k].coef = p1[i].coef;
            i++;
            k++;
        }
        else{
            p3[k].exp = p2[j].exp;
            p3[k].coef = p2[j].coef;
            j++;
            k++;
        }
    }
    while(i<s1){
        p3[k].exp = p1[i].exp;
        p3[k].coef = p1[i].coef;
        i++;
        k++;
    }

    while(j<s2){
        p3[k].exp = p2[j].exp;
        p3[k].coef = p2[j].coef;
        j++;
        k++;
    }

    printPoly(p3 , k);
}

void main(){
    struct poly p1[10] , p2[10];
    int s1 = readPoly(p1);
    int s2 = readPoly(p2);
    addPoly(p1,p2,s1,s2);
}
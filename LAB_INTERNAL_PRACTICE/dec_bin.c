// Program to convert decimal to binary using stack

#include <stdio.h>
#define SIZE 50

int stack[SIZE];
int top = -1;

void convert (int n){
    while(n>0){
        top++;
        stack[top] = n%2;
        n /=2 ;
    }
}

void printBin(){
    for(int i=top ; i>=0 ; i--){
        printf("%d",stack[i]);
    }
    printf("\n");
}

void main(){
    int n;
    printf("Enter the number : ");
    scanf("%d",&n);
    convert(n);
    printBin();
} 
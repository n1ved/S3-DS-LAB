// Program to find LCM and HCF of two given numbers 
#include <stdio.h>
#define SIZE 50

int stackOne[SIZE];
int stackTwo[SIZE];
int topO=-1;
int topT=-1;

void push(int n,int x){
    if(x == 1){
        topO++;
        stackOne[topO] = n;
    }
    else{
        topT++;
        stackTwo[topT] = n;
    }
}

void findFactor(int n , int x){
    for(int i=1 ; i<=n ; i++){
        if(n%i == 0){
            push(i,x);
        }
    }
}
int findCommonFactor(){
    while(topO > -1 && topT > -1){
        if(stackOne[topO] == stackTwo[topT])
            return stackOne[topO];
        else{
            stackOne[topO] < stackTwo[topT] ? topT-- : topO--;
        }
    }
    return 1;
}

void main(){
    int a , b;
    printf("Enter two numbers : ");
    scanf("%d%d",&a,&b);
    findFactor(a,1);
    findFactor(b,2);
    int hcf = findCommonFactor();
    printf("%d\n" , hcf);
    printf("%d\n" , a*b/hcf);
}
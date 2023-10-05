#include <stdio.h>
#define SIZE 100

void repeatedElements(int array[] , int n){
    int counter;

    for(int i=0 ; i<n ; i++){

        counter = 0;
        for(int j=0 ; j<n ; j++){
            if(array[i] == array[j]){
                if(j<i)
                    break;
                counter++;
            } 
        }

        if(counter > 1)
            printf("Element %d repeated %d times\n" , array[i] ,counter);
    }
}


void main(){
    int array[SIZE] , n;
    printf("Enter size of array : ");
    scanf("%d" , &n);
    printf("Enter array : ");
    for(int i=0 ; i<n ;i++)
        scanf("%d" , &array[i]);
    
    repeatedElements(array , n);
}
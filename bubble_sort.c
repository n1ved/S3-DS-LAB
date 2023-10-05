#include <stdio.h>
#define SIZE 100

void bubbleSort(int array[] , int n){
    int _temp;
    for(int i=0 ; i<n-1 ; i++){
        for(int j=0 ; j<n-i-1 ; j++){
            if(array[j] > array[j+1]){
                _temp = array[j];
                array[j] = array[j+1];
                array[j+1] = _temp;      
            }
        }
    }
}

void main(){
    int array[SIZE] , n;
    printf("Enter size of array : ");
    scanf("%d" , &n);
    printf("Enter array : ");
    for(int i=0 ; i<n ;i++)
        scanf("%d" , &array[i]);

    bubbleSort(array , n);

    for(int i=0 ; i<n ;i++)
        printf("%d " , array[i]);

    printf("\n");
}
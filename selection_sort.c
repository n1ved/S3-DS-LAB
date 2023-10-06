#include <stdio.h>
#define SIZE 100


void selectionSort(int array[] , int n){
    int _temp , min;
    for(int i=0 ; i<n-1 ; i++){
        min = i;
        for(int j=i+1 ; j<n ; j++){
            if(array[min] > array[j]){
                _temp = array[min];
                array[min] = array[j];
                array[j] = _temp;
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

    selectionSort(array , n);

    for(int i=0 ; i<n ;i++)
        printf("%d " , array[i]);

    printf("\n");
}
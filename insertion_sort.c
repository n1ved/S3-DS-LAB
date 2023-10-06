#include <stdio.h>
#define SIZE 100

void insertionSort(int array[] , int n){
    int key , j;
    for(int i=1 ; i<n ;i++){
        key = array[i];
        j = i - 1;
        while(j>=0 && array[j] > key){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}

void main(){
    int array[SIZE] , n;
    printf("Enter size of array : ");
    scanf("%d" , &n);
    printf("Enter array : ");
    for(int i=0 ; i<n ;i++)
        scanf("%d" , &array[i]);

    insertionSort(array , n);

    for(int i=0 ; i<n ;i++)
        printf("%d " , array[i]);

    printf("\n");
}
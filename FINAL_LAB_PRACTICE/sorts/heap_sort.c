#include <stdio.h>

void heapify(int arr[] , int size , int key){

    int largest = key ;

    int left  = 2*key + 1;
    int right = 2*key + 2;

    if(left < size && arr[left] > arr[largest])
        largest = left;

    if(right < size && arr[right] > arr[largest])
        largest = left;

    if(largest != key){
        int temp = arr[key];
        arr[key] = arr[largest];
        arr[largest] = temp;
        heapify(arr , size , largest);
    }
}

void heapSort(int arr[] , int size){
    for(int i=size/2 -1 ; i>=0 ; i--){
        heapify(arr , size , i);
    }

    for(int i=size-1 ; i>= 0 ; i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp; 
    }
}

void main(){
    int size;
    scanf("%d",&size);
    int arr[size];
    for(int i=0 ; i<size ; i++){
        scanf("%d",&arr[i]);
    }
    heapSort(arr , size);
    for(int i=0 ; i<size ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
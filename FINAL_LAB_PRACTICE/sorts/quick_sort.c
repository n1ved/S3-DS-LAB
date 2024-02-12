#include <stdio.h>

int partition(int arr[] , int low , int high){
    int pivot = arr[high];
    int i= low - 1;
    for(int j=low ; j<=high ; j++){
        if(arr[j] < pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return i+1;
}

void quickSort(int arr[] , int low , int high){
        if(low < high){
            int part = partition(arr , low , high);
            quickSort(arr , low ,part - 1);
            quickSort(arr , part+1 , high);
        }
}

void main(){
    int size;
    scanf("%d",&size);
    int arr[size];
    for(int i=0 ; i<size ; i++){
        scanf("%d",&arr[i]);
    }
    quickSort(arr , 0 , size-1);
    for(int i=0 ; i<size ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
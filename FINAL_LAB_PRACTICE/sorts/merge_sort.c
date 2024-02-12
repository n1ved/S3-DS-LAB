#include <stdio.h>

void merge(int arr[] , int low , int mid , int high){
    int i=low;
    int j=mid+1;
    int k=0;
    int newArr[high-low+1];

    while(i <= mid && j <= high){
        if(arr[i] <= arr[j]){
            newArr[k] = arr[i];
            i++;
            k++;
        }
        else{
            newArr[k] = arr[j];
            j++;
            k++; 
        }
    }

    while(i<=mid){
        newArr[k] = arr[i];
        i++;
        k++;
    }

    while(j<=high){
        newArr[k] = arr[j];
        j++;
        k++; 
    }

    for(int i=low ; i<=high ; i++){
        arr[i] = newArr[i-low];
    }
}


void mergeSort(int arr[] , int low , int high){
    if(low < high){
        int mid = (low + high) / 2;

        mergeSort(arr , low , mid);
        mergeSort(arr , mid+1 , high);

        merge(arr , low , mid , high);
    }
}

void main(){
    int size;
    scanf("%d",&size);
    int arr[size];
    for(int i=0 ; i<size ; i++){
        scanf("%d",&arr[i]);
    }
    mergeSort(arr , 0 , size-1);
    for(int i=0 ; i<size ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
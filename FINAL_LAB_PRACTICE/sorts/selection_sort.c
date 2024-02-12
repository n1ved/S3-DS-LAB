#include <stdio.h>
#define MAX_SIZE 10

void sort(int arr[] , int n){
    for(int i=0 ; i<n ; i++){
        for(int j=i+1 ; j<n ; j++){
            if(arr[j] < arr[i]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

void main(){
    int arr[MAX_SIZE];
    int n;
    scanf("%d" , &n);
    for(int i=0 ; i<n ; i++)
        scanf("%d" , &arr[i]);

    sort(arr , n);

    for(int i=0 ; i<n ; i++)
        printf("%d " , arr[i]);

    printf("\n");
}
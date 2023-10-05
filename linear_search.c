#include <stdio.h>
#define SIZE 100

int linearSearch(int array[] , int n , int key){
    for(int i=0 ; i<n ;i++){
        if(array[i] == key)
            return i;
    }
    return -1;
}

void main(){
    int array[SIZE] , n , key;
    printf("Enter size of array : ");
    scanf("%d" , &n);
    printf("Enter array : ");
    for(int i=0 ; i<n ;i++)
        scanf("%d" , &array[i]);
    printf("Enter search key : ");
    scanf("%d" , &key);

    int pos = linearSearch(array, n , key);

    if(pos != -1)
        printf("Element found at %d\n",pos);
    else
        printf("Element not found\n");
}
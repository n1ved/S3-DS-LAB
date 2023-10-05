#include <stdio.h>
#define SIZE 100

int binarySearch(int array[] , int n , int key){
    int l = 0 , h = n-1 ,m;
    while(l<=h){
        m = (l+h)/2;
        if(array[m] == key)
            return m;
        else if(array[m] > key)
            h = m-1;
        else
            l = m+1;
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

    int pos = binarySearch(array, n , key);

    if(pos != -1)
        printf("Element found at %d\n",pos);
    else
        printf("Element not found\n");
}
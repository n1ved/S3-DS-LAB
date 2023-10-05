#include <stdio.h>
#define SIZE 100

void twoLargest(int array[] , int n){
    int l   = array[0];
    int sl  = array[0];

    for(int i=0 ; i<n ; i++){
        if(array[i]>l)
            l=array[i];
        else
            sl=array[i];
    }
     for(int i=0 ; i<n ; i++){
        if(array[i]>sl && array[i]<l)
            sl=array[i];
    }

    printf("%d %d \n" , l , sl);

}

void main(){
    int array[SIZE] , n;
    printf("Enter size of array : ");
    scanf("%d" , &n);
    printf("Enter array : ");
    for(int i=0 ; i<n ;i++)
        scanf("%d" , &array[i]);
    
    twoLargest(array , n);
}
#include <stdio.h>
#define SIZE 100

void printArray(int array[] , int n){
	for(int i=0 ; i<n ; i++)
		printf("%d " , array[i]);
	printf("\n");	
}

void selectionSort(int array[] ,int n){
	int min , temp;
	for(int i=0 ; i<n-1 ; i++){
		min = i;
		for(int j=i+1 ; j<n ; j++){
			if(array[min] > array[j]){
				temp = array[min];
				array[min] = array[j];
				array[j] = temp;
			}
			// printArray(array , n);
		}
		
	}
}

void main(){
	int array[SIZE] , n;
	printf("Enter size of array : ");
	scanf("%d" , &n);
	printf("Enter the array : ");
	for(int i=0 ; i<n ; i++)
		scanf("%d" , &array[i]);
	
	selectionSort(array , n);
	
	for(int i=0 ; i<n ; i++)
		printf("%d " , array[i]);
	printf("\n");

}

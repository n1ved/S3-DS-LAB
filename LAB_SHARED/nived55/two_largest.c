#include <stdio.h>
#define SIZE 100

void main(){
	int arr[SIZE] , n;
	printf("Enter size of array : ");
	scanf("%d",&n);
	printf("Enter the array : ");
	for(int i=0 ; i<n ; i++){
		scanf("%d",&arr[i]);
	}
	
	int largest = arr[0];
	int slargest = arr[0] ;
	
	for(int i=0 ; i<n ; i++){
		if(arr[i] > largest){
			largest = arr[i];
		}
		else
			slargest = arr[i];
	}
	for(int i=0 ; i<n ; i++){
		if(arr[i] > slargest && arr[i] < largest){
			slargest = arr[i];
		}
	}
	
	
	
	printf("%d %d\n", largest , slargest);
	
}

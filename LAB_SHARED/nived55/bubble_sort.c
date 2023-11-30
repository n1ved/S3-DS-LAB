#include <stdio.h>
#define SIZE 100
void main(){
	int arr[SIZE] , n , temp;
	printf("Enter size of array : ");
	scanf("%d", &n);
	printf("Enter the array : ");
	for(int i=0; i<n ; i++)
		scanf("%d" , &arr[i]);
	for(int i=0; i<n-1 ; i++){
		for(int j=0 ; j<n-i-1 ;j++){
			if(arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	for(int i=0; i<n ; i++)
		printf("%d " , arr[i]);
	printf("\n");
}

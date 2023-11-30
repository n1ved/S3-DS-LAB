#include <stdio.h>
#define SIZE 100

void main(){
	int arr[SIZE] , key , n;
	printf("Enter size of array : ");
	scanf("%d",&n);
	printf("Enter the array : ");
	for(int i=0 ; i<n ; i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter search key : ");
	scanf("%d",&key);
	int flag = -1;
	for(int i=0 ; i<n ; i++){
		if(arr[i] == key){
			flag = i;
			break;
		}
	}
	
	flag != -1 ? printf("Element found at position %d\n",flag) : printf("Element not found\n");
}

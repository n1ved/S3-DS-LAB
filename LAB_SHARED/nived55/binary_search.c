#include <stdio.h>
#define SIZE 100
void main(){
	int arr[SIZE] , key , n;
	printf("Enter size of array : ");
	scanf("%d",&n);
	int l=0 , h=n-1 , mid;
	printf("Enter the array : ");
	for(int i=0 ; i<n ; i++)
		scanf("%d",&arr[i]);
	printf("Enter the search key : ");
	scanf("%d",&key);
	int flag = -1;
	while(l<=h){
		mid = (l+h)/2;
		if(arr[mid] == key){
			flag = mid;
			break;
		}
		else if(arr[mid]<key){
			l = mid+1;
		}
		else{ 
			h=mid-1;
		}
	}
	
	if(flag != -1)
		printf("Element found at position %d\n",flag);
	else
		printf("Element not found\n");
}

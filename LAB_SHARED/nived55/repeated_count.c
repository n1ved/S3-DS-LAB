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
	int count;
	for(int i=0 ; i<n ; i++){
		count = 0;
		for(int j =0 ; j<n ;j++){
			if(arr[i] == arr[j]){
				if(j<i)
					break;
				else
					count++;
			}
				
		}
		if(count > 1)
			printf("%d repeated %d times\n",arr[i],count);
	}
}

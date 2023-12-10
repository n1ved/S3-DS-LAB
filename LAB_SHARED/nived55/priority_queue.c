#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define SIZE 5

int queue[SIZE];

int f = -1;
int r = -1;

void enqueue();
void dequeue();

void display();
void size();

bool isFull();
bool isEmpty();

void main(){
	int option;
	while(true){
		printf("\n\nQueue operations\n");
		printf("\t1.Display\n\t2.Enqueue\n\t3.Dequeue\n\t4.Size\n\t5.Exit\n");
		printf("Select an option : ");
		scanf("%d",&option);
		printf("\n");
		switch(option){
			case 1	:display();break;
			case 2	:enqueue();break;
			case 3	:dequeue();break;
			case 4	:size();break;
			case 5	:exit(0);break;
			default	:printf("Invalid option entered\n");
		}
	}
}

bool isEmpty(){
	return (f == -1 && r == -1);
}
bool isFull(){
	return (r == SIZE-1);
}

void enqueue(){
	if(isFull()){
		printf("Cannot enqueue , queue overflow\n");
	}
	else{
		if(isEmpty()){
			f++;
			r++;
		}
		else{
			r++;
		}
		int key;
		printf("Enter element to insert : ");
		scanf("%d",&key);
		int j = r-1;
		while(j>=0 && queue[j]>key){
			queue[j+1] = queue[j];
			j--;
		}
		queue[j+1] = key;
	}
}

void dequeue(){
	if(isEmpty()){
		printf("Queue underflow , nothing to dequeue\n");
	}
	else if(f>r){
		printf("Cannot perform dequeue on stack of size 0\n");
	}
	else{
		printf("Dequeued %d\n",queue[f]);
		f++;
	}
}

void size(){
	if(isEmpty()){
		printf("Queue underflow\n");
	}
	else{
		printf("Queue size : %d\n",r-f+1);
	}
}

void display(){
	if(!isEmpty()){
		for(int i=f;i<=r;i++){
			printf("%d ",queue[i]);
		}
		printf("\n");
	}
	else{
		printf("Empty queue , nothing to display\n");
	}
}

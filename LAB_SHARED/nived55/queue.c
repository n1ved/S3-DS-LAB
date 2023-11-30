#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

int queue[SIZE];
int f=-1,r=-1;

bool isEmpty();
bool isFull();

void display();
void enqueue();
void dequeue();
void size();

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
	if(isEmpty()){
		f++;
		r++;
		printf("Enter element to insert : ");
		scanf("%d",&queue[r]);
	}
	else if(isFull()){
		printf("Queue overflow , cannot enqueue\n");
	}
	else{
		r++;
		printf("Enter element to insert : ");
		scanf("%d",&queue[r]);
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
	printf("Size of queue is %d\n",r-f+1);
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

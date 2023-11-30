#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

int q[SIZE];
int F = -1;
int R = -1;

void enqueue();
void dequeue();
void display();

bool isEmpty();
bool isFull();

void resetQueue();

void main(){
	int option;
	while(true){
		printf("Menu\n");
		printf("\t1 . Enqueue \n");
		printf("\t2 . Dequeue \n");
		printf("\t3 . Display \n");
		printf("\t4 . Exit \n");
		printf("Option >> ");
		scanf("%d" , &option);
		
		switch(option){
			case 1 : enqueue();break;
			case 2 : dequeue();break;
			case 3 : display();break;
			case 4 : return ; break;
			case 5 : printf("Invalid option\n");
		}
	}
}


//This function checks the empty condition and return weather true or false
bool isEmpty(){
	if(F == -1 && R == -1)
		return true;
	return false;
}
//This function checks the full condition and return weather true or false
bool isFull(){
	if(F == 0 && R==SIZE-1)
		return true;
	else if(F == (R+1)%SIZE)
		return true;
		
	return false;
}


//This function checks whether its full and if not full enqueues
void enqueue(){
	if(!isFull()){
		if(isEmpty()){
			F = 0 ;
			R = 0 ;
		}
		else{
			R = (R+1)%SIZE;
		}
		printf("Enter element : ");
		scanf("%d",&q[R]);
		display();
	}
	else{
		printf("Queue is full ! \n");
	}
}

//resets the queue back to initial possition
void resetQueue(){
	F = -1;
	R = -1;
}

//This function checks whether its Empty and if not empty dequeues
void dequeue(){
	if(!isEmpty()){
		if(F == R){
			resetQueue();
		}
		else{
			F = (F+1)%SIZE;
		}
		display();
	}
	else{
		printf("Queue is Empty ! \n");
	}
}

//Print out the queue
void display(){
	if(isEmpty()){
		printf("Queue is Empty ! \n");
		return;
	}
	printf("Queue : ");
	int i = F;
	while(i != R){
		printf("%d\t",q[i]);
		i = (i+1)%SIZE;
	}
	
	printf("%d\n",q[R]);
}

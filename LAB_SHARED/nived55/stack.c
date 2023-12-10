
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

int stack[SIZE];
int top = -1;

bool isEmpty();
bool isFull();

void push();
void pop();
void peek();
void display();

void main(){
	int option;
	while(true){
		printf("\n\nStack operations\n");
		printf("\t1.Display\n\t2.Push\n\t3.Pop\n\t4.Peek\n\t5.Exit\n");
		printf("Select an option : ");
		scanf("%d",&option);
		printf("\n");
		switch(option){
			case 1	:display();break;
			case 2	:push();break;
			case 3	:pop();break;
			case 4	:peek();break;
			case 5	:exit(0);break;
			default	:printf("Invalid option entered\n");
		}
	}
}

bool isEmpty(){
	return top == -1;
}
bool isFull(){
	return top == SIZE-1;
}

void push(){
	if(!isFull()){
		top++;
		printf("Enter Element to push : ");
		scanf("%d",&stack[top]);
	}
	else{
		printf("Stack Overflow , Cannot Push\n");
	}
}

void pop(){
	if(!isEmpty()){
		printf("%d is poped\n",stack[top]);
		top--;
	}
	else{
		printf("Stack Underflow , Nothing to pop\n");
	}
}

void peek(){
	if(!isEmpty()){
		printf("%d\n",stack[top]);
	}
	else{
		printf("Empty stack, nothing to peek\n");
	}
}

void display(){
	if(!isEmpty()){
		for(int i=top ; i>=0 ; i--){
			printf("%d\n",stack[i]);
		}
	}else{
		printf("Empty stack, nothing to display\n");
	}
}


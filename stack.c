#include <stdio.h>
#include <stdlib.h>

#define SIZE 10;

//Stack declaration 
int stack[SIZE];
int top = -1;

//Stack function declarations
void push();
void pop();
void peek();
bool isEmpty();
bool isFull();

//Companion functions
void display();

void main(){
    int option;
    while(true){
        printf("Stack Operations \n");
        printf("\t1.Push\n\t2.Pop\n\t3.Peek\n\t4.Display\n\t5.Exit\n");
        printf("Select option : ");
        scanf("%d",&option);

        switch(option){
            case 1  : push() ; break;
            case 2  : pop() ; break;
            case 3  : peek() ; break;
            case 4  : display() ; break;
            case 5  : exit(0) ; break;
            default : printf("Invalid option inserted ... try again ! \n\n");
        }
    }
}

bool isEmpty(){
    return (top == -1);
}
bool isFull(){
    return (top == SIZE-1);
}

void push(){
    if(!isFull()){
        printf("Enter element to push : ");
        top++;
        scanf("%d",&stack[top]);
        printf("\n");
        display();
    }else{
        printf("Stack overflow\n");
    }
}

void pop(){
    if(!isEmpty()){
        printf("Poped %d\n",stack[top]);
        top--;
    }else{
        printf("Stack underflow\n");
    }
}



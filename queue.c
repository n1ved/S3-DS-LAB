#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int F = -1 , R = -1;

void enqueue();
void dequeue();
void display();

bool isEmpty(){
    if(F == -1)
        return true;
    else if (F > R)
        return true;
    return false;
}

bool isFull(){
    return R == SIZE -1 ;
}

void main(){
    int opt;
    while(true){
        printf("\n1. Enqueue\n2. Dequeue\n3. Exit\nEnter your choice: ");
        scanf("%d",&opt);
        switch(opt){
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: exit(0);
            default: printf("Invalid option\n");
        }
    }
}

void enqueue(){
    if(!isFull()){
        if(F == -1){
            F++;
            R++;
        }
        else{
            R++;
        }
        printf("Enter number to enqueue : ");
        scanf("%d" , &queue[R]);
    }
    else{
        printf("queue overflow \n");
    }
    display();
}

void dequeue(){
    if(!isEmpty()){
        printf("Dequeueing %d ...\n" , queue[F]);
        F++;
    }
    else{
        printf("Nothing to delete queue underflow \n");
    }
    display();
}

void display(){
    if(!isEmpty()){
        printf("Queue : ");
        for(int i = F ; i <= R ; i++){
            printf("[%d]" , queue[i]);
        }
        printf("\n");
    }
    else{
        printf("Queue is empty\n");
    }   
}
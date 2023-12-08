//Q said first come first serve so implementing normal queue
#include <stdio.h>
#include <string.h>
#define SIZE 10

char queue[SIZE][50];
int f = -1;
int r = -1;

void dequeue();
void enqueue();
void display();

void main(){
    int o;
    while(1){
        printf("Patient queue\n");
        printf("\t1. Add patient\n");
        printf("\t2. Call patient\n");
        printf("\t3. Display\n");
        printf("\t4. EXIT\n");
        printf("Option : ");
        scanf("%d",&o);
        switch(o){
            case 1 : enqueue() ; break;
            case 2 : dequeue() ; break;
            case 3 : display() ; break;
            case 4 : return;
            default: return;
        }
    }
}

void enqueue(){
    char str[50];
    printf("Enter first name : ");
    scanf("%s" , str);
    if(r == SIZE - 1){
        printf("Queue full\n");
        return;
    }

    f == -1 ? f=r=0 : r++;
    strcpy(queue[r],str);
}
void dequeue(){
    if(f == -1){
        printf("Queue Empty\n");
        return;
    }
    puts(queue[f]);
    printf("\n");
    f == r ? f = r = -1 : f++ ;
}
void display(){
    for(int i=f ; i<=r ; i++)
        printf("[%s]",queue[i]);
    printf("\n");
}

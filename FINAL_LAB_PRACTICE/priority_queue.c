#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 10

int q[MAX_SIZE];
int f = -1 , r = -1;

bool isFull(){
    return r == MAX_SIZE-1;
}
bool isEmpty(){
    return f == r ;
}

void enqueue(){
    if(!isFull()){
        printf("Enter data : ");
        int key,temp;
        scanf("%d",&key);
        if(r == -1){
            r++;
            f++;
            q[r] = key;
            return;
        }
        r++;
        int j = r -1;
        while(j>=f && q[j] > key){
            q[j+1] = q[j];
            j--;
        }
        q[j] = key;
    }
}

void dequeue(){
    if(!isEmpty()){
        f++;
    }
}

void display(){
    for(int i=0 ; i<=MAX_SIZE-1 ; i++){
        printf("%d ", q[i] );
    }
    printf("\n");
}

void main(){
    int choice;
    while(choice != 4 ){
        printf("\n1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("Enter Option : ");
        scanf("%d" , &choice);
        switch(choice){
            case 1 :  enqueue(); break;
            case 2 :  dequeue(); break;
            case 3 :  display(); break;
            default:  return;
        }
    }
}
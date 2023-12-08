//make queue (FIFO) using stack(LIFO)

#include <stdio.h>
#define SIZE 10

int stack[SIZE];
int top = -1;
int _stack[SIZE];
int _top = -1;

void push(int n){
    top++;
    stack[top] = n;
}

int pop(){
    top--;
    return stack[top+1];
}

int _pop(){
    _top--;
    return _stack[_top+1];
}

void _push(int n){
    _top++;
    _stack[_top] = n;
}

void enqueue(){
    int n;
    printf("Enter element : ");
    scanf("%d" , &n);
    push(n);
}

void dequeue(){
    while(top > -1){
        _push(pop());
    }
    printf("dequeued %d\n" , _pop());
    while(_top > -1){
        push(_pop());
    }
}

void display(){
    for(int i=0 ; i<=top ; i++){
        printf("%d ",stack[i]);
    }
    printf("\n");
}


void main(){
    int o;
    while(1){   +
        printf("Queue operation\n");
        printf("\t1. Enqueue\n");
        printf("\t2. Dequeue\n");
        printf("\t3. Display\n");
        printf("\t4. EXIT\n");
        printf("Enter option : ");
        scanf("%d" , &o);
        switch(o){
            case 1 : enqueue()  ;break;
            case 2 : dequeue()  ;break;
            case 3 : display()  ;break;
            case 4 : return;
            default: return;
        }
    }
}
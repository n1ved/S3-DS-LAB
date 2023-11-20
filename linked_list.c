#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LL long long int

struct node{
    int data;
    struct node *next; 
};

LL* createLinkedList(LL*,int);
void displayLinkedList(LL*);
LL* addFront(LL*);


void main(){
    LL *head = NULL;
    int n;
    printf("Enter number of node to create : ");
    scanf("%d" , &n);
    head = createLinkedList(head , n);
    displayLinkedList(head);
    while(true){
        printf("1.Display\n2.Add to front\n3.Add to end\n4.Add after\n5.Exit\nChoose option >>>");
        int o;
        scanf("%d" , &o);
        switch(o){
            case 1  :   displayLinkedList(head);    break;
            case 2  :   head = addFront(head);             break;
            case 5  :   exit(0);                break;
        }
    }
}

void displayLinkedList(LL* head){
    struct node *current = head;
    while(current->next != NULL){
        printf("[%d]-",current->data);
        current = current->next;
    }
    printf("\n");
}

LL* createLinkedList(LL *head , int n){
    struct node *current = malloc(sizeof(struct node));
    int i=n;
    while(i--){
        printf("Generating node %d \n" ,n-i);
        printf("data : ");
        scanf("%d",&current->data);
        if (head == NULL)
            head = current;

        current->next = malloc(sizeof(struct node));
        current = current->next;
        current->next = NULL;
    }
    return head;
}

LL* addFront(LL* head){
    struct node *newNode = malloc(sizeof(struct node));
    printf("Enter element to add : ");
    scanf("%d",&newNode->data);
    newNode->next = head;
    return newNode;
}



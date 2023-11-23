#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* push(struct node* head){
    struct node *newNode = malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d" , &newNode->data);
    newNode->next = head;
    head = newNode;
    return head;
}

struct node* pop(struct node* head){
    if(head == NULL){
        printf("Stack underflow");
    }
    else{
        struct node* temp = head;
        head = head->next;
        printf("deleting %d\n" , temp->data);
        free(temp);
        return head;
    }
}

void display(struct node* head){
    if(head == NULL)
        printf("Nothing to display\n");
    while(head != NULL){
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}

void main(){
    struct node* head = NULL;

    int opt;
    while(1){
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter option : ");
        scanf("%d",&opt);
        switch(opt){
            case 1 : head = push(head); break;
            case 2 : head = pop(head);  break;
            case 3 : display(head);     break;
            case 4 : exit(0);           break;
        }
    }

}
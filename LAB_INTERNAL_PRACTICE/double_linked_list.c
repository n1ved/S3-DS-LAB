//All operations on Double linked list
//took 51mins

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node * prev;
    struct node * next;
};

struct node * addFront(struct node *);
struct node * addRear(struct node *);
struct node * rmFront(struct node *);
struct node * rmRear(struct node *);
struct node * addAfter(struct node *);
struct node * rmAfter(struct node *);
struct node * addAfterIndex(struct node *);
struct node * rmAfterIndex(struct node *);
void display(struct node *);

void main(){
    struct node* head = NULL;
    int o;
    while(true){
        printf("Double Ended Queue\n");
        printf("\t1.Add Front\n");
        printf("\t2.Add Rear\n");
        printf("\t3.Add After\n");
        printf("\t4.Add After Index\n");
        // printf("\t5.Remove Front\n");
        // printf("\t6.Remove Rear\n");
        // printf("\t7.Remove After\n");
        // printf("\t8.Remove After Index\n");
        printf("\t9.Display\n");
        printf("\t10.EXIT\n");
        printf("Enter option : ");
        scanf("%d",&o);
        switch(o){
            case 1 : head = addFront(head) ; break;
            case 2 : head = addRear(head) ; break;
            case 3 : head = addAfter(head) ; break;
            case 4 : head = addAfterIndex(head) ; break;
            // case 5 : head = rmFront(head) ; break;
            // case 6 : head = rmRear(head) ; break;
            // case 7 : head = rmAfter(head) ; break;
            // case 8 : head = rmAfterIndex(head) ; break;
            case 9 : display(head) ; break;
            case 10 : exit(0) ; break;
            default : printf("Wrong choice\n");exit(1);
        }
    }
}

struct node * addFront(struct node * head){
    struct node * newNode = malloc(sizeof(struct node));
    printf("Enter data :");
    scanf("%d" , &newNode->data);
    newNode->prev = NULL;
    newNode->next = head;
    if(head != NULL)
        head->prev = newNode;
    head = newNode;
    return head;
}

struct node * addRear(struct node *head){
    struct node * newNode = malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d" , &newNode->data);
    newNode->next = NULL;
    if(head == NULL){
        newNode->prev = NULL;
        newNode->next = head;
        head = newNode;
    }else{
        struct node * current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
    return head;
}

struct node * addAfter(struct node *head){
    struct node * newNode = malloc(sizeof(struct node));
    int key;
    printf("Enter data : ");
    scanf("%d" , &newNode->data);
    printf("Enter key : ");
    scanf("%d" , &key);  
    if(head == NULL){
        printf("List empty\n");
    }
    else{
        struct node * current = head; 
        while(current != NULL){
            if(current ->data == key){
                if(current->next != NULL){
                    current->next->prev = newNode;
                    newNode->next = current->next;
                }else{
                    newNode->next = NULL;
                }
                newNode->next = current->next;
                newNode->prev = current;
                current->next = newNode;
                return head;
            }
            current = current->next;
        }
        printf("Cannot find key\n");
    }
    return head;
}

struct node * addAfterIndex(struct node * head){
    struct node * newNode = malloc(sizeof(struct node));
    int key;
    int count = 0;
    printf("Enter data : ");
    scanf("%d" , &newNode->data);
    printf("Enter index : ");
    scanf("%d" , &key);
    struct node * current = head ;
    while(current != NULL){
        if(count == key){
            break;
        }
        count++;
    }
    if(current == NULL)
        return head;
    while(count--){
        current = current->next;
    }
    if(current->next != NULL){
        current->next->prev = newNode;
        newNode->next = current->next;
    }else{
        newNode->next = NULL;
    }
    newNode->prev = current;
    current->next = newNode;
    return head;
}

void display(struct node * head){
    while(head != NULL){
        printf("[%d]-",head->data);
        head = head->next;
    }
    printf("[NULL]\n");
}

//lazy to complete
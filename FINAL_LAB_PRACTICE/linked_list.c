#include <stdio.h>

struct node{
    int data;
    struct node *next;
};

struct node* head = NULL;

void insert_begin(){
    struct node* newNode = malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d",&newNode->data);
    if( head == NULL){
        newNode->next = NULL;
    }else{
        newNode->next = head;
    }
    head = newNode;
}
void insert_end(){
    struct node* newNode = malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d",&newNode->data);
    if(head == NULL){
        newNode->next = NULL;
        head = newNode;
    }else{
        struct node* current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
        newNode->next = NULL;
    }
}
void insert_pos(){
    struct node* newNode = malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d",&newNode->data);
    printf("Enter data to search : ");
    int key;
    scanf("%d",&key);
    struct node* current = head;
    while(current->next != NULL){
        if(current->data == key){
            newNode->next = current->next;
            current->next = newNode;
        }
        current = current->next;
    }
}

void delete_begin(){
    if(head == NULL){
        printf("Nothing to delete");
    }else{
        struct node* current = head;
        head = head->next;
        free(current);
    }
}

void delete_end(){
    if(head == NULL){
        printf("Nothing to delete");
    }else{
        struct node* current = head;
        while(current->next->next != NULL){
            current = current->next;
        }
        struct node* temp = current->next;
        current->next = NULL;
        free(temp);
    }
}

void delete_pos(){
    if(head == NULL){
        printf("Nothing to delete");
    }else{
        printf("Enter data to search : ");
        int key;
        scanf("%d",&key);
        struct node* current = head;
        while(current != NULL){
            if(current->next->data == key){
                struct node* temp = current->next;
                current->next = current->next->next;
                free(temp);
            }
        }
    }
}

void display(){
    struct node* current = head;
    while(current != NULL){
        printf("%d " , current->data );
        current = current->next;
    }
}

void main(){
    int choice;
    while(choice !=9 ){
        printf("1. Create a linked list\n");
        printf("2. Display the linked list\n");
        printf("3. Insert a node at the beginning\n");
        printf("4. Insert a node at the end\n");
        printf("5. Insert a node at a given position\n");
        printf("6. Delete a node from the beginning\n");
        printf("7. Delete a node from the end\n");
        printf("8. Delete a node from a given position\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 2:
                display();
                break;
            case 3:
                insert_begin();
                break;
            case 4:
                insert_end();
                break;
            case 5:
                insert_pos();
                break;
            case 6:
                delete_begin();
                break;
            case 7:
                delete_end();
                break;
            case 8:
                delete_pos();
                break;
            default:
                printf("Invalid choice\n");
        }
    }
}
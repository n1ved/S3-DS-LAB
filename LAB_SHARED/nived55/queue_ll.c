#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node {
	int data ;
	struct node* next;
};

struct node * enqueue(struct node *);
struct node * dequeue(struct node *);
void display(struct node *);


void main(){
	struct node * head = NULL;
	int o;
	while(true){
		printf("Queue operations\n");
		printf("\t1. Display\n");
		printf("\t2. Enqueue\n");
		printf("\t3. Dequeue\n");
		printf("\t4. Exit\n");
		printf("Enter option : ");
		scanf("%d" , &o);
		switch(o){
			case 1	: display(head)		;break;
			case 2	: head = enqueue(head)	;break;
			case 3	: head = dequeue(head)	;break;
			case 4	: exit(0)		;break;
			default	: printf("Invalid option\n");
		}
	}
}

struct node * enqueue(struct node * head){
	struct node * current = head;
	struct node * newNode = malloc(sizeof(struct node));
	printf("Enter data : ");
	scanf("%d" , &newNode->data);
	newNode->next = NULL;
	if(current == NULL){
		head = newNode;
	}
	else{
		while(current->next != NULL){
			current = current->next;	
		}
		current->next = newNode;	
	}
	return head;
}

struct node * dequeue(struct node * head){
	if(head == NULL){
		printf("Queue underflow\n");
	}
	else{
		struct node * temp = head;
		head = head->next;
		free(temp);
	}
	return head;
}

void display(struct node * head){
	printf("\n");
	if(head == NULL){
		printf("Queue underflow\n");
		return;
	}
	while(head != NULL){
			printf("%d ",head->data);
			head = head->next;
	}
	printf("\n");
}

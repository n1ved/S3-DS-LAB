#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct node {
	int data ;
	struct node* next;
};

struct node *  push(struct node * );
struct node *  pop(struct node * );
void peek(struct node * );
void display(struct node * );


void main(){
	struct node *  head = NULL;
	int o;
	while(true){
		printf("Stack operations\n");
		printf("\t1. Display\n");
		printf("\t2. Push\n");
		printf("\t3. Pop\n");
		printf("\t4. Peek\n");
		printf("\t5. Exit\n");
		printf("Enter option : ");
		scanf("%d" , &o);
		switch(o){
			case 1	: display(head)		;break;
			case 2	: head = push(head)	;break;
			case 3	: head = pop(head)	;break;
			case 4	: peek(head)		;break;
			case 5	: exit(0)		;break;
			default	: printf("Invalid option\n");
		}
	}
}

struct node *  push(struct node *  head){
	struct node *  newNode = malloc(sizeof(struct node));
	printf("Enter data : ");
	scanf("%d" , &newNode->data);
	newNode->next = head;
	head = newNode;
	return head;
}

struct node * pop(struct node *  head){
	if(head == NULL){
		printf("Stack underflow\n");
	}
	else{
		struct node *  temp = head;
		head = head->next;
		free(temp);
	}
	return head;
}

void display(struct node *  head){
	printf("\n");
	if(head == NULL){
		printf("Stack underflow\n");
		return;
	}
	while(head != NULL){
			printf("%d\n",head->data);
			head = head->next;
	}
	printf("\n");
}

void peek(struct node *  head){
	printf("\n");
	if(head == NULL){
		printf("Stack underflow\n");
	}
	else{
		printf("%d\n",head->data);
	}
}


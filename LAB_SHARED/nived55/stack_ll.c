#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NODE struct node*

struct node {
	int data ;
	struct node* next;
};

NODE push(NODE);
NODE pop(NODE);
void peek(NODE);
void display(NODE);


void main(){
	NODE head = NULL;
	int o;
	while(true){
		printf("\n1.Display\n2.Push\n3.Pop\n4.Peek\n5.Exit\nEnter option : ");
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

NODE push(NODE head){
	NODE newNode = malloc(sizeof(struct node));
	printf("Enter data : ");
	scanf("%d" , &newNode->data);
	newNode->next = head;
	head = newNode;
	return head;
}

NODE pop(NODE head){
	if(head == NULL){
		printf("List empty\n");
	}
	else{
		NODE temp = head;
		head = head->next;
		free(temp);
	}
	return head;
}

void display(NODE head){
	printf("\n");
	if(head == NULL){
		printf("List empty\n");
		return;
	}
	while(head != NULL){
			printf("%d\n",head->data);
			head = head->next;
	}
	printf("\n");
}

void peek(NODE head){
	printf("\n");
	if(head == NULL){
		printf("List empty\n");
	}
	else{
		printf("%d\n",head->data);
	}
}


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NODE struct node*

struct node {
	int data ;
	struct node* next;
};

NODE enqueue(NODE);
NODE dequeue(NODE);
void display(NODE);


void main(){
	NODE head = NULL;
	int o;
	while(true){
		printf("\n1.Display\n2.Enqueue\n3.Dequeue\n4.Exit\nEnter option : ");
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

NODE enqueue(NODE head){
	NODE current = head;
	NODE newNode = malloc(sizeof(struct node));
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

NODE dequeue(NODE head){
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
			printf("%d ",head->data);
			head = head->next;
	}
	printf("\n");
}

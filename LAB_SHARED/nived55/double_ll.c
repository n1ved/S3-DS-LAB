#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define NODE struct node *
struct node{
	int data;
	struct node* prev;
	struct node* next;
} *HEAD , *TAIL;

void addFront();
void addRear();
void rmFront();
void rmRear();
void displayFR();
void displayRF();
void addAfter();
void addBefore();

void main(){
	int opt;
	HEAD = NULL;
	TAIL = NULL;
	while(true){
		printf("\nDOUBLE LINKED LIST OPERATIONS\n\n");
		printf("\t1 . Display Front to Rear \n");
		printf("\t2 . Display Rear to Front\n");
		printf("\t3 . Add to Front\n");
		printf("\t4 . Add to Rear\n");
		printf("\t5 . Remove from Front\n");
		printf("\t6 . Remove from Rear\n");
		printf("\t7 . Add after\n");
		printf("\t8 . Add before\n");
		printf("\t9 . EXIT\n");
		printf("\nSelect an option : ");
		scanf("%d" , &opt);
		switch(opt){
			case 1 : displayFR()	;break;
			case 2 : displayRF()	;break;
			case 3 : addFront()	;break;
			case 4 : addRear()	;break;
			case 5 : rmFront()	;break;
			case 6 : rmRear()	;break;
			case 7 : addAfter()	;break;
			case 8 : addBefore()	;break;
			case 9 : return		;break;
			default:printf("Invalid option entered !\n");
		}
	}
}


void addFront(){
	struct node* newNode = malloc(sizeof(struct node));
	printf("Enter data : ");
	scanf("%d",&newNode->data);
	newNode->prev = NULL;
	if(HEAD == NULL){
		newNode->next = NULL;
		HEAD = newNode;
		TAIL = newNode;
	}
	else{
		newNode->next = HEAD;
		HEAD->prev = newNode;
		HEAD = newNode;
	}
}

void addRear(){
	struct node* newNode = malloc(sizeof(struct node));
	printf("Enter data : ");
	scanf("%d",&newNode->data);
	newNode->next = NULL;
	if(TAIL == NULL){
		newNode->prev = NULL;
		HEAD = newNode;
		TAIL = newNode;
	}
	else{
		TAIL->next = newNode;
		newNode->prev = TAIL;
		TAIL = newNode;
	}
}

void rmFront(){
	NODE temp = HEAD;
	if(HEAD == NULL){
		printf("Empty list\n");
	}
	else if(HEAD->next == NULL){
		HEAD = NULL;
		TAIL = NULL;
		free(temp);
	}
	else{
		HEAD = HEAD->next;
		HEAD->prev = NULL;
		free(temp);
	}
}

void rmRear(){
	NODE temp = TAIL;
	if(TAIL == NULL){
		printf("Empty list\n");
	}
	else if( TAIL->prev == NULL){
		HEAD = NULL;
		TAIL = NULL;
		free(temp);
	}
	else{
		TAIL = TAIL->prev;
		TAIL->next = NULL;
		free(temp);
	}
}

void displayFR(){
	if(HEAD == NULL){
		printf("Empty list\n");
	}else{
		NODE current = HEAD;
		while(current->next != NULL){
			printf("[ %d ]",current->data);
			current = current->next;
		}
		printf("[ %d ]\n",current->data);
	}
}
void displayRF(){
	if(TAIL == NULL){
		printf("Empty list\n");
	}else{
		NODE current = TAIL;
		while(current->prev != NULL){
			printf("[ %d ]",current->data);
			current = current->prev;
		}
		printf("[ %d ]\n",current->data);
	}
}
void addAfter(){
	int key;
	NODE newNode = malloc(sizeof(struct node));
	printf("Enter data : ");
	scanf("%d",&newNode->data);
	printf("Enter element to add data after : ");
	scanf("%d",&key);
	NODE current = HEAD;
	if (HEAD == NULL)
	{
		printf("List empty\n");
		return;
	}
	
	while(current->next != NULL){
		if(current->data == key){
			current->next->prev = newNode;
			newNode->next = current->next;
			newNode->prev = current;
			current->next = newNode;
			if(current = TAIL){
				TAIL = newNode;
			}
			return;
		}
		current = current->next;
	}
	printf("Cannot find element %d\n" , key);
}
void addBefore(){
	int key;
	NODE newNode = malloc(sizeof(struct node));
	printf("Enter data : ");
	scanf("%d",&newNode->data);
	printf("Enter element to add data before : ");
	scanf("%d",&key);
	NODE current = TAIL;
	if (TAIL == NULL)
	{
		printf("List empty\n");
		return;
	}
	while(current->prev != NULL){
		if(current->data == key){
			current->prev->next = newNode;
			newNode->prev = current->prev;
			newNode->next = current;
			current->prev = newNode;
			if(current = HEAD){
				HEAD = newNode;
			}
			return;
		}
		current = current->prev;
	}
	printf("Cannot find element %d\n" , key);
}

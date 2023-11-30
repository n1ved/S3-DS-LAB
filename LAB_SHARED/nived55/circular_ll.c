#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NODE struct node*

struct node {
	int data ;
	struct node* next;
};

NODE addFront(NODE);
NODE addRear(NODE);
NODE rmFront(NODE);
NODE rmRear(NODE);
void addAfter(NODE);
void display(NODE);

void main(){
	NODE head = NULL;
	int o;
	while(true){
		printf("\n0.Display\n1.Add to front\n2.Add to rear\n3.Delete from front\n4.Delete from rear\n5.Insert after\n6.EXIT\nEnter option :");
		scanf("%d" , &o);
		switch(o){
			case 0	: display(head)		;break;
			case 1	: head = addFront(head)	;break;
			case 2	: head = addRear(head)	;break;
			case 3	: head = rmFront(head)	;break;
			case 4	: head = rmRear(head)	;break;
			case 5	: addAfter(head)	;break;
			case 6	: exit(0)		;break;
			default	: printf("Invalid option\n");
		}
	}
}

NODE addFront(NODE head){
	NODE newNode = malloc(sizeof(struct node));
	printf("Enter data : ");
	scanf("%d" , &newNode->data);
	
	if(head == NULL){
		newNode->next = newNode;
		head = newNode;
	}else{
		newNode->next = head;
	
		NODE current = head;
		while(current->next != head){
		current = current->next;	
		}
		head = newNode;
		current->next = head;
	
	}
	display(head);
	return head;
}

NODE addRear(NODE head){
	NODE current = head;
	NODE newNode = malloc(sizeof(struct node));
	printf("Enter data : ");
	scanf("%d" , &newNode->data);

	if(current == NULL){
		newNode->next = newNode;
		head = newNode;
	}
	else{
		while(current->next != head){
			current = current->next;	
		}
		newNode->next = current->next;
		current->next = newNode;	
	}
	display(head);
	return head;
}

NODE rmFront(NODE head){
	if(head == NULL){
		printf("List empty\n");
	}
	else{
		NODE current = head;
		while(current->next != head){
			current = current->next;	
		}
		NODE temp = head;
		head = head->next;
		current->next = head;
		free(temp);
	}
	display(head);
	return head;
}

NODE rmRear(NODE head){
	if(head == NULL){
		printf("List empty\n");
	}
	else{
		NODE current = head;
		while(true){
			if(current->next == head){
				NODE temp = current;
				head = NULL;
				free(temp);
				break;
			}
			if(current->next->next == head){
				NODE temp = current->next;
				current->next = head;
				free(temp);
				break;
			}
			current = current->next;
		}
	}
	display(head);
	return head;
}

void addAfter(NODE head){
	
	int key;
	NODE newNode = malloc(sizeof(struct node));
	printf("Enter element to search : ");
	scanf("%d" , &key);
	printf("Enter element to add after : ");
	scanf("%d" , &newNode->data);
	NODE current = head;
	while(true){
		if(current->data == key){
			newNode->next = current->next;
			current->next = newNode;
			display(head);
			return;
		}
		if(current->next == NULL){
			break;
		}
		current = current->next;
	}
	printf("Cannot find %d in List\n" , &key);
}

void display(NODE head){
	printf("\n");
	NODE current = head;
	if(head == NULL){
		printf("List empty\n");
		return;

	}
	while(current->next != head){
			printf("%d ",current->data);
			current = current->next;
	}
	printf("%d\n",current->data);
}

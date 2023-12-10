#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
	int data ;
	struct node* next;
};

struct node * addFront(struct node *);
struct node * addRear(struct node *);
struct node * rmFront(struct node *);
struct node * rmRear(struct node *);
struct node * rmKey(struct node *);
void addAfter(struct node *);
void display(struct node *);

void main(){
	struct node * head = NULL;
	int o;
	while(true){
		printf("Circular Linked List\n");
		printf("\t1. Display\n");
		printf("\t2. Add Front\n");
		printf("\t3. Add Rear\n");
		printf("\t4. Add After\n");
		printf("\t5. Remove Front\n");
		printf("\t6. Remove Rear\n");
		printf("\t7. Remove Key\n");
		printf("\t8. Exit\n");
		printf("Enter option : ");
		scanf("%d" , &o);
		switch(o){
			case 1: display(head); break;
			case 2: head = addFront(head); break;
			case 3: head = addRear(head); break;
			case 4: addAfter(head); break;
			case 5: head = rmFront(head); break;
			case 6: head = rmRear(head); break;
			case 7: head = rmKey(head); break;
			case 8: exit(0);
			default: printf("Invalid option\n");
		}
	}
}

struct node * addFront(struct node * head){
	struct node * newNode = malloc(sizeof(struct node));
	printf("Enter data : ");
	scanf("%d" , &newNode->data);
	
	if(head == NULL){
		newNode->next = newNode;
		head = newNode;
	}else{
		newNode->next = head;
		struct node * current = head;
		while(current->next != head){
			current = current->next;	
		}
		head = newNode;
		current->next = head;
	
	}
	return head;
}

struct node * addRear(struct node * head){
	struct node * current = head;
	struct node * newNode = malloc(sizeof(struct node));
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
		current->next = newNode;
		newNode->next = head;	
	}
	return head;
}

struct node * rmFront(struct node * head){
	if(head == NULL){
		printf("List empty\n");
	}
	else{
		struct node * current = head;
		while(current->next != head){
			current = current->next;	
		}
		struct node * temp = head;
		head = head->next;
		current->next = head;
		free(temp);
	}
	return head;
}

struct node * rmRear(struct node * head){
	if(head == NULL){
		printf("List empty\n");
	}
	else{
		struct node * current = head;
		while(true){
			if(current->next == head){
				struct node * temp = current;
				head = NULL;
				free(temp);
				break;
			}
			if(current->next->next == head){
				struct node * temp = current->next;
				current->next = head;
				free(temp);
				break;
			}
			current = current->next;
		}
	}
	return head;
}

void addAfter(struct node * head){
	
	int key;
	struct node * newNode = malloc(sizeof(struct node));
	printf("Enter element to search : ");
	scanf("%d" , &key);
	printf("Enter element to add after : ");
	scanf("%d" , &newNode->data);
	struct node * current = head;
	if(head == NULL){
		printf("List empty\n");
		return;
	}
	else{
		while(true){
			if(current->data == key){
				newNode->next = current->next;
				current->next = newNode;
				return;
			}
			if(current->next == head){
				break;
			}
			current = current->next;
		}
	}
	printf("Cannot find %d in List\n" , &key);
}

struct node * rmKey(struct node * head){
	int key;
	printf("Enter element to delete : ");
	scanf("%d" , &key);
	struct node * current = head;
	if(head == NULL){
		printf("List empty\n");
		return head;
	}
	if(current->data == key){
		struct node * temp = current;
		head = head->next;
		free(temp);
		return head;
	}
	else{
		while(true){
			if(current->next->data == key){
				struct node * temp = current->next;
				current->next = current->next->next;
				free(temp);
				return head;
			}
			if(current->next == head){
				break;
			}
			current = current->next;
		}
	}
	printf("Cannot find %d in List\n" , &key);
	return head;
}

void display(struct node * head){
	if(head == NULL){
		printf("List empty\n");
		return;
	}
	while(head->next != head){
			printf("%d ",head->data);
			head = head->next;
	}
	printf("%d\n",head->data);
}

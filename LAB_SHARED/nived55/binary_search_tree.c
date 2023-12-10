#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NODE struct node *

struct node{
	int data;
	struct node * left;
	struct node * right;
};

NODE assignNodes(NODE current , int adata){
	if(current == NULL){
		NODE newNode = malloc(sizeof(struct node));
		current = newNode;
		current->data = adata;
		current->left = NULL;
		current->right = NULL;
	}else{
		if(adata<current->data){
			current->left = assignNodes(current->left , adata);
		}
		else{
			current->right = assignNodes(current->right , adata);
		}
	}
	
	return current;
}

void printNode(NODE current){
	if(current != NULL){
		printNode(current->left);
		printf("%d ",current->data);
		printNode(current->right);
	}
}

void main(){
	int o,temp;
	NODE root = NULL;
	while(true){
		printf("\nBINARY SEARCH TREE\n\n");
		printf("\t 1 . Insert\n");
		printf("\t 2 . Show\n");
		printf("Enter option : ");
		scanf("%d",&o);
		switch(o){
			case 1 :
				scanf("%d",&temp);
				root = assignNodes(root , temp);
				break;
			case 2 :
				printNode(root);
				break;
			default:
				return;
				
		}
	}
	
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node * insert(struct node* curser , int data){
    if(curser == NULL){
        curser = malloc(sizeof(struct node));
        curser->data    = data;
        curser->right   = NULL;
        curser->left    = NULL;
    }
    else if(data < curser->data)
        curser->left    = insert(curser -> left , data);
    else if(data > curser->data)
        curser->right   = insert(curser -> right, data);
    else{
        printf("Cannot Enter Two elements of same data ! Abort Insertion \n");
    }
    return curser;
}

void inorder(struct node* curser){
    if(curser != NULL){
        inorder(curser -> left);
        printf("%d ", curser -> data);
        inorder(curser -> right);
    }
}

void preorder(struct node* curser){
    if(curser!= NULL){
        printf("%d ", curser -> data);
        preorder(curser -> left);
        preorder(curser -> right);
    }
}

void postorder(struct node* curser){
    if(curser != NULL){
        postorder(curser -> left);
        postorder(curser -> right);
        printf("%d ", curser -> data);
    }
}

bool alone(struct node * curser){
    return (curser -> right == NULL && curser -> left == NULL);
}

struct node * delete(struct node * curser , int key){
    if(curser == NULL){
        return curser;
    }

    if(curser->data > key){
        curser->left = delete(curser->left , key);
        return curser;
    }
    else if(curser->data < key){
        curser->right = delete(curser->right, key);
        return curser;
    }

    if(curser->left == NULL){
        struct node* temp = curser->right;
        free(curser);
        return temp;
    }
    else if(curser->right == NULL){
        struct node* temp = curser->left;
        free(curser);
        return temp;
    }
    else{
        struct node * currentParent = curser;
        struct node * current = curser -> right ;

        while(current -> left != NULL){
            currentParent = current;
            current = current -> left;
        }

        if(currentParent != curser){
            currentParent->left = current->right;
        }else{
            currentParent->right = current->left;
        }

        curser->data = current->data;
        free(current);
        return curser;  

    }
}

void main(){
    struct node *root = NULL;

    int choice , data;
    while(true){
        printf("\n");
        printf("1. Insert\n");
        printf("2. Inorder\n");
        printf("3. Preorder\n");
        printf("4. Postorder\n");
        printf("5. Delete\n");
        printf("6. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1  :   printf("Enter Data : ");
                        scanf("%d" , &data);
                        root = insert(root,data)      ; break;
            case 2  :   inorder(root)     ; break;
            case 3  :   preorder(root)    ; break;
            case 4  :   postorder(root)   ; break;
            case 5  :   printf("Enter data to Delete :");
                        scanf("%d",&data);
                        root = delete(root,data) ;     break;
            case 6  :   exit(0)           ; break;
            default :   printf("Invalid choice\n");
        }
    }
}
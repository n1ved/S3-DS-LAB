#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
};



int main(){
    printf("Enter size of graph : ");
    int size;
    scanf("%d" , &size);
    printf("Enter the vertices : ");
    struct node * vertice[size];
    for(int i=0 ; i<size ; i++){
        vertice[i] = malloc(sizeof(struct node));
        scanf("%d",&vertice[i]->data);
        vertice[i]->next = NULL;
    }

    for(int i=0 ; i<size ; i++){
        printf("Enter the Number of neighbours of %d : ",vertice[i]->data);
        int neighbourCount;
        scanf("%d" , &neighbourCount);
        printf("Enter the neighbours : ");
        struct node * current = vertice[i];
        for(int j=0 ; j<neighbourCount ; j++){
            struct node * newNode = malloc(sizeof(struct node));
            scanf("%d",&newNode->data);
            newNode->next = NULL;
            current->next = newNode;
            current = current->next;
        }
    }

    for(int i=0 ; i<size ; i++){
        struct node * current = vertice[i];
        printf("%d : ",current->data);
        current = current->next;
        while(current!=NULL){
            printf("%d ",current->data);
            current = current->next;
        }
        printf("\n");
    }

}
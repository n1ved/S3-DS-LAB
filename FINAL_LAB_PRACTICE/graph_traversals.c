#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
};
bool visitedAll(int t , int size){
        return (t == size-1);
}

bool isVisited(int arr[] , int key , int size){
    for(int i=0 ; i<size ; i++){
        if(arr[i] == key)
            return true;
    }
    return false;
}

void init(int arr[] , int n){
    for(int i=0 ; i<n ; i++){
        arr[i] = -1;
    }
}

void printArr(int arr[] , int size){
    for(int i=0 ; i<size ; i++){
        printf("%d " , arr[i]);
    }
    printf("\n");
}

void doBFS(struct node * root[] , int size){
    int i=0;
    int visted[size] , queue[size];
    int t = -1;
    int f = 0 , r = -1;
    init(visted , size);
    while(!visitedAll(t,size)){
        struct node *current = root[i];
        if(!isVisited(visted , current->data , size)){
            r++;
            t++;
            queue[r] = current->data;
            visted[t] = current->data;
        }
        f++;
        current = current ->next;
        while (current!=NULL){
            if(!isVisited(visted , current->data , size)){
                r++;
                t++;
                queue[r] = current->data;
                visted[t] = current->data;
            }
            current = current -> next;
        }
        i++;
    }
    printArr(visted , size);
}

int findIndex(struct node * root[] , int key , int size){
    for(int i =0 ; i<size ; i++){
        if(root[i]->data == key)
            return i;
    }
    return -1;
}

void doDFS(struct node * root[] , int size){
    int i=0;
    int stack[size];
    int visited[size];
    int t = -1 ;
    int v = -1 ;
    init(visited , size);
    init(stack , size);
    while(!visitedAll(v , size)){
        struct node *current = root[i]; 
        if(!isVisited(visited , current->data , v)){
            v++;
            visited[v] = current->data;
            current = current ->next;
            while(current != NULL){
                if(!isVisited(visited , current->data , v)){
                    t++;
                    stack[t] = current->data;
                }
                current = current -> next;
            }
        }
        i = findIndex(root , stack[t] , size);
        t--;
    }

    printArr(visited , size);
}   

void main(){

   printf("Enter number of vertices : ");
   int n;
   scanf("%d",&n);
   printf("Enter Vertices : ");
   struct node * vertices[n];
   for(int i=0;i<n;i++){
       vertices[i] = malloc(sizeof(struct node));
       scanf( "%d",&vertices[i]->data);
       vertices[i]->next = NULL;
   }

    for(int i=0;i<n;i++){
        printf("Enter number of neighbours of %d : ",vertices[i]->data);
        int m;
        scanf("%d",&m);
        printf("Enter neighbours : ");
        struct node * tmp = vertices[i];
        for(int j=0;j<m;j++){
            struct node * new = malloc(sizeof(struct node));
            scanf("%d",&new->data);
            new->next = NULL;
            tmp->next = new;
            tmp = tmp->next;
        }
    }
    doBFS(vertices , n);
    doDFS(vertices , n);
}

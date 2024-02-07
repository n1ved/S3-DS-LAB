#include <stdio.h>
#include <stdbool.h>

char array[20];
int r=-1;

char stack[20];
int top = -1;

void enqueue(char c){
    r++;
    array[r] = c;
}

void push(char c){
    top++;
    stack[top] = c;
}

void pop(){
    top--;
}

bool isOperator(char c){
    switch(c){
        case '*' :
        case '/' :
        case '+' :
        case '-' :
        case '^' :
        case ')' :
        case '(' : return true;
        default  : return false;
    }
}

int prior(char c){
    if(c == '+' || c == '-')
        return 1;
    if(c == '*' || c == '/')
        return 2;
    if(c == '^' )
        return 3;
    if(c == '(')
        return 0;
    
}

void assign(char c){
    if(!isOperator(c)){
        enqueue(c);
    }
    else{
        if(top == -1){
            push(c);
        }
        else if (c == ')'){
            while(stack[top] != '('){
                pop();
                enqueue(stack[top +1]);
            }
            pop();
        }
        else if (c=='(' || c=='^'){
            push(c);
        }
        else{
            while(prior(c) <= prior(stack[top])){
                pop();
                enqueue(stack[top+1]);
            }
            push(c);
        }
    }
}

void main(){
    char exp[20];
    printf("Enter Infix : ");
    scanf("%s" , exp);
    for(int i=0 ; exp[i] != '\0' ; i++){
		assign(exp[i]);
	}
    while(top > -1){
        pop();
        enqueue(stack[top+1]);
    }

    for(int i=0 ; i<= r ;i++)
        printf("%c",array[i]);

    printf("\n");
}
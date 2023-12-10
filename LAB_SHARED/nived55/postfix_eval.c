#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define SIZE 20

int stack[SIZE];

int TOP = -1;

void push(int n){
	TOP++;
	stack[TOP] = n;
}

int pop(){
	TOP--;
	return stack[TOP+1];
}

bool isOperator(char c){
	switch(c){
		case '+':
		case '-':
		case '*':
		case '/':
		case '^': return 1;
		default : return 0;
	}
}


int extract(char c){
	return c-48;
}


void operate(int a , char c  , int b){
	int var;
	switch(c){
		case '+' : var = b+a	;break;
		case '-' : var = b-a	;break;
		case '*' : var = b*a	;break;
		case '/' : var = b/a	;break;
		case '^' : var = pow(b,a);break;
	}
	push(var);
}

void assign (char c){
	if(isOperator(c)){
		operate(pop() , c , pop());
	}
	else{
		push(extract(c));
	}
}

void main(){
	char infix[SIZE];
	printf("Enter the infix operation :");
	
	scanf("%s" , &infix);
	
	for(int i=0 ; infix[i] != '\0' ; i++){
		assign(infix[i]);
	}
	
	printf("%d\n", stack[TOP]);	
}

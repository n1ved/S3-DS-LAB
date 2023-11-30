#include <stdio.h>
#include <stdbool.h>
#define SIZE 20

char stack[SIZE];
char array[SIZE];

int TOP = -1;
int INDEX = -1;

//Add the elemet to end of resultant array
void addToArray(char c){
	INDEX++;
	array[INDEX] = c;
}

//Push element to stack
void push(char c){
	TOP++;
	stack[TOP] = c;
}

//pop the element out of stack
char pop(){
	TOP--;
	return stack[TOP+1];
}


//find outs whether the character is an operator or not returns 1 if operator otherwise returns 0
bool isOperator(char c){
	switch(c){
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
		case '(':
		case ')': return 1;
		default : return 0;
	}
}

//Returns the relative priority of a operator
int prior(char c){
	switch(c){
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 2;
		case '^': return 3;
		case '(': return 0;
	}
}



void assign(char c){
	if(!isOperator(c)){
		addToArray(c);
	}
	else{
		//If stack empty push
		if(TOP == -1){
			push(c);
		}
		//When closing bracket encounterd pop everything out until first opening bracket
		else if(c == ')'){
			while(stack[TOP] != '('){
				addToArray(pop());
			}
			pop();
		}
		
		//if opening bracket or ^ operator found do a mandatory push
		else if(c == '(' || c == '^'){
			push(c);
		}
		
		//checks the priority of current character with one in top of stacks if its less or equal pop all higher elements
		//else push 
		else{
			while(prior(c) <= prior(stack[TOP])){
				addToArray(pop(c));
			}
			push(c);
		}
	}
	
	/*
	//DEBUGGER
	for(int i=0 ; i<=INDEX ; i++){
		printf("%c" ,array[i] );
	}
	printf("\n");
	for(int i=0 ; i<=TOP ; i++){
		printf("%c" ,stack[i] );
	}
	printf("\n");
	*/
}

void main(){
	char infix[SIZE];
	printf("Enter the infix operation :");
	scanf("%s" , &infix);
	for(int i=0 ; infix[i] != '\0' ; i++){
		assign(infix[i]);
	}
	while (TOP > -1){
		addToArray(pop());
	}
	for(int i=0 ; i<=INDEX ; i++){
		printf("%c" ,array[i] );
	}
	printf("\n");	
}

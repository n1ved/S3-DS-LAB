#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define SIZE 20

//stack is used to store every number and by the end the result
int stack[SIZE];

int TOP = -1;

//Push element to stack
void push(int n){
	TOP++;
	stack[TOP] = n;
}

//pop the element out of stack
int pop(){
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
		case '^': return 1;
		default : return 0;
	}
}


//Since the expression is enterd as charecter array this function returns each digit character as an integer
int extract(char c){
	return c-48;
}


//Perform operation by accepting 2 operands and an operator
void operate(int a , char c  , int b){
	int var;
	switch(c){
		case '+' : var = a+b	;break;
		case '-' : var = a-b	;break;
		case '*' : var = a*b	;break;
		case '/' : var = a/b	;break;
		case '^' : var = pow(a,b);break;
	}
	push(var);
}

//Peform different operations based on whether the given character is operator or digit 
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
	
	//take Input 
	scanf("%s" , &infix);
	
	for(int i=0 ; infix[i] != '\0' ; i++){
		assign(infix[i]);
	}
	
	//print last element in stack whilch would be the result of postfix
	printf("%d\n", stack[TOP]);	
}

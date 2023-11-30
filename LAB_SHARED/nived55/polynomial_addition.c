#include <stdio.h>

struct polynomial{
	int coef;
	int exp;
};


int readPoly(struct polynomial p[]){
	int n;
	printf("Enter number of terms : ");
	scanf("%d" , &n);
	printf("Enter the polynomial terms in descending order \n");
	for(int i=0 ; i<n ; i++){
		 printf("Enter Exponent of term %d	:",i+1);
		 scanf("%d" , &p[i].exp);
		 printf("Enter Coefficent of term %d	:",i+1);
		 scanf("%d" , &p[i].coef);
	}
	return n;
}

int addPoly(struct polynomial p1[] , struct polynomial p2[] , struct polynomial rp[] , int s1 , int s2){
	int i = 0; //keeper for p1
	int j = 0; //keeper for p2
	int k = 0; //keeper for rp
	
	while(i<s1 && j<s2){
		if(p1[i].exp == p2[j].exp){  				//if same exponent found
			rp[k].exp = p1[i].exp;
			rp[k].coef= p1[i].coef+p2[j].coef;
			i++;
			j++;
			k++;
		}
		else if(p1[i].exp > p2[j].exp){
			rp[k].exp = p1[i].exp;
			rp[k].coef= p1[i].coef;
			i++;
			k++;
		}
		else{
			rp[k].exp = p2[j].exp;
			rp[k].coef= p2[j].coef;
			j++;
			k++;	
		}
	}
	while(i<s1){							//To count leftover element ie if size does not match
		rp[k].exp = p1[i].exp;
		rp[k].coef= p1[i].coef;
		i++;
		k++;
	}
	while(j<s2){
		rp[k].exp = p2[j].exp;
		rp[k].coef= p2[j].coef;
		j++;
		k++;
	}
	return k;
}

void printPoly(struct polynomial p[] , int n){
	printf("%d(x^%d)",p[0].coef,p[0].exp);
	for(int i=1 ; i<n ; i++)
		printf(" + %d(x^%d)",p[i].coef,p[i].exp);
	printf("\n");
}


void main(){
	struct polynomial p1[10];
	struct polynomial p2[10];
	struct polynomial rp[20];
	int s1 = readPoly(p1);
	printPoly(p1,s1);
	int s2 = readPoly(p2);
	printPoly(p2,s2);
	int rs = addPoly(p1 , p2 , rp , s1 , s2);
	
	printPoly(rp , rs);
}

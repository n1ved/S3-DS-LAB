#include <stdio.h>
#define L 10

void inputMatrix(int m , int n , int sm[m][n]){
	for(int i=0 ; i<m ; i++)
		for(int j=0 ; j<n ; j++)
			scanf("%d" , &sm[i][j]);
}

int tripletGen(int m,int n,int sm[m][n] , int tr[L*L][3]){
	int count = 0;
	int k=1;
	tr[0][0] = m;
	tr[0][1] = n;
	for(int i=0 ; i<m ; i++){
		for(int j=0 ; j<n ; j++){
			if(sm[i][j] != 0){
				tr[k][0] = i;
				tr[k][1] = j;
				tr[k][2] = sm[i][j];
				k++;
				count++;			
			}
		}	
	}
	return count;
}

void printTriplet(int c,int tr[L*L][3]){
	for(int i=0 ; i<=c ; i++){
		for(int j=0 ; j<3 ; j++){
			printf("%d\t",tr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int tripletAddition(int c1 , int c2 , int tr1[L*L][3] , int tr2[L*L][3] , int str[L*L][3]){


	int i=1;
	int j=1;
	int k=1;
	
	
	while(i<=c1 && j<=c2){
	

		if(tr1[i][0] == tr2[j][0] && tr1[i][1] == tr2[j][1]){
			str[k][0] = tr1[i][0];
			str[k][1] = tr1[i][1];
			str[k][2] = tr1[i][2] + tr2[j][2];
			i++;
			j++;
			k++; 
		}
		else if(tr1[i][0] == tr2[j][0]){
			if(tr1[i][1] < tr2[j][1]){
				str[k][0] = tr1[i][0];
				str[k][1] = tr1[i][1];
				str[k][2] = tr1[i][2];
				i++;
				k++;
			}
			else{
				str[k][0] = tr2[j][0];
				str[k][1] = tr2[j][1];
				str[k][2] = tr2[j][2];
				j++;
				k++;
			}
		}
		else if(tr1[i][0] < tr2[j][0]){
			str[k][0] = tr1[i][0];
			str[k][1] = tr1[i][1];
			str[k][2] = tr1[i][2];
			i++;
			k++;
		}
		else{
			str[k][0] = tr2[j][0];
			str[k][1] = tr2[j][1];
			str[k][2] = tr2[j][2];
			j++;
			k++;
		}
	}
	
	while(i<=c1){
		str[k][0] = tr1[i][0];
		str[k][1] = tr1[i][1];
		str[k][2] = tr1[i][2];
		i++;
		k++;
	}
	
	while(j<=c2){
		str[k][0] = tr2[j][0];
		str[k][1] = tr2[j][1];
		str[k][2] = tr2[j][2];
		j++;
		k++;
	}
	
	return k;
}

void main(){
	int r1 , c1 , r2 , c2 , sm1[L][L] , sm2[L][L];
	
	printf("Enter size of matrix 1 : ");
	scanf("%d %d" , &r1 , &c1);
	printf("Enter size of matrix 2 : ");
	scanf("%d %d" , &r2 , &c2);
	
	if(r1 != r2 || c1!=c2){
		printf("Cannot perform addition of matrices of different size \n");
		return;
	}
	
	printf("Enter matrix 1 :\n");
	inputMatrix(r1 , c1 , sm1);
	printf("Enter matrix 2 :\n");
	inputMatrix(r2 , c2 , sm2);
	
	int tr1[L*L][3];
	int tr2[L*L][3];
	
	int count1 = tripletGen(r1 , c1 ,sm1,tr1);
	int count2 = tripletGen(r2 , c2 ,sm2,tr2);
	
	printf("Triplet representation of M1 :\n");
	printTriplet(count1 , tr1);
	printf("Triplet representation of M2 :\n");
	printTriplet(count2 , tr2);
	
	
	int str[L*L][3];
	str[0][0] = r1 ;
	str[0][1] = c1 ;
	
	int sumCount = tripletAddition(count1 , count2 , tr1 , tr2 , str);
	
	str[0][2] = sumCount-1;
	printf("Triplet representation of resultant matrix :\n");
	printTriplet(sumCount-1 , str);
	
}



/* Verifying anagrams
__author__='Vishal'
Date=14/08/2016*/

#include<stdio.h>

int* char_arr(char*, int*);

int main(){
	char A[100], B[100];
	int i, flag=1;
	int A_count[26]={0};
	int B_count[26]={0};
	scanf("%s%s", A, B);
	char_arr(A, A_count);
	char_arr(B, B_count);
	for(i=0;i<26;i++){
		if (A_count[i]!=B_count[i]){
			flag=0;  
			break;
		}
	}

	printf("%d\n", flag);
	return 0;
}

/*Computes the character array for a string
Input=string
output=Integer array holding the character count*/
int* char_arr(char* A, int *A_count){
	int i;
	char c;
	for(i=0;i<sizeof(A);i++){
		c=A[i];
		switch(c){
			case 'a' ... 'z':
				A_count[c-97]++;
				break;
		}
	}
	return;
}


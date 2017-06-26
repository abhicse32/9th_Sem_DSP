/*Converting decimal to hexadecimal
__author__='Vishal'
Date=13/08/2016*/

#include<stdio.h>
#define size 8

void hex_print(int);

int main(){
	long long int n;
	int i;
	int rem=0;
	int A[size]={0};
	
	scanf("%lld", &n);
	i=0;
	do{
		rem=n%16;
		n/=16;
		A[i]=rem;
		i++;
		}while(n>0);

	printf("%c%c", 'O', 'x');
	for (i=size-1;i>=0;i--){
		hex_print(A[i]);
		}
	printf("\n");
	return 0;
	}
	
/*prints the respective hexadecimal digit of 
an integer 0<=n<=15
no return value*/
void hex_print(int n){
	switch(n){
		
		case 0 ... 9: 
			printf("%d", n);
			break;

		case 10 ... 16:
			printf("%c", n+87); //Printing using ascii values
			break;
	}
}

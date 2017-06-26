/*Common prime factors of two integers
__author__='Vishal'
Date=13/08/2016*/

#include<stdio.h>
int hcf(int, int);
int isprime(int);

int main(){
	int a, b;
	int h, i;
	scanf("%d%d", &a, &b);
	h = hcf(a, b);
	
	for (i=2;i<=h;i++){
		if (h%i==0){
			if (isprime(i))
				printf("%d ", i);
		}
	}
	printf("\n");
	return 0;
}

/*Computes HCF of two integers
Input: Two integers a, b
Output: HCF of a, b*/
int hcf(int a, int b){
	if (a>=b){
		if (a%b==0) return b;
		else return hcf(b, a-b);
		}
	else{
		if (b%a==0) return a;
		else return hcf(a, b-a);
		}
}

/*Verifies if a number is prime or not
Input: integer
Output: 0->not prime
		1->prime
*/
int isprime(int n){
	int flag=0;
	int i;
	int count=0;
	for (i=2;i<n;i++){
		if (n%i==0)
			count++;
	}
	if (count==0) flag=1;
	return flag;
}
	

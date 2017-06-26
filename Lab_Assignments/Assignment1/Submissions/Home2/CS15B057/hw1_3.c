/* Author: G.Kavitha
Roll Number: CS15B057
Date: 11-08-16 */
#include <stdio.h>
const int N=1e6+1;

/* Function to check if a number i is prime
Done be checking whether any of the prime numbers from 2 to N-1 divide it
Returns 1 if it is prime, 0 otherwise
Arguments: number i which is to be checked, num of primes from 2 to N-1, 
and the array holding primes from 2 to N-1*/
int isPrime(int i,int num_primes,int primes[],int prime[]){
	
	if(i<N) {//Check directly using prime[] array
		if(prime[i]) return 1;
		else return 0;
	}

	int k;
	
	for(k=0;k<num_primes&&(primes[k]*primes[k])<=i;k++){
		if(i%primes[k]==0) return 0;//Since a prime number divides i, i is not prime
	}

	return 1;//i is prime
}
int main(){
	/*prime[i] is 0 if i is not a prime, 1 otherwise*/
	int prime[N];
	
	/* primes[] holds all the primes from 1 to N*/
	int primes[N];
	
	int i;
	int num_primes=0;//Holds the number of primes

	//Setting everything to 1 initially
	for(i=0;i<N;i++) prime[i]=1;
	
	//0 and 1 are not primes so setting them to 0
	prime[1]=0;
	prime[0]=0;

	for(i=2;i<N;i++){
		int j;
		if(prime[i]==1){
			//The multiples of a prime number are not prime
			for(j=2*i;j<N;j=j+i){
				prime[j]=0;
			}
			primes[num_primes++]=i;//Updating the array primes
		}
	}

	int a,b;
	scanf("%d %d",&a,&b);//Reading in the 2 integers
	
	for(i=2;i<=a&&i<=b;i++){
		if(isPrime(i,num_primes,primes,prime)) //Call function to check if i is prime
			if(a%i==0&&b%i==0) //If prime number i divides both a and b 
				printf("%d ",i);//Display i
	}
	printf("\n");//New line
	return 0;
}

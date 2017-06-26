/*Program that prints the common prime factors of the two integers received as arguments
		G.Pranav CS15B015 10-8-2016*/
#include<stdio.h>
#include<math.h>
void printcpfactors(int a,int b);
int isprime(int x);
int minimum(int a,int b);
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	printcpfactors(a,b);
	return 0;
}
/*Function that prints the common prime factors of the two integers received as arguments*/
void printcpfactors(int a,int b){
	int temp;
	int lim=minimum(a,b);	//variable lim is initialized to the smaller number
	for(temp=2;temp<=lim;temp++){
		if((a%temp==0)&&(b%temp==0)){
			if(isprime(temp)) printf("%d ",temp);
		}
	}
	printf("\n");
}
/*Program that returns 1 if the integer received is prime and 0 if not*/
int isprime(int x){
	int i;
	for(i=2;i<=sqrt(x);i++){
		if(x%i==0) return 0;
	}
	return 1;
}
/*Program that returns the least integer among the two integers received as arguments*/
int minimum(int a,int b){
	if(a<b) return a;
	else return b;
}
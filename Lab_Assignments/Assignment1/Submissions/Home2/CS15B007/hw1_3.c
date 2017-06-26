#include<stdio.h>

int gcd(int ,int);						//to find gcd of two integers and return it
void primefac(int);					//to find and print prime factors of the passed interger

int main(){
	
	int a,b,c;
	
	scanf("%d%d",&a,&b);
	c=gcd(a,b);
	primefac(c);

	return 0;
}

int gcd(int a ,int b){

	int g;
	for( ; b!=0 ; ){							//division method to find gcd
		g=a%b;
		a=b;
		b=g;
	}
	return a;
}

void primefac(int c){
	
	int i,j,flag=1;
	if(c%2==0){printf("2 ");}
	for(i=3 ; i<=c/2 ; i=i+2,flag=1){
		if(c%i==0){
			for(j=2 ; j<=i/2 ; j++){
				if(i%j==0){
					flag=0;
					break;
				}
			}
			if(flag==1){printf("%d ",i);}
		}
	}
	printf("\n");	
}

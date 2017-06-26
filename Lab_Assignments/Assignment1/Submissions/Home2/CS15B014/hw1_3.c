/*to Determine the common prime-factors of two positive integers.*/
/*name D Teja Vardhan Reddy cs15b014 date 14/8/16*/
#include<stdio.h>
int prime(int);					/*prime function declaration*/
int min(int a,int b){			/*returns minimum of two numbers*/
	if(a<b)
		return a;
	else
		return b;
}
int main(){						/*main function*/
	int a,b,i;
	scanf("%d%d",&a,&b);
	for(i=2;i<=min(a,b);i++)
	{
		if(a%i==0 && b%i==0)
		{
			if(prime(i))			/*calling prime function*/
			printf("%d  ",i);
		}
	}
}
int prime(int n){					/*prime function*/
	int i;
	if(n==2)
	return 1;
	if(n%2==0)
	return 0;
	for(i=3;i*i<=n;i+=2){
		if(n%i==0)
		return 0;
	}
	return 1;
}

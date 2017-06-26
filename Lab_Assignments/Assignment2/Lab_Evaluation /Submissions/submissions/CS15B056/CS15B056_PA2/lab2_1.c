//FIBONACCI SERIES


#include <stdio.h>

int fib(int n);   //Function to calculate fibonnaci by recursion
int main ()
{
	
	int n,i;
	scanf("%d",&n);
	int fibo[n+1],fibr[n+1];
	
	fibo[0]=0;
	fibo[1]=1;
	
	 for(i=1;i<n;i++)    //calculates fibonacci series iteratively 
	 {
	  fibo[i+1]=fibo[i]+fibo[i-1];
	 }
	 
	 for(i=1;i<=n;i++)
	  printf("%d ",fibo[i]);   //prints iterative fibonacci values
	 
	  
	 printf ("\n");
	 
	 
	 for(i=1;i<=n;i++)       //Calculates fibonacci recursively
	 printf("%d ",fib(i));
	
	 
	 
	
	 
}

int fib(int n)
{
	if (n==1)
	 {
	 return 1;              //Exiting conditions
	 }
	else if(n==0)
	 return 0;
	 
	 else
	 {
	 return fib(n-1)+fib(n-2);     // Fibonacci condition
	 
	 }

	 
}	 
	 

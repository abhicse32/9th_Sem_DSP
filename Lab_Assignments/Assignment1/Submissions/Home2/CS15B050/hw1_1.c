						//COde to find Maximum and next maximum ofan array of numbers
						//Author:M.Prasanna Kumar
						//Date:10/08/1997
#include<stdio.h>
int main()
{
int max,nmax;                                   //Max and Next max Variables
int n;                                          //Size of array
scanf("%d",&n);
int arr[n];                                     //Declaring array of size n
int i;
for(i=0;i<n;i++) scanf("%d",&arr[i]);           //Reading array elements
max=arr[0];                                      
nmax=arr[1];
if(arr[0]<=arr[1])                              //
{                                               // 
	max=arr[1];                             //Assigning max and next max to first two elements 
	nmax=arr[0];                            // 
}                                               //
for(i=2;i<n;i++)
{
	if(max<=arr[i])                         //
	{                                       //
		nmax=max;                       //Finding max and next max if max is less than ith element
		max=arr[i];                     //
	}                                       //
	else if(nmax<=arr[i]) nmax=arr[i];	//Updating next max if it is les than ith element	
}
printf("%d %d",max,nmax);                       //Printing max and next max
return 0;
}

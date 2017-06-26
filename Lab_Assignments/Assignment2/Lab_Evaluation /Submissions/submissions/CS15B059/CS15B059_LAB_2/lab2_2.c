/* CS15B059 KOMMURU ALEKHYA REDDY 18AUG2016
TO FIND THE PERMUTATION OF N INTEGERS*/
#include<stdio.h>
void sort(int a[],int n);//prototypes of functions
void swap(int *x,int *y);
int factorial(int no);
void main()
{
	int no;
	printf("Enter the number of digits");
	scanf("%d",&no);//accept the number of integers
	 int fact;
	 fact=factorial(no);//to calculate the number of times the code must be executed
	int i,j,k,a[no];
	for(i=0;i<no;i++)
		{
			scanf("%d",&a[i]);//to input the n integers which we have to permute
		}
 	sort(&a[0],no);
        for(k=0;k<no;k++)
		      printf("%d ",a[k]);//to print the first permutation
		      printf("\n");
	  
	int t;
	for(i=0;i<(fact-1);i++)
	{
	j=no-1;
	while(a[j]<a[j-1])//to find the first pair of elements where a decrease is found
		j--;
	sort(&a[j],no-j);//sort all the elements to the right of this element 
	for(t=j;t<no;t++)
		{
		if(a[j-1]<a[t])
		{
		swap(&a[j-1],&a[t]);//to encounter the first largest number and swap the two numbers
		break;
		}
	}
		for(k=0;k<no;k++)
		      printf("%d ",a[k]);//to print the permutation
	printf("\n");
	}
	

}

//function which sorts the elements given the array index and the size of the array 
void sort(int a[],int n)
{
	int i,j;
	for(i=0;i<(n-1);i++)
	{
		for(j=0;j<(n-1);j++)
		{
		 if(a[j]>a[j+1])
		 	swap(&a[j],&a[j+1]);
		}
	}
	
}

//to swap two numbers by passing their addresses
void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

// calculating the factorial to count the number of times it must be executed
int factorial(int no)
{
	if(no==1)
	  return 1;
	else 
	  return(no*factorial(no-1));  

}

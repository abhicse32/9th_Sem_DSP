/* CS15B059 KOMMURU ALEKHYA REDDY 18AUG2016
TO FIND THE PERMUTATION OF N INTEGERS*/
#include<stdio.h>
void sort(int a[],int n);//prototypes of functions
void swap(int *x,int *y);
int factorial(int no);
void main()
{
	int no;
	//printf("Enter the number of digits");
	scanf("%d",&no);//accept the number of integers
	 int fact;
	 fact=factorial(no);//to calculate the number of times the code must be executed
	int i,j,k,a[no],chk=0,b=0,c=0;
	for(i=0;i<no;i++)
		{
			scanf("%d",&a[i]);//to input the n integers which we have to permute
		}
 	sort(&a[0],no);
        for(k=0;k<no;k++)
		      printf("%d",a[k]);//to print the first permutation
		      printf(" ");
	 for(i=0;i<(no-1);i++)
	 {
	        if(a[i]!=a[1+i])
	        c++;
	 } 
	 if(c==0)
	        b=1;    //to check if all the numbers are same
	int t,p,flag;
	for(i=0;i<(fact-1);i++)
	{
	j=no-1;
	
	while(a[j]<=a[j-1] && j>1)
	{//to find the first pair of elements where a decrease is found
		j--;
		
		}
	//if(j=1 && chk>1)
	//break;	
		
	sort(&a[j],no-j);//sort all the elements to the right of this element 
	for(t=j;t<no;t++)
		{
		if(a[j-1]<a[t])
		{
		swap(&a[j-1],&a[t]);//to encounter the first largest number and swap the two numbers
		break;
		}
	}
	flag=0;
	for(p=0;p<(no-1);p++)
	{
	if(a[p]>=a[p+1])
	        flag++;
	}       
	if(flag==no-1)
	        chk++;  //to check if it is the last element to be printed
	        
	        
	if(chk<=1 && b==0)
	{
		for(k=0;k<no;k++)
		      printf("%d",a[k]);//to print the permutation
		      if(chk==1)
		        b++;	
                printf(" ");
	
	}
	else 
	break;
	
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

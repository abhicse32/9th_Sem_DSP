/*CS15B059 8AUG16 KOMMURU ALEKHYA REDDY
TO FIND MAXIMUM AND MINIMUM IN THE MOST EFFICIENT WAY*/
#include<stdio.h>
#include<stdlib.h>
void main()
{
	int n,i,j;//n stands for the no of integers,i and j are incrementing variables
	scanf("%d",&n);//accepts the number of integers
	int *info=(int *)malloc(sizeof(int)*n);// dynamically allocates memory
	int *max,*min,maxno,minno;
	for(i=0;i<n;i++)
		{
			scanf("%d",info+i);
			 
		}// inputs all values
	
	if(n%2==0)// if n is even then executes this part of the code
	{
		int *min=(int *)malloc(sizeof(int)*n/2);
		int *max=(int *)malloc(sizeof(int)*n/2);//creates two more arrays to store min and max values
		for(i=0,j=0;i<n-1;i=i+2,j++)
			{
			if(*(info+i)<*(info+i+1))
			    {
			       *(min+j)=*(info+i);
			       *(max+j)=*(info+1+i);// compares elements
				
			    }
			else
			    {
			       *(max+j)=*(info+i);
			       *(min+j)=*(info+1+i);
			    }
			
			}
			maxno=*max;
			minno=*min;//assigns the initial value
			
		
		for(i=1;i<n/2;i++)
		{
                       
			if(*(min+i)<minno)
				minno=*(min+i);
			if(*(max+i)>maxno)
				maxno=*(max+i);//swaps value by comparing it 
			 
		}
	}
	
	else// if n is odd this part is executed
	{
	        int *min=(int *)malloc(sizeof(int)*(n/2+1));
		int *max=(int *)malloc(sizeof(int)*(n/2+1));//creates two more arrays to store min and max values
		for(i=0,j=0;i<n-2;i=i+2,j++)
			{
			if(*(info+i)<*(info+i+1))
			    {
			       *(min+j)=*(info+i);
			       *(max+j)=*(info+1+i);// compares elements
			    }
			else
			    {
			       *(max+j)=*(info+i);
			       *(min+j)=*(info+1+i);
			    }
			   
			}
			*(max+n/2)=*(info+n-1);
			*(min+n/2)=*(info+n-1);
			maxno=*max;
			minno=*min;//assigns the initial value
			
		
			for(i=1;i<=(n/2);i++)
		{
		        if(*(min+i)<minno)
				minno=*(min+i);
			if(*(max+i)>maxno)
				maxno=*(max+i);//swaps value by comparing it 
		}
		
			
	}
	
	printf("%d %d",minno,maxno);//prints the maximum and minimum values
}

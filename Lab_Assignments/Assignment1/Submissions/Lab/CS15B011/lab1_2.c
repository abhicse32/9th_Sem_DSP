							/*program to print max and min by Akshay Kumar*/

#include<stdio.h>

void main()
{

	int n,i,max,min,j=0;					/*declaration of variables*/
	scanf("%d",&n);
	int array[n];						/*declaration of array*/
	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	
	if((n%2) == 0)
	{
	int a[n/2 ];
	int b[n/2 ];
	
	for(i=0;i<n;j++)
	{
		if(array[i]>array[++i])
		{ b[j]=array[i];
		  a[j]=array[--i];
		  }
		else 
		{a[j]=array[i];
		b[j]=array[--i];}
		i=i+2;
	
	}
	max = a[0];
	min = b[0];
	for(i=0;i<n/2;i++)
	{
		if(a[i]>max) max=a[i];
		if(b[i]<min) min=b[i];
		
	}	

	}
	else
	{
	n=n-1;
	int a[(n/2)];
	int b[(n/2)];
	
	for(i=0;i<n;j++)
	{
		if(array[i]>array[++i])
		{ b[j]=array[i];
		  a[j]=array[--i];
		  }
		else 
		{a[j]=array[i];
		b[j]=array[--i];}
		i=i+2;
	}
	max = a[0];
	min = b[0];
	for(i=0;i<(n/2);i++)
	{
		if(a[i]>max) max=a[i];
		if(b[i]<min) min=b[i];
		
	}
	if(array[n]>max) max = array[n];
	if(array[n]<min) min = array[n];
	
	}
	
	printf("%d %d\n",min,max);				/*printing min and max*/
		
}



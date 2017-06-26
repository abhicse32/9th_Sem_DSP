
/* 
	Home Assignment1_1question
	CS15B049 lokesh koshale

*/

#include<stdio.h>


/*for storing max and next max no */
struct pair
{
	int max;
	int nextmax;
};


/* declaration of fn for finding max */
struct pair FindMax(int*a,long int size);


int main()
{
	long int n;
	
	struct pair out;	//for output
	
	scanf("%ld",&n);	//scanning n
	
	int arr[n]; 		// array of n elements
	long int i;
	
	/*scanning array elements*/
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	out= FindMax(arr,n); 	//calling fn
	
	printf("%d %d",out.max,out.nextmax);	
	
} // end main



/* function for finding max and next max*/

struct pair FindMax(int*a,long int size)
{
	long int i,j,k;
	int flag=0;		//for storing index of maximum no.
	
	struct pair temp;	
	
	temp.max=a[0]; 		//intilaizing the temp variable to element 0
	temp.nextmax=a[0];
	
	/*loop for assign next max to minimum value in array*/
	for(k=1;k<size;k++)
	{
		if(a[k]<temp.nextmax)
		{
			temp.nextmax=a[k];
		
		}
	}
	
	/* loop for finding max element*/
	for(i=1;i<size;i++)
	{
		if(a[i]>=temp.max)
		{
			temp.max=a[i];
			flag=i;
		}
	}
	
	/*loop for finding next max*/
	for(j=0;j<size;j++)
	{
		if(j==flag)
		{
			continue; 	//escaping the max index
		}
		
		if(a[j]>temp.nextmax)
		{
			temp.nextmax=a[j];
		}
		
	}
	return temp;

} //end fn

 

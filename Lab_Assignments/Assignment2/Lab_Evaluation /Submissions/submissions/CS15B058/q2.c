//Program to print all the permutations of n integers, Author: B Arjun, CS15B058, Date:18/08/16
#include<stdio.h>
#include<stdlib.h>
/*Function to sort an array a of size n using bubblesort algorithm*/
void bubblesort(int a[],int n)
{	
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=1;j<n-i;j++)
		{
			if(a[j]<a[j-1])
				{
					int temp=a[j];
					a[j]=a[j-1];
					a[j-1]=temp;
				}
		}
	}
}

int main(void)
{
	int n;
	scanf("%d",&n);
	int *permute=(int*)malloc(n*sizeof(int));//permute is the array which will be used for storing the integers and permuting it
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&permute[i]);	
	}
	/*First we sort the array of integers, and print the first permutation(integers sorted in ascending order)*/
	bubblesort(permute,n);
	for(i=0;i<n;i++)
	{
		printf("%d",permute[i]);	
	}
	printf(" ");


	int sortsize=0,swapindex1,swapindex2;
	while(sortsize!=n)
	{
		for(i=n-1;permute[i]<=permute[i-1]&&i>0;i--);//To scan array till sudden decrease							
		sortsize=n-i;  //This contains the number of elements, that we must sort.
		swapindex1=i-1; //The index of the number at which the decrease happened is saved in swapindex1.
		if(i!=0)	//To prevent further swapping and printing after last permutation
		{
			for(i=n-1;permute[swapindex1]>=permute[i]&&i>0;i--); //To find the index of the first integer from the right end, whose value is 											higher than the number saved in swapindex1.
			swapindex2=i;
			int temp=permute[swapindex1];   		//For swapping the 2 elements and index1 and index2
			permute[swapindex1]=permute[swapindex2];
			permute[swapindex2]=temp;
			if(sortsize!=1)  //We sort the rest of the elements(if no. of elements is 1 then no need to sort)
			bubblesort(permute+swapindex1+1,sortsize);//The bubblesort starts from swapindex1+1 and size will be sortsize
			for(i=0;i<n;i++)
			{
				printf("%d",permute[i]);	
			}
			printf(" ");
		}
	}
	
	
	
	
}

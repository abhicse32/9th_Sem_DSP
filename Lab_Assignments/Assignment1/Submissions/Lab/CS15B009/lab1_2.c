/* Program to find the minimum and maximum of an integer array
   by Chandrashekhar D    Roll no.CS15B009     8 August 2016 */

#include <stdio.h>

void findMinMax(int num[],int l);

int main()
{
	int n,i;
	scanf("%d",&n);
	int numbers[n];
	for (i=0;i<n;i++)
		scanf("%d",&numbers[i]);
	findMinMax(numbers,n);
	return 0;
}   // End of main function


/*  Function to print the minimum and maximum of an array
	Input parameters : Array num[] and its length l
	Returns: nothing */
void findMinMax(int num[],int l)
{
	int i,max,min,possibleMax,possibleMin;    // Declaration of required variables
	max = num[0];
	min = num[0];
	
	if (l%2 == 1) // If length is odd, drop the last element and divide the rest of the array into possible maxima and minima
	{
		int trunc[l-1];
		
		for (i=0;i<l-1;i++)
			trunc[i] = num[i];
		for (i=0;i<l-1;i=i+2)
		{
			if (trunc[i]>trunc[i+1])
			{
				possibleMax = trunc[i];
				possibleMin = trunc[i+1];
			}
			else
			{
				possibleMax = trunc[i+1];
				possibleMin = trunc[i];
			}
			if (possibleMax>max)
				max = possibleMax;
			if (possibleMin<min)
				min = possibleMin;
		}
		
		if (num[l-1]>max)  // Check the last (dropped) element
			max = num[l-1];
		if (num[l-1]<min)
			min = num[l-1];
	}
	
	else         // If length is even, divide the array into possible maxima and minima
	{
		for (i=0;i<l;i=i+2)
		{
			if (num[i]>num[i+1])
			{
				possibleMax = num[i];
				possibleMin = num[i+1];
			}
			else
			{
				possibleMax = num[i+1];
				possibleMin = num[i];
			}
			if (possibleMax>max)
				max = possibleMax;
			if (possibleMin<min)
				min = possibleMin;
		}
		
	}
	printf("%d %d",min,max);	// Print the minimum and maximum
}














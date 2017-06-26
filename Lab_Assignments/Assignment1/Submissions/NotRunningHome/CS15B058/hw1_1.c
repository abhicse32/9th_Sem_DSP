//Program to find the maximum and next maximum of an array
//Author: B Arjun, CS15B058; Date:10/08/16
#include<stdio.h>
#include<stdlib.h>

/*findmax is a function which takes an array and its size as parameters and implements the 
tournament data structure and stores maximum in first element, array[1]*/
void findmax(int array[],int size)
{
	int i;
	for(i=size-1;i>=1;i--)
	{
		if(array[2*i]>array[2*i+1])
			array[i]=array[2*i];
		else
			array[i]=array[2*i+1];
	}
}

int main(void)
{
	int n;
	scanf("%d",&n);
	int *array=(int*)malloc((2*n)*sizeof(int));
	int i,j;

	//Inputting the values from the end of the array
	for(i=2*n-1;i>(n-1);i--)
	{
		scanf("%d",&array[i]);
	}

	//Finding the Maximum
	findmax(array,n);

	int maximum=array[1];
/*Finding the losers to Maximum. 
For implementing the tournament data structure for losers we have to make a separate array 
called loserarray with size equal to 2*(no. of losers). Since we have to find the no. of losers first, 
we need to store it in a temparray first*/
	int *temparray=(int*)malloc((2*n)*sizeof(int));
	i=1;
	j=0;
	int losersize=0;
	while((array[2*i]==maximum||array[2*i+1]==maximum)&&(2*i+1<2*n))
	{
		if(array[2*i]==maximum)
			{
				temparray[j]=array[2*i+1];
				j++;
				i=2*i;
				losersize++;
			}
		else if(array[2*i+1]==maximum)
			{
				temparray[j]=array[2*i];
				j++;
				i=2*i+1;
				losersize++;
			}
	}
//We copy the values from the temparray to the loserarray. losersize is the no. of losers to the maximum.
	int *loserarray=(int*)malloc((2*losersize)*sizeof(int));
	for(i=2*losersize-1,j=0;j<losersize;i--,j++)
	{
		loserarray[i]=temparray[j];
	}
	
	findmax(loserarray,losersize);

	int nextmaximum=loserarray[1];
	printf("%d %d",maximum,nextmaximum);
	return 0;

}

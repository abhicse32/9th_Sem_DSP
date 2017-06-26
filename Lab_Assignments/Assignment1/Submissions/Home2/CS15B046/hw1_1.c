/*A program to calculate MAX and NEXT_MAX among the entered elements
  Author:CS15B046 Jahnvi Patel
  Date:August 9, 2016 */

#include <stdio.h>

/*A function that calculates MAX in c*n time and NEXT_MAX in c*logn time
  Parameters: the arrayof integers, no. of entries by user */

void find(int arr[],int n)
{
	int i;
	int max,next_max;
	for(i=2*n-2;i>1;i-=2)
	{
		if(arr[i]>arr[i+1])
			arr[i/2]=arr[i];
		else 
			arr[i/2]=arr[i+1];
	}
	max=arr[1];
	/*We found MAX using tournament method comparing adjacent cells
	  Takes c*n time */
	i=1;
	if(arr[2]>arr[3])
		next_max=arr[3];
	else next_max=arr[2];
	/*MAX can win only if it has been compared with NEXT_MAX so we check only those numbers that were compared with MAX
	  Takes c*logn time */
	while(i<2*n)
	{
		if(arr[i]>arr[i+1]) {
			if(arr[i+1]>next_max)
				next_max=arr[i+1];
		                    }
		else {
			if(arr[i+1]>next_max)
				next_max=arr[i];
			 }
		i*=2;

	}
	//OUTPUT

	printf("%d %d\n",max,next_max);
}

void main()
{   int i,n;
	scanf("%d",&n);
	int arr[2*n];
	//INPUT
	for(i=n;i<=2*n-1;i++)
		scanf("%d",&arr[i]);
	arr[0]=arr[1];
	find(arr,n);
}
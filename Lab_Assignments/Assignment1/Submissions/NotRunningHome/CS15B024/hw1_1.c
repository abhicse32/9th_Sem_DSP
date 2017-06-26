#include <stdio.h>
int main()
{
int i;	//i is used as the index of the array elements
int n;
int max;
int nextmax;
printf("enter the value of n"); //n is the size of array a
scanf("%d",&n);
int a[n];
printf("enter the values of array");
for(i=0;i<n;i++)
{
	scanf("%d",&a[i]);	//giving array as input
}
max=a[0],nextmax=a[1]; 		//initiating max as the first element of array and nextmax as second element of array
if(max>nextmax)
	{
		max=a[0];
		nextmax=a[1];
	}
if(max<nextmax)
	{
		max=a[1];
		nextmax=a[0];
	}
	for(i=2;i<n;i++)	//running through the loop and updating the value of max and nextmax
	{
		if(max<a[i])
		{
			nextmax=max;
			max=a[i];
		}
		else if(nextmax<a[i])
		{
			nextmax=a[i];
		}
	}	
		printf("%d %d",max,nextmax);	//printing max and nextmax
}

		

		
	
	
	

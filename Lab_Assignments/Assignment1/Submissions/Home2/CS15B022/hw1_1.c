#include<stdio.h>
int main()
{
	int arr[100000];
	int n;
	scanf("%d",&n);
	int j = 0;
	for(j = 0;j < n;j++)
		{
			scanf("%d",&arr[j]);
		}
	int max;
	int nextmax;
	int i = 2;
	if(arr[0]>arr[1])
	{
		max = arr[0];
		nextmax = arr[1];
	}
	else
	{
		max = arr[1];
		nextmax = arr[0];
	}
	
	for(i = 2;i<n;i++)
	  {
	    if(arr[i] > max)
	      {
		nextmax  = max;
		max = arr[i];
	       }
           
	   else
	      {
		if(arr[i] > nextmax)
		  {
		    nextmax = arr[i];
		   }
               }
            }
	printf("%d ",max);
	printf("%d",nextmax);
 	return 0;
}
	

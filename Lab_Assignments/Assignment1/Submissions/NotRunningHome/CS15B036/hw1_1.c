#include<stdio.h>
int main()
{
	int n;
	int i;
	scanf("%d",&n);
	int arr[n];
	int max;
	int nmax;
	for(i=0;i<n;i++)
	{
	scanf("%d",&arr[i]);
    }
    if(arr[0]>=arr[1])
    {
	
    max=arr[0];
    nmax=arr[1];
    }
    else
    {
    max=arr[1];
    nmax=arr[0];	
	}
	for(i=0;i<n;i++)
	{
		if(arr[i]>=nmax)
		{
			if(arr[i]>=max)
			{   
			    nmax=max;
				max=arr[i];
				
			}
			else
			{
				nmax=arr[i];
			}
		}
		
	}
	printf("%d %d",max,nmax);
	return 0;
	
	
    
}

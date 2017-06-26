//Lab1 assignment 2 max and min in an array by Raghavan S CS15B034
#include<stdio.h>
/*function to calculate and return minimum in an integer array p of size n)
*/
int minc(int n,int p[])
{
int i;
int min=p[0];
for(i=1;i<n;i++)
	if(p[i]<min)
		min=p[i];
return min;
}
/*function to calculate and return maximum in an integer array p of size n)
*/
int maxc(int n,int p[])
{
int i;
int max=p[0];
for(i=1;i<n;i++)
	if(p[i]>max)
		max=p[i];
return max;
}

int main()
{
int arr[2000];//input array
int minarr[1000];//arraywithsmallerones
int maxarr[1000];//arraywithbiggerones
int min;//minimum
int max;//maximum
int lc=0;//minarr counter
int n;//size of array
scanf("%d",&n);
int i;//counter
if(n<=0)
printf("size should be positive");	//making sure input size is positive
else
{
for(i=0;i<n;i++)			//scanning array
scanf("%d",&arr[i]);
	if(n==1)				
	min=max=arr[0];				
	else
	{
	for(i=1;i<=n-1;i=i+2)
	{
	if(arr[i]>arr[i-1])
	{
	minarr[lc]=arr[i-1];
	maxarr[lc]=arr[i];		//comparing and separating winners from losers in each assignment
	}
	else
	{
	minarr[lc]=arr[i];
	maxarr[lc]=arr[i-1];
	}
	lc++;
	}
	max=maxc(n/2,maxarr);
	min=minc(n/2,minarr);
	if(n%2==1)
	{
		if(max<arr[n-1])
		max=arr[n-1];
		if(min>arr[n-1])
		min=arr[n-1];
	}
	}		
		
printf("%d %d",min,max);	
}
return 0;
}

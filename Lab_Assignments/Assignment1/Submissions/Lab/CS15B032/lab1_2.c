/*
Program to operate on array of numbers find min, max
and print the result
cs15b032
8/7/16
*/

#include<stdio.h>

/*
Recursive function to selectively sort the array to find max and min
*/
void maxmin(int n, int *a, int k)
{	
int i,p=(k+1)/2,temp;
if(k!=1)
	{
	for(i=0;i<p;i++)//Finding the min in first k numbers and moving to k/2
		{
		if(a[i]>a[k-1-i])
			{
			temp=a[i];
			a[i]=a[k-1-i];
			a[k-i-1]=temp;
			}
		}
	if(k!=n);
		for(i=0;i<p;i++)//Finding the max in last k numbers and moving to k/2
			{
			if(a[n-i-1]<a[n-(k-i)])
			{
			temp=a[n-i-1];
			a[n-i-1]=a[n-(k-i)];
			a[n-(k-i)]=temp;
			}
		}
	maxmin(n,a,p);
	}
else
 printf("%d %d",a[0],a[n-1]);


}

int main()
{
int num;
int a[100];//array to hold input

scanf("%d",&num);
int i;
	for(i=0;i<num;i++)
	{
	scanf("%d",&a[i]);
	}
maxmin(num,a,num);//passed by reference. Operated value reflects in the original array



}

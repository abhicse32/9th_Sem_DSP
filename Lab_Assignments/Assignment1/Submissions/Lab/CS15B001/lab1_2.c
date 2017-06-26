#include<stdio.h>

/*
This function calculates max and min of a given array in 3n/2 operations

Ameet S Deshpande
CS15B001
*/

int main()
{
void find_min(int* a,int n);
void find_max(int* a,int n);

int n,a[100];	//Input array and size
int i;

scanf("%d",&n);	//Read the array size from the user

for(i=0;i<n;++i)
{
	scanf("%d",&a[i]);	//Read the values from the user
}


find_min(a,n);	//Prints minimum
return 0;

}


void find_min(int* a,int n)
{
/*This function calculates the minimum and gives control to another
function to find maximum
*/

if(n==0)
{
	return;
}

if(n==1)
{
	printf("%d %d\n",a[0],a[0]);
	return;
}



void find_max(int*,int);
int choice=0,min=32768,i;


for(i=0;i<n-1;i=i+2)	//Checking adjacent elements
{

	if(a[i]>=a[i+1])
	{

		if(a[i+1]<min)	//Calculating minimum in this traversal itself
		{
			min=a[i+1];
		}

		a[choice]=a[i];
		choice++;
	}


	if(a[i]<a[i+1])
	{

		if(a[i]<min)
		{
			min=a[i];
		}

	a[choice]=a[i+1];
	choice++;
	}

}



if(n%2==1)	//Adding last element to both sets if array size is odd
{
	a[choice]=a[n-1];
	if(a[choice]<min)
	{
		min=a[i+1];
	}
	n=n/2+1;
}
else
{
	n=n/2;
}

printf("%d ",min);
find_max(a,n);

}



void find_max(int* a,int n)
{

/*This function calculates the maximum
*/

int choice=0,i;
if(n==1)
{
	printf("%d\n",a[0]);
	return;
}
else
{

	for(i=0;i<n-1;i=i+2)	//Checking adjacent elements
	{
	
		if(a[i]>=a[i+1])
		{

			a[choice]=a[i];
			choice++;
		}



		if(a[i]<a[i+1])
		{

			a[choice]=a[i+1];
			choice++;
		}


	}

	if(n%2==1)	//Adding last element to both sets if array size is odd
	{
		a[choice]=a[n-1];
		n=n/2+1;
	}

	else
	{
		n=n/2;
	}

	find_max(a,n);

}

}







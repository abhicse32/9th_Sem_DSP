/*  Program to determine if two input strings are anagrams or not
	By  Chandrashekhar D   CS15B009   Programming Home Assignment 1  */   

#include <stdio.h>
#include <string.h>   // Importing required libraries

/*  Function to sort an integer array in ascending order using Insertion sort algorithm :
	Input parameters : arr, the integer array and l, its length
	Returns : nothing  */
void isort(int arr[],int l)
{
	int i,j,minind,tmp;
	for(i=0;i<l;i++)
	{
		tmp=arr[i];
		j=i-1;
		while(tmp>arr[j]&&j>=0)
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=tmp;
		
	}
}

/*  Function to determine if two integer arrays are identical :
	Input parameters : Two arrays a and b, their length l
	Returns : 1 if they are identical, 0 otherwise  */
int isEqual(int a[],int b[],int l)
{
	int i;
	for (i = 0;i<l;i++)
	{
		if (a[i]!=b[i])
			return 0;
	}
	return 1;
}

/*  Main function */
int main()
{
	char a[100],b[100];
	scanf("%s %s",a,b);  // Taking two strings as input
	int l1,l2,i;
	l1 = strlen(a);      // Finding length of both strings
	l2 = strlen(b);
	if (l1 != l2)        // Checking if both strings are of same length
	{
		printf("0");
		return 0;
	}
	int s1[l1],s2[l2];   
	for (i = 0;i<l1;i++) // Converting the string into corresponding integer array by type casting
	{
		s1[i] = (int)a[i];
		s2[i] = (int)b[i];
	}
	isort(s1,l1);
	isort(s2,l2);        // Sorting the integer arrays uniformly

	if (isEqual(s1,s2,l1) == 1)   // Checking if the sorted arrays are identical, thereby if original strings are anagrams
		printf("1");
	else
		printf("0");
	return 0;

}

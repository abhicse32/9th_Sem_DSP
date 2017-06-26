// Home Assignement 1 Question 4
// Checking whether 2 entered strings are anagrams or not
// Author : Milind Srivastava
// Date : 9 Aug 2016

#include <stdio.h>
#include <string.h>

int compare (const void * a, const void * b) // compare function for qsort
{
  return ( *(int*)a - *(int*)b );
}

int main()
{
	char s1[101],s2[101];
	int s1int[101], s2int[101];

	scanf("%s",s1);
	scanf("%s",s2);

	int i=0;

	// Converting both strings to equivalent integer arrays

	for(i=0;i<strlen(s1);i++)
		s1int[i] = (int)(s1[i]);

	for(i=0;i<strlen(s2);i++)
		s2int[i] = (int)(s2[i]);

	// Sorting both integer arrays

	qsort(s1int,strlen(s1),sizeof(int),compare);
	qsort(s2int,strlen(s2),sizeof(int),compare);

	// Checking if both integer arrays are identical after sorting

	for(i=0;i<strlen(s1) || i<strlen(s2);i++)
	{
		if(s1int[i] != s2int[i])
		{
			printf("%d",0);
			return 0;
		}
	}

	printf("%d",1);
	
	return 0;
}
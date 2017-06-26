/*

Author Name: Gudur Phani Karan Reddy (EE13B077)
Time: Mon Aug  8 20:55:25 IST 2016

Description:
This program implements an abstract data type for complex numbers, takes 2 complex numbers as input
and defines functions to perform basic mathematical operations on them.

*/



#include <stdio.h>


int main()

{
	int well[100];

	int n,i; 

	do
	{
		printf("No. of integers? \n");
		scanf("%d", &n);

	}while(n < 1);

	for(i=0;i<n;i++)
		scanf("%d", &well[i]);

	int max = well[0];
	int min = well[0];

	for(i=1;i<n;i++)
	{	
		if(max < well[i])
			max = well[i];

		if(min > well[i])
			min = well[i];
	}

	printf("%d %d \n", min, max);

	return 0;
}






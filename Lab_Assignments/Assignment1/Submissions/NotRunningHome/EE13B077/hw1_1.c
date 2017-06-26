
/*

Author Name: Gudur Phani Karan Reddy (EE13B077)
Time: Sun Aug 14 20:21:36 IST 2016

Description:
This program takes a list of integers as an input and outputs the maximum and secon maximum integer of the lot, respectively.

*/



#include <stdio.h>


int main()

{
	int well[100000];

	int n,i; 

	do
	{
		printf("No. of integers? \n");
		scanf("%d", &n);

	}while(n < 1);

	for(i=0;i<n;i++)
		scanf("%d", &well[i]);

	int max = well[0];

	int second_max = well[0];

	for(i=1;i<n;i++)
	{	
		if(max < well[i])
		{
			second_max = max;
			max = well[i];

		}

	}

	printf("%d %d \n", max, second_max);

	return 0;
}


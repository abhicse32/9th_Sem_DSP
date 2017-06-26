#include<stdio.h>

int main()
{
	int a[100],n,i;
	int min,max;
	scanf("%d",&n);		//scan number of elements

	for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);		//scan elements
		}

	min = a[0];			//assigning initial value as array's first value rather than 0 to decrease comparison
	max = a[0];

	for(i=1;i<n;i++)		//no need to check for index 0,hence starting from 1.
		{
			if(a[i]>max) 		//here, including of whole if..else statements will reduce comparison. 
			max = a[i]; 		//because a number can't be both max and min.
			else if(a[i]<min)
			min = a[i];
		}

	printf("%d %d\n",min,max);

	return 0;
}



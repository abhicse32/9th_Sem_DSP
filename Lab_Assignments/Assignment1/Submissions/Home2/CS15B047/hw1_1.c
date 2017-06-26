#include <stdio.h>

int main(void) 
{
	long int n;
	long int i;
	int max,nextmax;
			
	scanf("%ld",&n); //Take number of input elements
	
	int num[n];
	
	for(i=0;i<n;i++)
		scanf("%d",&num[i]); // Take elements from user
	
	//Set initial values to max and nextmax from 1st 2 elements of array
	
	if(num[0]>num[1])
	{
		max=num[0];
		nextmax=num[1];
	}
	else
	{
		max=num[1];
		nextmax=num[0];
	}
        /*
        Always max >= nextmax
        3 cases possible for each number in array
        number > max
        max >= number > nextmax
        nextmax >= number
        */
	for(i=2;i<n;i++)
	{
		if(num[i]>max) // case 1
		{
			nextmax=max; // Update nextmax to current max value 
			max=num[i];  // Update max value to num[i]
		}
		else if(num[i]>nextmax) //case 2
		{
			nextmax=num[i]; // Update nextmax to num[i]
		}
		//case 3 doesnt change max and nextmax
	}
	
	printf("%d %d\n",max,nextmax); //Print max and nextmax
	return 0;
}


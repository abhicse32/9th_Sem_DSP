#include<stdio.h>

int main()
	{
		int n;		/*for declaring the number of terms*/
		scanf("%d",&n);
		int array[n];		/*for storing the numbers*/
		int i;		/*for counting the iterations*/

		if ( n==1 ) {
						int num;
						scanf("%d",&num);	/*Since if there is only one number then, it is only max and min*/
						printf("%d %d",num,num);
					}
						
		
	else{	for( i = 0; i < n; i++ )
			{
				scanf("%d",&array[i]);	
				if ( (i%2)!=0 ) {			/*here we are writing as a comparision between even and odd element*/
									if ( array[i-1] > array[i] ) {
																	int tempelement;
																	tempelement = array[i-1];
																	array[i-1] = array[i];
																	array[i] = tempelement;
																	
																	
																 }
								}
			}
		int min = array[0];	/*declaring a minimum element*/
		int max = array[1];	/*declaring a maximum element*/

		for( i = 0; i < n; i++)
			{
				if ( i%2 == 0 )	{ 
									 if ( array[i] < min ) min = array[i];
								}
				else {	
						if ( array[i] > max ) max = array[i];
					 }					
			}
		
		
	
		if ( max < array[n-1] ) max = array[n-1];
		
		printf("%d %d", min, max);	/*Printing a maximum and minimum element */

	
	  }
	return 0;
	}
	


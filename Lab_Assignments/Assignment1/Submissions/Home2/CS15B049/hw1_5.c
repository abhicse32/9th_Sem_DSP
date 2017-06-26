/* 
	Home Assignment1_5 question
	CS15B049 lokesh koshale

*/

#include<stdio.h>


/*decalring fn*/
double sqrt1( long int x);


int main()
{
	long int n;		//storing the input
	
	double y;		
	
	scanf("%ld",&n);	//input the number
	
	y= sqrt1(n);		//calling the fn
	
	printf("%0.15lf",y);		//printing the root upto 15 decimal places
	
	return 0;
	
} 		// end main



/* finding root by newtons method */
double sqrt1( long int x)
{
	double gues = 1; 	//initial guess for root
	
	
	int k,maxk=100; 	//variables and no of iteration
	
	
	/*aproxmimating the root by iteration*/
	for(k=0;k<maxk;k++)
	{
		gues = gues -( (gues*gues - x)/(2*gues) ) ;  	//newtons approximation
	
	}
	
	return gues;	//returning value
	
} //end fn

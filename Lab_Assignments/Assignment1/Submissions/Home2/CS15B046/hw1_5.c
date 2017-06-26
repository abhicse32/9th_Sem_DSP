/* A program to calculate square root of entered integer.
   Author:CS15B046 Jahnvi Patel
   Date:August 10, 2016 */

#include <stdio.h>
/* A funvtion that uses Newton Raphson method for square root calculation where f(x)=x^2 here
   Return value: Square root
   Parameters:the number whose square root is to be calculated*/


double squareroot(int n)
{   double root=1;
	int i;
	
	while(root*root-n>=0.000000001||n-root*root>=0.00000000001)
		root=(n/root+root)/2;
	return root;
	
}

void main()
{
	int n; //input number
	scanf("%d",&n);
	printf("%.15lf",squareroot(n));
}
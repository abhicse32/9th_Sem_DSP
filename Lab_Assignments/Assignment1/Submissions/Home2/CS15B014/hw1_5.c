/*to calculate the square root of an integer precisely upto 15 digits
after decimal point*/
/*name D Teja Vardhan Reddy cs15b014 date 14/8/16*/
#include<stdio.h>
int main(){					/*main function*/
	double n;int i;
	scanf("%lf",&n);
	double mid;				/*using binary search instead of newton raphson  method*/
	if(n>1){				/*case n is more than one*/
		double low,high;
		high=n;
		low=1;
		for ( i = 0; i < 200; ++i)
		{	
			mid=(high+low)/2;

			if(mid*mid<n){
				low=mid;
			}
			else
			{
				high=mid;
			}

		}
	}
	else if(n<1)			/*case n<1*/
	{
		double low,high;
		high=1;
		low=n;
		for ( i = 0; i < 200; ++i)
		{	mid=(high+low)/2;
			 
			if(mid*mid<n){
				low=mid;
			}
			else
			{
				high=mid;
			}
		}
	}
	else{					/*CASE N==1*/
		 mid=1;
	}
	printf("%.15lf\n",mid);
}

/*

Author Name: Gudur Phani Karan Reddy (EE13B077)
Time: Sun Aug 14 21:15:45 IST 2016

Description:
This program takes an integer as an input and outputs its squareroot upto 15 decimal places.

*/



#include <stdio.h>

double msqrt(int x)
	{
        int prev,k = 0;
        double s = 1;
        for(k=0; k<1000; k++)
        {
                prev = s;
                s = (s + x/s)/2;
                if(prev == s)
                    break;
         
        }
        return s;
	}



int main()

{
	int n;
	scanf("%d", &n);

	printf("%.15lf\n", msqrt(n));	
	return 0;
}


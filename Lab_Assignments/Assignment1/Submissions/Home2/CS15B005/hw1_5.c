#include<stdio.h>
/* Driver program to test above function*/
int main()
{
    int n;
    scanf("%d",&n);
    double x = n;
    double y = 1;
    double e = 0.0000000000001; /* e decides the accuracy level*/
    while(x - y > e)
    {
    	x = (x + y)/2;
    	y = n/x;
    }
    printf("%.15lf",x);
    return 0;
}

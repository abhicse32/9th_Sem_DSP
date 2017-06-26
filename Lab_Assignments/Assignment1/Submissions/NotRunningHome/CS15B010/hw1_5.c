#include<stdio.h>
#include<math.h>

int main(){
	double n;
	scanf("%lf",&n);
	double x=n/2;
	do{
		x=x-(x*x-n)/(2*x);
	}while(fabs(n-x*x)>0.000000000000001);

	printf("%0.15lf",x);
	return 0;
}

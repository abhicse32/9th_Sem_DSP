#include<stdio.h>

int main(){

	int n;
	double a,b,diff;
	scanf("%d",&n);
	a=n;
	b=1;
	diff=0.0000000000001;				//for accuracy upto 15 digits
	for( ;a-b>diff ; ){								//newton ralphsons method
		a=(a+b)/2;
		b=n/a;
	}
	
	printf("%.15lf",a);
	return 0;
}

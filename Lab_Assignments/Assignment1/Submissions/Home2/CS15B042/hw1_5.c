#include <stdio.h>
double ab(double b){
	if(b > 0) return b;
	else return (-1*b);
}

int main(){
	int n;
	scanf("%d",&n);
	double x = 1.0;
	double b = 15.0;
	while(ab(b) > 0.00000000000001){
		b = ((x*x) - n)/(2*x);
		//printf("%.15f\n",b);
		x = x - b;
	}
	printf("%.15lf\n",x);
	return 0;
}

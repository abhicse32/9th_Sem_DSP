#include <stdio.h>
int main(int argc, char const *argv[])
{
	int n,i;
	scanf("%d",&n);

	double s=(double)(n/2);
	for(i=0;i<20;i++){

		s = (double) (s+ (double)(n/s))/2;

	}

	printf("%.15lf\n",s);


	return 0;
}
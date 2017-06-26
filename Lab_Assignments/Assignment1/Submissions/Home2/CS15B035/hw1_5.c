#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	double sqrt=(double)(n/2);
	int i;
	for(i=0;i<=20;i++){
		sqrt=(sqrt+n/sqrt)/2;
	}
	printf("%.15lf\n",sqrt);
	return 0;
}

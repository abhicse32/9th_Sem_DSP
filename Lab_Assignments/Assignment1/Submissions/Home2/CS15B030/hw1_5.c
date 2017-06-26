/*
 * Using Newton-Rapshon method
 */
#include <stdio.h>

int main() {
	int num;
	scanf("%d", &num);
	double sqrt = (double)num / 2; //Taking something to start with
	int i;
	for(i=0;i<20;i++){
		sqrt = (sqrt + num/sqrt)/2;
	}
	printf("%.15lf\n",sqrt);
	return 0;
}

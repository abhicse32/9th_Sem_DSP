#include <stdio.h>
long double sqrt_(int n){	
	long double res=1;
	int counter=0;
	while(counter<10000){
		res=(res+n/res)/2;
		counter++;
	}
	return res;
}

int main(){
	int m;
	scanf("%d",&m);
	printf("%.15llf\n",sqrt_(m));
}
#include <stdio.h>
double sqrt_(int n){	
	double res=n;
	double im=1;
	double error=0.0000000000001;
	while(res - im > error){
		res=(res+im)/2;
		im=(n/res);
	}
	return res;
}

int main(){
	int m;
	scanf("%d",&m);
	printf("%.15lf\n",sqrt_(m));
}
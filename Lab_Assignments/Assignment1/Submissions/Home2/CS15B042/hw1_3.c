#include <stdio.h>
#include <math.h>

int prime(int x){
	int i;
	if(x == 2) return 1;
	
	if( x % 2 == 0) return 0;

	for(i = 3;i <= sqrt(x);i+=2){
		if(x % i == 0) return 0;
	}
	return 1;
}

int main(){
	int n1,n2,i;
	fscanf(stdin,"%d%d",&n1,&n2);
	int min;

	if(n1 < n2) min = n1;
	else min = n2;	

	for(i = 2;i <= min;i++){
		if(n1 % i == 0 && n2 % i == 0 && prime(i) == 1){
			fprintf(stdout,"%d ",i);
		}
	}
	
	fprintf(stdout,"\n");
}

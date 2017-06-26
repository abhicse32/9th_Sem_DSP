/*Square root
__author__='Vishal'
Date=14/08/2016*/

#include<stdio.h>
#define error 0.000000000000001
int main(){
	int n;
	double prev_val, new_val, sroot;
	scanf("%d", &n);
	new_val = n/2.0;
	do{
		prev_val = new_val;
		new_val = (prev_val + n/prev_val)/2;
	}while((prev_val-new_val)>error);
	sroot = new_val;
	printf("%.15lf", sroot);
	return 0;	
}

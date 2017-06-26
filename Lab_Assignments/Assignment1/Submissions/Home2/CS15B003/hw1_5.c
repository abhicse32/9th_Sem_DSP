#include<stdio.h>

int main(){
	
	double n, i, root;
	double a = 0.0, b = 50.0, c = 100.0;
	
	scanf("%lf",&n);
		
	for(i = 0; i < 60; i++){

		if(((a*a)<n)&&(n<(b*b))){
			a = a; c = b; b = a/2 + b/2;
 		}
 		
 		else{
			a = b; b = b/2 + c/2; c = c;
		 }
		  
	}
	
		root = a/2 + c/2;
	printf("%0.15f\n",root);
}

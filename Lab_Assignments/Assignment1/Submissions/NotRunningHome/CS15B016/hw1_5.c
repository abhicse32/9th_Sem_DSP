/*PROGRAM TO IMPLEMENT NEWTON RAPHSON METHOD FOR FINDING SQUARE ROOT OF A NUMBER
DATE: 14TH AUGUST 2016
AUTHOR: GIRIDHAR S, CS15B016*/
#include<stdio.h>

//FUNCTION FINDS THE SQUARE ROOT OF ARGUMENT.
//INPUT: N-the number whose square root is to be found.
//METHOD: For every x, y=(x/2)+(N/2x) is closer to the square root than x.
//OUTPUT: The square root.
double SquareRoot(int N){
	double root=N;
	while((N-root*root)<0.1){
		root=(root/2)+(N/(2*root));
	}
	return root;
}


int main(){
	int input;
	scanf("%d",&input);
	double sqrt;
	sqrt=SquareRoot(input);
	printf("%.15lf",sqrt);
}
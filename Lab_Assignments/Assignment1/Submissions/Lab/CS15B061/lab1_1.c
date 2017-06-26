/* Program to implement Complex ADT with functions to add , subtract, multiply, divide, and find distance between two points.

Author : Harshavardhan.P.K. (CS15B061)
Date: Aug 8,2016

*/



#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Structure of Complex ADT, real- real component, img- imaginary component.
typedef struct{
	double real;
	double img;
}Complex;

void add (Complex *, Complex *);
void sub (Complex *, Complex *);
void mult (Complex *, Complex *);
void divd (Complex *, Complex *);
double dist (Complex *, Complex *);
void printcomplex (Complex *);



/* 
Main function to input choices and numbers iteratively until sentinal value (0 or -1) is typed as a choice)
*/
int main(void){

Complex n1, n2, *ans;
int choice;
double ans2;
do{
	scanf("%lf%lf%lf%lf",&(n1.real),&(n1.img),&(n2.real),&(n2.img));
	
	scanf ("%d",&choice);
	switch (choice){
	case 1:  add(&n1,&n2); break;
	case 2:  sub(&n1,&n2); break;
	case 3:  mult(&n1,&n2); break;
	case 4:  divd(&n1,&n2); break;
	case 5: printf ("%.6lf\n",dist(&n1,&n2)); break;

	}

	
	}while (!(choice == -1 || choice == 0));

return 0;
}


/* 
Add 2 Complex Numbers
Paameters: num1- Pointer to 1st number
num1- Pointer to 1st number

Prints the answer and return nothing
*/
void add (Complex *num1, Complex *num2){
	
	Complex ans;
	ans.real = (*num1).real + (*num2).real;
	ans.img = (*num1).img + (*num2).img;
	printcomplex (&ans);
}



/* 
Subtract 2 Complex Numbers
Paameters: num1- Pointer to 1st number
num1- Pointer to 1st number

Prints the answer and return nothing
*/
void sub (Complex *num1, Complex *num2){
	Complex ans;
	ans.real = (*num1).real - (*num2).real;
	ans.img = (*num1).img - (*num2).img;
	printcomplex (&ans);
}



/* 
Multiply 2 Complex Numbers
Paameters: num1- Pointer to 1st number
num1- Pointer to 1st number

Prints the answer and return nothing
*/
void mult (Complex * num1, Complex * num2){
	Complex ans;
	ans.real = ((*num1).real*(*num2).real) - ((*num1).img*(*num2).img);
	ans.img = ((*num1).img * (*num2).real) + ((*num2).img*(*num1).real);
	printcomplex (&ans);
}


/* 
Distance Between 2 Complex Numbers
Paameters: num1- Pointer to 1st number
num1- Pointer to 1st number

Returns the Distance
*/
double dist (Complex *num1, Complex *num2){
	return sqrt (((*num1).real-(*num2).real)*((*num1).real-(*num2).real) + ((*num1).img-(*num2).img)*((*num1).img-(*num2).img));
}



/* 
Divide 2 Complex Numbers
Paameters: num1- Pointer to 1st number
num1- Pointer to 1st number

Prints the answer and return nothing
*/
void divd (Complex * num1, Complex * num2){
	Complex ans, conj2;
	double abssq = (*num2).real*(*num2).real + (*num2).img*(*num2).img;
	conj2.real=(*num2).real/abssq;
	conj2.img=(-(*num2).img)/abssq;
	 mult(num1,&conj2);
	

}
/* 
Print Complex Numbers
Paameters: num1- Pointer to 1st number

Prints the answer and return nothing
*/
void printcomplex(Complex* num){
	printf("%f",(*num).real);
	if((*num).img<0)
		printf("%lfi\n",(*num).img);
	else
		printf("+%lfi\n",(*num).img);
}





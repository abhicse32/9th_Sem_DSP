/*
Operations on Complex Numbers
__author__= 'Vishal'
__date__= 08/08/16
*/

#include <stdio.h>
#include <math.h>

typedef struct Complex{
	float real;
	float img;
}complex; 

complex Addition (complex, complex);
complex Subtraction (complex, complex);
complex Multiplication (complex, complex);
complex Division (complex, complex);
float Distance (complex, complex);
void print_comp (complex);

int main(){
	
	complex c1;
	complex c2;
	complex res;
	int menu;
	float dist;

	do{
		scanf("%f%f", &c1.real, &c1.img);
		scanf("%f%f", &c2.real, &c2.img);
		scanf("%d", &menu);
		if (menu==1){
			res = Addition(c1, c2);
			print_comp(res);}
		else if (menu==2){
			res = Subtraction(c1, c2);
			print_comp(res);}			
		else if (menu==3){
			res = Multiplication(c1, c2);
			print_comp(res);}			
		else if (menu==4){
			res = Division(c1, c2);
			print_comp(res);}			
		else if (menu==5){
			dist = Distance(c1, c2);
			printf("%.6f", dist);
			}
	}while(menu!=0 && menu!=-1);


	return 0;
}

/* Performs addition of complex numbers
Input = 2 complex numbers
Output = Sum of the complex numbers
*/ 
complex Addition (complex c1, complex c2){
	
	complex sum;
	sum.real = c1.real + c2.real;
	sum.img = c1.img + c2.img;
	return sum;
}

/* Performs subtration of complex numbers
Input = 2 complex numbers
Output = Sum of the complex numbers
*/ 
complex Subtraction (complex c1, complex c2){
	
	complex dif;
	dif.real = c1.real - c2.real;
	dif.img = c1.img - c2.img;
	return dif;
}

complex Multiplication (complex c1, complex c2){

	complex mul;
	mul.real = c1.real*c2.real - c1.img*c2.img;
	mul.img = c1.real*c2.img + c1.img*c2.real;
	return mul;
}

complex Division (complex c1, complex c2){

	complex div;
	div.real = (c1.real*c2.real + c1.img*c2.img)/(pow(c2.real, 2) + pow(c2.img, 2));
	div.img = (c1.img*c2.real - c1.real*c2.img)/(pow(c2.real, 2) + pow(c2.img, 2));
	return div;
}

float Distance (complex c1, complex c2){
	float dist;
	dist = sqrt(pow(c1.real-c2.real, 2) + pow(c1.img-c2.img, 2));
	return dist;
}

void print_comp (complex x){
	if (x.img>=0){
		printf("%f + %fi", x.real, x.img);
		}
	else{
		printf("%f - %fi", x.real, (-x.img));
	}
}

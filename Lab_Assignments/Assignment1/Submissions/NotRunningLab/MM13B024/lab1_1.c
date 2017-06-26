#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct Complex
 {
 float a, b;
 }complex;

void printComplex(complex c)
 {
if(c.b<0.0)
	{
	printf("%f - %fi",c.a,(-1)*c.b);
	} 
else	{
	printf("%f + %fi",c.a,c.b);
	}
 }

void add(complex c1 , complex c2)
 {
	complex c; 
	c.a = c1.a + c2.a; 
	c.b = c1.b + c2.b; 
	printComplex(c);
 }

void subtract(complex c1 , complex c2)
 {	complex c; 
	c.a = c1.a - c2.a; 
	c.b = c1.b - c2.b; 
	printComplex(c);
 }

void multiply(complex c1, complex c2)
 {	complex c; 
	c.a = c1.a * c2.a; 
	c.b = c1.b * c2.b; 
	printComplex(c);
 }

void divide(complex c1, complex c2)
 {	complex c; 
	c.a = c1.a/c2.a; 
	c.b = c1.b/c2.b; 
	printComplex(c);
 }

void distance(complex c1, complex c2)
 {	double distance = sqrt((c1.a-c2.a)*(c1.a-c2.a) + (c1.b-c2.b)*(c1.b-c2.b)); 
 	printf("%f", distance);
 }


void main()
 {
 complex c1,c2; 
 int operator = 1;
 
while(operator!=0 && operator!=0)
 { 
 	scanf("%f",&c1.a);
 	scanf("%f",&c1.b);
 	scanf("%f",&c2.a);
 	scanf("%f",&c2.b);
 	scanf("%d",&operator);
 switch(operator)
 {
 	case 0: exit(0);
 	case 1: add(c1, c2); break;
 	case 2: subtract(c1, c2); break;
 	case 3: multiply(c1, c2); break;
 	case 4: divide(c1, c2); break;
 	case 5: distance(c1, c2); break;

 }
 }
}

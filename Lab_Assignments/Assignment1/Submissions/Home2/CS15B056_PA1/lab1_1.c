#include <stdio.h>
#include <math.h>

typedef struct cmplex {
  float real;
  float img;
    }complex;
    
void addition (complex a,complex b);
void subtract (complex a,complex b);
void multiply (complex a,complex b);
void divide (complex a,complex b);
void distance (complex a,complex b);
    
int main ()  {

	int i=1;
	complex a,b;
	for (;i<=5&&i>=1;)           //Exit Condition
	 {
	  scanf("%f%f%f%f",&a.real,&a.img,&b.real,&b.img);
	  scanf("%d",&i);	 
	  if (i==1)
	  addition (a,b);
	  else if (i==2)
	  subtract (a,b);
	  else if (i==3)
	  multiply (a,b);
	  else if (i==4)
	  divide (a,b);
	  else if (i==5)
	  distance(a,b);
	 }
  return 0;
  	  
}	  
	     
void addition (complex a,complex b)  {

	float r,i;
	r=a.real+b.real;               //Addition
	i=a.img+b.img;
	if (i>0)
	printf("%f + %fi\n",r,i);
	else 
	printf ("%f - %fi\n",r,-1*i);
	 }

void subtract (complex a,complex b) {
	float r,i;
	r=a.real-b.real;
	i=a.img-b.img;                   //Subtraction
	if (i>0)
	printf("%f + %fi\n",r,i);
	else 
	printf ("%f - %fi\n",r,-1*i);	         
         }

void multiply (complex a,complex b) {
	float r,i;
	r=a.real*b.real-a.img*b.img;      //Multiplication
	i=a.img*b.real+a.real*b.img;
	if (i>0)
	printf("%f + %fi\n",r,i);
	else 
	printf ("%f - %fi\n",r,-1*i);
	 }
	 
void divide (complex a,complex b)  {
	float r,i,m;
	m=b.real*b.real+b.img*b.img;
	r=(a.real*b.real+a.img*b.img)/m;      //Division rule
	i=(b.real*a.img-a.real*b.img)/m;
	if (i>0)
	printf("%f + %fi\n",r,i);
	else 
	printf ("%f - %fi\n",r,-1*i);
	 }
void distance(complex a,complex b){
	float d;
	d=sqrt((a.real-b.real)*(a.real-b.real)+(a.img-b.img)*(a.img-b.img));	   //Distance calculation
	printf("%f\n",d);
	 }
	 
	
	
			 
	 


             


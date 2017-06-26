            //Code to find different operations using Complex numbers
			//Author:M.Prasanna Kumar
			//Date:08/08/2016
#include<stdio.h>
#include<math.h>
typedef struct Complex{
	float real;
	float imag;
}CompType;

void Add(CompType,CompType);                        //Addition Function
void Sub(CompType,CompType);                        //Subtraction Function
void Mult(CompType,CompType);                       //Multiplication Function
void Div(CompType,CompType);                        //Division Function
void Dist(CompType,CompType);                       //Distance Function

int main()
{
  int operation;                                    //Choice of operation
  int test=1;                                       //condition variable
  do
  {
	CompType C1;
	CompType C2;
	CompType C3;    
	scanf("%f %f",&C1.real,&C1.imag);               //Reading Complex no.1
    scanf("%f %f",&C2.real,&C2.imag);               //Reading Complex no.2
    scanf("%d",&operation);
	
	switch(operation)
	{
	  case 1:  Add(C1,C2);
			   break;
	  case 2:  Sub(C1,C2);
			   break;
	  case 3:  Mult(C1,C2);
			   break;
	  case 4:  Div(C1,C2);
			   break;
	  case 5:  Dist(C1,C2);
			   break;
	  default: test=0;
	           break;
	}
  }while(test==1);
  
return 0;

}

void Add(CompType a,CompType b)
{
CompType c;
c.real=a.real+b.real;                                 //Adding Real part
c.imag=a.imag+b.imag;                                 //Adding Imaginary part
printf("%.6f+%.6fi\n",c.real,c.imag);
}

void Sub(CompType a,CompType b)
{
CompType c;
c.real=a.real-b.real;                                 //Subtracting real part
c.imag=a.imag-b.imag;                                 //Subtracting Imaginary part
if(c.imag<0) printf("%.6f%.6fi\n",c.real,c.imag);
if(c.imag>=0) printf("%.6f+%.6fi\n",c.real,c.imag);
}

void Mult(CompType a,CompType b)
{
CompType c;
c.real=a.real*b.real-a.imag*b.imag;                   //Simplified real part after multiplying
c.imag=a.real*b.imag+a.imag*b.real;                   //Simplified imaginary part after multiplying
printf("%.6f+%.6fi\n",c.real,c.imag);
}

void Div(CompType a,CompType b)
{
CompType c;
	if (b.real!=0 && b.imag!=0)                       //Checking if denominator is 0
	{
	c.real=(a.real*b.real+a.imag*b.imag)/(b.real*b.real+b.imag*b.imag);          //Simplified real part after dividing
	c.imag=(a.imag*b.real-a.real*b.imag)/(b.real*b.real+b.imag*b.imag);          //Simplified imaginary part after multiplying 
	printf("%.6f+%.6fi\n",c.real,c.imag);
	}
	else printf("%d",-1);
}

void Dist(CompType a,CompType b)
{
float root;
CompType c;
c.real=pow((b.real-a.real),2);
c.imag=pow((b.imag-a.imag),2);
root=sqrt(c.real+c.imag);
printf("%.6f\n",root);
}



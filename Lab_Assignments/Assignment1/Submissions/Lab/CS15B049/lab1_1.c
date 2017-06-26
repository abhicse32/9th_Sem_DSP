
/* Assignment 1 : Complex Numbers 
   by CS15B049 Lokesh Koshale
   date: 08-08-16
*/

#include<stdio.h>
#include<math.h>

/* defining structure to store the
   complex nubers */
 
struct complex
{
	float real;
	float imag;
};

/* declaration of functions */

struct complex add( struct complex x, struct complex y);
struct complex subtraction( struct complex x, struct complex y);
struct complex multiplication( struct complex x, struct complex y);
struct complex division( struct complex x, struct complex y);
float modulus( struct complex x, struct complex y);


int main()
{
	/*declaring the variables */
	struct complex number1;
	struct complex number2;
	struct complex output;
	int i;
	float mod;

	scanf("%f %f",&number1.real,&number1.imag); //input num1
	scanf("%f %f",&number2.real,&number2.imag); //input num2
	
	/* looping the process with do while */
	do
	{
		scanf("%d",&i);
		
		if(i==1) //condition for addition
		{
			output= add(number1,number2); 
			
			if(output.imag<0) 
			{
				printf("%f %fi",output.real,output.imag);
			}
			else
			{
				printf("%f + %fi",output.real,output.imag);
			}
		}
		else if(i==2) //condition for Subtraction 
		{
			output= subtraction(number1,number2);
			
			if(output.imag<0)
			{
				printf("%f %fi",output.real,output.imag);
			}
			else
			{
				printf("%f + %fi",output.real,output.imag);
			}
		}
		else if(i==3) //condition for  multiplication
		{
			output= multiplication(number1,number2);
			
			if(output.imag<0)
			{
				printf("%f %fi",output.real,output.imag);
			}
			else
			{
				printf("%f + %fi",output.real,output.imag);
			}

		}
		else if(i==4) //condition for  division
		{
			output= division(number1,number2);
			
			if(output.imag<0)
			{
				printf("%f %fi",output.real,output.imag);
			}
			else
			{
				printf("%f + %fi",output.real,output.imag);
			}

		}
		else if(i==5) //condition for  modulus (distance bw the points)
		{
			mod= modulus(number1,number2);
			
			printf("%0.6f",mod);	
		}
		else
		{
			break;
		}

	}while(i!= 0); //end while

	return 0;
}

/* addition of complex numbers */
struct complex add( struct complex x, struct complex y)
{
	struct complex temp;

	temp.real= x.real+ y.real;
	temp.imag= x.imag+ y.imag;
	
	return temp;
}

/* subtraction of complex numbers */
struct complex subtraction( struct complex x, struct complex y)
{
	struct complex temp;

	temp.real= x.real- y.real;
	temp.imag= x.imag- y.imag;
	
	return temp;
}

/* multiplication of complex numbers */
struct complex multiplication( struct complex x, struct complex y)
{
	struct complex temp;

	temp.real= x.real*y.real - x.imag*y.imag;
	temp.imag= x.real*y.imag + x.imag*y.real;
	
	return temp;
}

/* division of complex numbers */
struct complex division( struct complex x, struct complex y)
{
	struct complex temp;
	struct complex conjugate;
	struct complex y1;
	struct complex y2;

	conjugate.real= y.real;
	conjugate.imag= y.imag;

	y1= multiplication(x,conjugate);
	y2= multiplication(y,conjugate);

	if(y2.real==0)
	{
		printf("error divided by zero");

	}
	else
	{
	temp.real= y1.real / y2.real;
	temp.imag= y1.imag / y2.real;

	}
	
	return temp;
	
}

/* distance bw  complex numbers */
float modulus( struct complex x, struct complex y)
{
	float temp;

	temp= sqrt( (x.real-y.real)*(x.real-y.real) + (x.imag-y.imag)*(x.imag-y.imag) ); 
	
	return temp;
}



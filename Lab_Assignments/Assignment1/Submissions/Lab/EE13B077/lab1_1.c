/*

Author Name: Gudur Phani Karan Reddy (EE13B077)
Time: Mon Aug  8 20:55:25 IST 2016

Description:
This program takes a list of integers as an input and outputs the minimum and maximum of the lot, respectively.

*/


#include <stdio.h>

struct cmplx
{
	float re, im;
};

struct cmplx Addition(struct cmplx p, struct cmplx q) 
	{
		struct cmplx final;
		final.re = p.re + q.re;
		final.im = p.im + q.im;
		return final;

	}

struct cmplx Subtraction(struct cmplx p, struct cmplx q) 
	{
		struct cmplx final;
		final.re = p.re - q.re;
		final.im = p.im - q.im;
		return final;

	}
struct cmplx Multiplication(struct cmplx p, struct cmplx q) 
	{
		struct cmplx final;
		final.re = (p.re)*(q.re) - (p.im)*(q.im);
		final.im = (p.re)*(q.im) + (p.im)*(q.re);
		return final;

	}

float Magnitude(struct cmplx p) 
	{
		int mod;
		mod = (p.re)*(p.re) + (p.im)*(p.im);
		return mod;
	}

struct cmplx Division(struct cmplx p, struct cmplx q) 
	{
		struct cmplx final;

		final.re = ( (p.re)*(q.re) + (p.im)*(q.im) ) / Magnitude(q);
		final.im = ( (p.im)*(q.re) - (p.re)*(q.im) ) / Magnitude(q);
		return final;

	}

int main()

{
	
	int op,i; 
	struct cmplx a, b, result;
	
	printf("Enter two complex numbers, and operation code as desired \n");
	printf(" 0) Exit \n 1) Addition \n 2) Subtraction \n 3) Multiplication \n 4) Division \n 5) Magnitude \n");
	scanf("%f %f", &a.re, &a.im);
	scanf("%f %f", &b.re, &b.im);
	scanf("%d", &op);

	switch(op)
	{
		case(0):
			printf("Exiting...\n");
			break;

		case(1):
			result = Addition(a,b);
			printf("%f + %fi \n", result.re, result.im);
			break;

		case(2):
			result = Subtraction(a,b);
			printf("%f + %fi \n", result.re, result.im);
			break;

		case(3):
			result = Multiplication(a,b);
			printf("%f + %fi \n", result.re, result.im);
			break;			

		case(4):
			result = Division(a,b);
			printf("%f + %fi \n", result.re, result.im);
			break;

		case(5):
			printf("%f  %f \n", Magnitude(a), Magnitude(b));
			break;
	
	}

	return 0;
}






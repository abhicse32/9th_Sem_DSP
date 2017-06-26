#include<stdio.h>
#include<math.h>
typedef struct complex{
	float real ;
	float imaginary ;
	}complex;

complex add(complex k1,complex k2); 
complex subtract(complex k1,complex k2); 
complex multiply(complex k1,complex k2); 
complex divide(complex k1,complex k2);
complex mod(complex k1,complex k2);

int main(){

	complex k1,k2,a;
	int op;
	while(1){
		scanf("%f%f",&k1.real,&k1.imaginary);
		scanf("%f%f",&k2.real,&k2.imaginary);
		scanf("%d",&op);

		if(op == 1) 
		{
			a=add(k1,k2);
			printf("%f+%fi\n",a.real,a.imaginary);
		}
		else if(op == 2) 
		{
			a=subtract(k1,k2);
			printf("%f+%fi\n",a.real,a.imaginary);
		}
		else if(op == 3)
		{
			a=multiply(k1,k2);
			printf("%f+%fi\n",a.real,a.imaginary);
		}

		else if(op == 4)
		{
			a=divide(k1,k2);
			printf("%f+%fi\n",a.real,a.imaginary);
		}
		else if(op == 5) 
		{
				a=mod(k1,k2);
			printf("%f\n",a.real);

		}
	}
	return 0;
}
complex add(complex k1,complex k2)
{
	complex a;
	a.real=k1.real+k2.real;
	a.imaginary= k1.imaginary+k2.imaginary;
	return a;
}

complex subtract(complex k1,complex k2)
{
	complex a;
	a.real=k1.real-k2.real;
	a.imaginary= k1.imaginary-k2.imaginary;
	return a;
}

complex multiply(complex k1,complex k2)
{
	complex a;
	a.real=k1.real*k2.real-k1.imaginary*k2.imaginary;
	a.imaginary= k1.real*k2.imaginary+k1.imaginary*k2.real;
	return a;
}

complex divide(complex k1,complex k2)
{
	complex a;
	a.real = (k1.real*k2.real+k1.imaginary*k2.imaginary)/((k2.real*k2.real)+(k2.imaginary*k2.imaginary));
	a.imaginary = (k1.imaginary*k2.real-k1.real*k2.imaginary)/((k2.real*k2.real)+(k2.imaginary*k2.imaginary));
	return a;
}

complex mod(complex k1,complex k2)
{
	complex a;
	a.real = sqrt((k1.real-k2.real)*(k1.real-k2.real)+(k1.imaginary-k2.imaginary)*(k1.imaginary-k2.imaginary));
	return a;
}

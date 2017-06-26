#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct complex{
	float real;
	float imaginary;
};
typedef struct complex Complex_no;

Complex_no Addition(Complex_no,Complex_no);

Complex_no Subtraction(Complex_no,Complex_no);

Complex_no Multiplication(Complex_no,Complex_no);

Complex_no Division(Complex_no,Complex_no);

float Distance_between_them(Complex_no,Complex_no);

int main(void){

int choice;

Complex_no complex1,complex2;

Complex_no add,subtract,multiplicate,divide;

float distance;

scanf("%f %f",&(complex1.real),&(complex1.imaginary)); 

scanf("%f %f",&(complex2.real),&(complex2.imaginary));

printf("Enter a number from 1 to 5,-1 to end:\n");
scanf("%d",&choice);	

switch(choice){
	case 1:
		add=Addition(complex1,complex2);
		if(add.imaginary>=0) printf("The addition of the given two numbers is %f + %fi\n",(add.real),(add.imaginary));
		if(add.imaginary<0) printf("The addition of the given two numbers is %f - %fi\n",(add.real),(-add.imaginary));
	break;
	case 2:
		subtract=Subtraction(complex1,complex2);
		if(subtract.imaginary>=0) printf("The Subtraction of the given two numbers is %f + %fi\n",(subtract.real),(subtract.imaginary));
		if(subtract.imaginary<0) printf("The Subtraction of the given two numbers is %f - %fi\n",(subtract.real),(subtract.imaginary));
	break;
	case 3:
		multiplicate=Multiplication(complex1,complex2);
		if(multiplicate.imaginary>=0) printf("The multiplication of the given two numbers is %f + %fi\n",(multiplicate.real),(multiplicate.imaginary));
		if(multiplicate.imaginary<0) printf("The multiplication of the given two numbers is %f + %fi\n",(multiplicate.real),(multiplicate.imaginary));
	break;
	case 4:
		divide=Division(complex1,complex2);
		if(divide.imaginary>=0) printf("The division of the given two numbers is %f +%fi\n",(divide.real),(divide.imaginary));
		if(divide.imaginary<0) printf("The division of the given two numbers is %f +%fi\n",(divide.real),(divide.imaginary));
	break;
	case 5:
		distance=Distance_between_them(complex1,complex2);
		printf("The distance is %f\n",distance);
	break;
	case -1:
	printf("Program ended,end of input\n");
}
return 0;
}
Complex_no Addition(Complex_no x,Complex_no y){ 			//Addition of two complex numbers
	Complex_no z;
	z.real=x.real+y.real;
	z.imaginary=x.imaginary+y.imaginary;
	return z;
}
Complex_no Subtraction(Complex_no l,Complex_no m){ 			//Subtraction of two complex numbers
	Complex_no z;
	z.real=l.real-m.real;
	z.imaginary=l.imaginary-m.imaginary;
	return z;
}
Complex_no Multiplication(Complex_no x,Complex_no y){ 			//Multiplication of two complex numbers
	Complex_no z;
	z.real=(x.real)*(y.real)-(x.imaginary)*(y.imaginary);
	z.imaginary=(x.real)*(y.imaginary)+(x.imaginary)*(y.real);
	return z;
}
float Distance_between_them(Complex_no x,Complex_no y){			 //Distance between two complex numbers
	float magnitude_of_k;
	Complex_no k;
	k=Subtraction(x,y);
	magnitude_of_k=sqrt((k.real)*(k.real)+(k.imaginary)*(k.imaginary));
	return magnitude_of_k;
}
Complex_no Division(Complex_no x,Complex_no y){				//Division between two complex numbers
	Complex_no z;
	y.imaginary=-(y.imaginary);
	z.real=(x.real)*(x.real)-(y.imaginary)*(x.imaginary);
	z.imaginary=(x.real)*(y.imaginary)+(y.real)*(x.imaginary);
	float k=((y.real)*(y.real)-(y.imaginary)*(y.imaginary));
	z.real=(z.real)/k;
	z.imaginary=(z.imaginary)/k;
	return z;
}

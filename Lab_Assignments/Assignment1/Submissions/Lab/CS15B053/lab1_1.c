/* 	Program to perform operations on complex numbers by implementing ADT
	Author : Monisha J, CS15B053
	Date : 8 August 2016 							*/


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct complex							//Complex Number Representation as an abstract data type
{
	float real;
	float img;
};

struct complex add(struct complex n1, struct complex n2)	//Function that adds two complex numbers and returns the result as a complex number
{
	struct complex sum;
	sum.real = n1.real + n2.real;
	sum.img = n1.img + n2.img;
	return sum;
}

struct complex subtract(struct complex n1, struct complex n2)	//Function that subtracts two complex numbers and returns the result as a complex number
{
	struct complex difference;
	difference.real = n1.real - n2.real;
	difference.img = n1.img - n2.img;
	return difference;
}

struct complex multiply(struct complex n1, struct complex n2)	//Function that multiplies two complex numbers and returns the result as a complex number
{
	struct complex product;
	product.real = n1.real*n2.real - n1.img*n2.img;
	product.img = n1.img*n2.real + n1.real*n2.img;
	return product;
}

struct complex divide(struct complex n1, struct complex n2)	//Function that divides two complex numbers and returns the result as a complex number
{
	struct complex answer;
	float temp = pow(n2.real,2) + pow(n2.img, 2);
	answer.real = (n1.real*n2.real + n1.img*n2.img)/temp;
	answer.img = (n1.img*n2.real - n1.real*n2.img)/temp;
	return answer;
}

float distance(struct complex n1, struct complex n2)		//Function that computes and returns (as float) the distance between two complex numbers
{
	float distance = sqrt(pow((n1.real - n2.real),2) + pow((n1.img - n2.img),2));
	return distance;
}


void main()
{
	int choice;
	float dist;
	int error;
					
	struct complex num1, num2, result;	
	result.real=0;
	result.img=0;
	
	do
	{		
		scanf("%f %f", &num1.real, &num1.img);		//Takes two complex numbers as input
		scanf("%f %f", &num2.real, &num2.img);
		
		scanf("%d", &choice);
		
		error=0;
		
		switch(choice)
		{
			case 0: 
				printf("Quitting\n");
				break;
			case 1:
				result=add(num1, num2);
				break;	
			case 2:
				result=subtract(num1, num2);
				break;
			case 3:
				result=multiply(num1, num2);
				break;
			case 4:
				if(num2.real==0 && num2.img==0)
				{
					printf("Divide By zero error, please try again\n");
					error=1;
					break;
				}
				result=divide(num1, num2);
				break;
			case 5: 
				dist=distance(num1, num2);
				printf("%6f\n", dist);
				break;	
			default:
				printf("Invalid choice, please try again\n");
				break;			
		}
		
		if(choice>0 && choice<=4 && error==0)		//Prints the result
		{
			if(result.img<0)
				printf("%f - %fi\n", result.real, -1*result.img);
			else
				printf("%f + %fi\n", result.real, result.img);
		}				
		
	}while(choice!=0 && choice!=-1);
}




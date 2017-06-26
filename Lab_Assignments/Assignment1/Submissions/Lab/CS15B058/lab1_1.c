// Program to perform complex number operations: B Arjun CS15B058, 08/08/16
#include<stdio.h>
#include<math.h>
typedef struct complex complex;
struct complex
{
	float real;
	float img;
};

/* Function to output the complex number*/
void complexout(complex num)
{	
	if(num.img>=0)
	printf("%f+%fi\n",num.real,num.img);
	else if(num.img<0)
	printf("%f%fi\n",num.real,num.img);
	
	
	
}

/*Function to add 2 complex numbers*/
complex complexadd(complex num1,complex num2)
{
	complex sum;
	sum.real=num1.real+num2.real;
	sum.img=num1.img+num2.img;
	return sum;
}

/*Function to subtract 2 complex numbers*/
complex complexdiff(complex num1,complex num2)
{
	complex diff;
	diff.real=num1.real-num2.real;
	diff.img=num1.img-num2.img;
	return diff;
}

/*Function to multiply 2 complex numbers*/
complex complexproduct(complex num1,complex num2)
{
	complex product;
	product.real=num1.real*num2.real-num1.img*num2.img;
	product.img=num1.real*num2.img+num1.img*num2.real;
	return product;
}

/*Function to divide 2 complex numbers*/
complex complexdivision(complex num1, complex num2)
{
	complex div;
	div.real=(num1.real*num2.real+num1.img*num2.img)/(num2.real*num2.real+num2.img*num2.img);
	div.img=(num1.img*num2.real-num1.real*num2.img)/(num2.real*num2.real+num2.img*num2.img);
	return div;
}

/*Function to find distance*/
float complexdist(complex num1,complex num2)
{
	complex diff;
	diff=complexdiff(num1,num2);
	float dist;
	dist=sqrt(diff.real*diff.real+diff.img*diff.img);
	return dist;
}

int main(void)
{	
	complex num1,num2;   
	int option;
/*Loop for the Menu*/
	do
	{
		
		scanf("%f",&num1.real);
		scanf("%f",&num1.img);
		scanf("%f",&num2.real);
		scanf("%f",&num2.img);
		scanf("%d",&option);
		switch(option)
		{
			case 1: 	{
					complex sum;
					sum=complexadd(num1,num2);
					complexout(sum);
					break;
					}
			case 2: 	{	
					complex diff;
					diff=complexdiff(num1,num2);
					complexout(diff);
					break;
					}
			case 3: 	{
					complex product;
					product=complexproduct(num1,num2);
					complexout(product);
					break;
					}
			case 4: 	{
					complex div;
					if(num2.real!=0||num2.img!=0)
					{	div=complexdivision(num1,num2);
						complexout(div);
					}
					else 
						printf("Divide by zero error\n");
					break;
					}
			case 5: 	{
						float dist;
						dist=complexdist(num1,num2);
						printf("%f\n",dist);
						break;
					}
	

		}
	}while(option!= -1 && option!=0);

}




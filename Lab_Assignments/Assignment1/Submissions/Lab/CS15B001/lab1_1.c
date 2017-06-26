#include<stdio.h>
#include<math.h>

/*
This program performs basic operations like addition, subtraction, multiplication, 
division and finding distance between two given complex numbers

Ameet S Deshpande
CS15B001
*/


struct complex{		//Structure for storing the complex number
float p;
float q;
};


int main()
{

void addition(struct complex,struct complex);	//The functions that are going to be used
void subtraction(struct complex,struct complex);
void multiplication(struct complex,struct complex);
void division(struct complex,struct complex);
void distance(struct complex,struct complex);


int choice=1;	//Choice for the menu created
float p1,q1,p2,q2;	//Values of real and imaginary parts of the input
struct complex c1,c2;

while((choice>=1)&&(choice<=5)){

	scanf("%f %f",&p1,&q1);//Prompt the user to enter the complex numbers
	scanf("%f %f",&p2,&q2);

	c1.p=p1;
	c1.q=q1;
	c2.p=p2;	
	c2.q=q2;

	scanf("%d",&choice);

	switch(choice){

	case 1: addition(c1,c2);
		break;

	case 2: subtraction(c1,c2);
		break;

	case 3: multiplication(c1,c2);
		break;

	case 4: division(c1,c2);
		break;

	case 5: addition(c1,c2);
		break;
}


}
return 0;

}



void addition(struct complex c1, struct complex c2)
{
	struct complex c;
	c.p=c1.p+c2.p;
	c.q=c1.q+c2.q;
	
	if(c.q>=0)
	{
		printf("%f+%fi\n",c.p,c.q);
	}
	else
	{
		printf("%f%fi\n",c.p,c.q);
	}

}


void subtraction(struct complex c1, struct complex c2)
{
	struct complex c;
	c.p=c1.p-c2.p;
	c.q=c1.q-c2.q;
	
	if(c.q>=0)
	{
		printf("%f+%fi\n",c.p,c.q);
	}
	else
	{
		printf("%f%fi\n",c.p,c.q);
	}

}


void multiplication(struct complex c1, struct complex c2)
{
	struct complex c;
	c.p=c1.p*c2.p-c1.q*c2.q;
	c.q=c1.p*c2.q+c1.q*c2.p;
	
	if(c.q>=0)
	{
		printf("%f+%fi\n",c.p,c.q);
	}
	else
	{
		printf("%f%fi\n",c.p,c.q);
	}
}


void division(struct complex c1, struct complex c2)
{	
	struct complex c;
	c.p=(c1.p*c2.p+c1.q+c2.q)/(c2.p*c2.p+c2.q+c2.q);
	c.q=(c2.p*c1.q-c1.p*c2.q)/(c2.p*c2.p+c2.q+c2.q);
	
	if(c.q>=0)
	{
		printf("%f+%fi\n",c.p,c.q);
	}
	else
	{
		printf("%f%fi\n",c.p,c.q);
	}
}


void distance(struct complex c1,struct complex c2)
{
	float dist;
	dist=(c1.p-c2.p)*(c1.p-c2.p)+(c1.q-c2.q)*(c1.q-c2.q);
	dist=sqrt(dist);
	printf("%f\n",dist);
}









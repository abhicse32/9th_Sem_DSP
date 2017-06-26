							/*program to do complex operations by Akshay Kumar*/

#include<stdio.h>
#include<math.h>

	struct complex{							/*definition of complex structure*/
		float x;
		float y;
		
}c1,c2,c3;

void addition(struct complex *,struct complex *);			/*declarations of functions*/
void subtraction(struct complex *,struct complex *);
void multiplication(struct complex *,struct complex *);
void division(struct complex *,struct complex *);
void distance(struct complex *,struct complex *);

void main()
{


	int n;
	struct complex *p1 = &c1;					/*declaration of variables*/
	struct complex *p2 = &c2;
	scanf("%f %f",&c1.x,&c1.y);
	scanf("%f %f",&c2.x,&c2.y);
	scanf("%d",&n);
	switch(n){
		case 0 : exit(0);
		case -1 : exit(0);
		case 1 : addition(p1,p2);
			break;
		case 2 : subtraction(p1,p2);
			break;
		case 3 : multiplication(p1,p2);
			break;
		case 4 : division(p1,p2);
			break;
		case 5 : distance(p1,p2);
			break;
};

}

void addition(struct complex *k,struct complex *l)			/*this function adds two complex numbers*/
{

	float a=k->x +l->x;
	float b=k->y +l->y;
	if(b<0){b=b*-1;
	printf("%f-%fi \n",a,b);}
	else printf("%f+%fi \n",a,b);

}

void subtraction(struct complex *k,struct complex *l)			/*this function subtracts two complex numbers*/
{

	float a=k->x -l->x;
	float b=k->y -l->y;
	if(b<0){b=b*-1;
	printf("%f-%fi \n",a,b);}
	else printf("%f+%fi \n",a,b);

}

void multiplication(struct complex *k,struct complex *l)		/*this function multiplies two complex numbers*/
{

	float a=(k->x * l->x)-(k->y * l->y);
	float b=(k->x * l->y)+(k->y * l->x);
	if(b<0){b=b*-1;
	printf("%f-%fi \n",a,b);}
	else printf("%f+%fi \n",a,b);

}

void division(struct complex *k,struct complex *l)			/*this function divides two complex numbers*/
{

	float a=((k->x * l->x)+(k->y * l->y))/(l->x * l->x + l->y * l->y);
	float b=((k->y * l->x)-(k->x * l->y))/(l->x * l->x + l->y * l->y);
	if(b<0){b=b*-1;
	printf("%f-%fi \n",a,b);}
	else printf("%f+%fi \n",a,b);

}

void distance(struct complex *k,struct complex *l)			/*this function calculates distance between two complex numbers*/
{

	float a=(k->x - l->x)*(k->x - l->x)+(k->y - l->y)*(k->y - l->y);
	float b=sqrt(a);
	printf("%f\n",b);

}

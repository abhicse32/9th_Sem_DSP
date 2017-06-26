#include<stdio.h>
#include<math.h>
struct Complex{
	float real;
	float imag;
};
void complexadd(struct Complex c1,struct Complex c2);
void complexsubstract(struct Complex c1,struct Complex c2);
void complexmultiply(struct Complex c1,struct Complex c2);
void complexdivide(struct Complex c1,struct Complex c2);
void complexmodulus(struct Complex c1,struct Complex c2);
void main()
{	int j =0;
	for(j =0;j!=-1;j++)
	 { 
	   printf("input:");
	   struct Complex c1;
	   struct Complex c2;
	   scanf("%f %f",&c1.real,&c1.imag);
	   scanf("%f %f",&c2.real,&c2.imag);
	   printf("addition:1\nsubstraction:2\nmultiplication:3\ndivision:4\nmodulus:5\nbreak:0\n");
	   int i;
	   scanf("%d",&i);
	   if(i==1)
	     complexadd(c1,c2);
	   if(i==2)
	     complexsubstract(c1,c2);
	   if(i==3)
	     complexmultiply(c1,c2);
	   if(i==4)
	     complexdivide(c1,c2);
	   if(i==5)
	     complexmodulus(c1,c2);
	   if(i==0)
	     break;
	  }
}
void complexadd(struct Complex c1,struct Complex c2)
{
	float a = c1.real + c2.real;
	float b = c1.imag + c2.imag;
	printf("%f+i%f\n",a,b);
}
void complexsubstract(struct Complex c1,struct Complex c2)
{
	float a = c1.real - c2.real;
	float b = c1.imag - c2.imag;
	printf("%f+i%f\n",a,b);
}
void complexmultiply(struct Complex c1,struct Complex c2)
{
	float a = (c1.real*c2.real)-(c1.imag*c2.imag);
	float b = (c1.real*c2.imag)-(c1.imag*c2.real);
	printf("%f+i%f\n",a,b);
}
void complexdivide(struct Complex c1,struct Complex c2)
{
	float a = ((c1.real*c2.real)+(c1.imag*c2.imag))/((c2.real*c2.real)+(c2.imag*c2.imag));
	float b = ((c1.imag*c2.real)-(c1.real*c2.imag))/((c2.real*c2.real)+(c2.imag*c2.imag));
	printf("%f+i%f\n",a,b);
}
void complexmodulus(struct Complex c1,struct Complex c2)
{
	float a = sqrt((c1.real*c1.real)+(c1.imag*c1.imag));
	float b = sqrt((c2.real*c2.real)+(c2.imag*c2.imag));
	printf("%f %f\n",a,b);
}
	
	


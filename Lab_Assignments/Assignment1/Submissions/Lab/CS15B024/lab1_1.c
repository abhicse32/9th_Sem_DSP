#include<stdio.h>
#include<math.h>
typedef struct complex{
	float real;
	float img;
	}complex;
	void Addcomplex(complex p,complex q); //function prototypes of all the necessary functions
	void Subcomplex(complex p,complex q);
	void Multcomplex(complex p,complex q);
	void Divcomplex(complex p,complex q);
	void Modcomplex(complex p,complex q);
int main()
{
	int i;
	complex p,q;
	printf("enter the real and imaginary parts of p");//to get the two complex numbers as input
	scanf("%f%f",&p.real,&p.img);
	printf("enter the real and imaginary parts of q");
	scanf("%f%f",&q.real,&q.img);
	printf("enter the value of i");
	scanf("%d",&i);
	if(i%5==1) Addcomplex(p,q);
	else if(i%5==2) Subcomplex(p,q);
	else if(i%5==3) Multcomplex(p,q);
	else if(i%5==4) Divcomplex(p,q);
	else if(i%5==0) Modcomplex(p,q);
	return 0;	

}
	void Addcomplex(complex p,complex q){	//function to add two complex numbers
	complex temp;
	temp.real=p.real+q.real;		
	temp.img=p.img+q.img;
	printf("%f+%fi",temp.real,temp.img);
	}
	void Subcomplex(complex p,complex q){	//function to subtract a complex no from other
	complex temp;
	temp.real=p.real-q.real;
	temp.img=p.img-q.img;
	printf("%f+%fi",temp.real,temp.img);	
	}
	void Multcomplex(complex p,complex q){	//function to multiply two complex numbers
	complex temp;
	temp.real=(p.real*q.real)-(p.img*q.img);
	temp.img=(p.real*q.img)+(p.img*q.real);
	printf("%f+%fi",temp.real,temp.img);
	}
	void Divcomplex(complex p,complex q){ 	//function to divide a complex number by other 
	complex temp;
	float a=(q.real*q.real)+(q.img*q.img);
	temp.real=((p.real*q.real)+(p.img*q.img))/a;
	temp.img=((p.img*q.real)-(p.real*q.img))/a;
	printf("%f+%fi",temp.real,temp.img);
	}
	void Modcomplex(complex p,complex q){ //function to find the distance between two complex numbers
	float mod;
	mod=sqrt((p.real-q.real)*(p.real-q.real)+(p.img-q.img)*(p.img-q.img));
	printf("%f",mod);
	}
	
	
			
			

	

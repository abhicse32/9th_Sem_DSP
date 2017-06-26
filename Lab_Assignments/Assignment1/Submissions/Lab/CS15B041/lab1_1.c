#include<stdio.h>
#include<math.h>


typedef struct Complex
	{
		float real;
		float comp;
	}
	complex;

complex add(complex c1,complex c2);
complex sub(complex c1,complex c2);
complex mul(complex c1,complex c2);
complex div(complex c1,complex c2);
float mod(complex c1,complex c2);
	




	int main()
	{
		int ch;

		complex sum;
		complex difference;
		complex product;
		complex division;
		float modulus;
		complex numb1,numb2;
		int flag=1;
		while(flag)
		{scanf("%f %f",&numb1.real,&numb1.comp);
		scanf("%f %f",&numb2.real,&numb2.comp);
		
		
		
	       scanf("%d",&ch);
	switch(ch)
		{ 
			case 1:
				sum=add(numb1,numb2);
				printf("%f + %fi",sum.real,sum.comp);
				break;
	
			case 2:
				difference=sub(numb1,numb2);
				printf("%f+i%f",difference.real,difference.comp);
				break;
			case 3:	product=mul(numb1,numb2);
				printf("%f+i%f",product.real,product.comp);
				break;
			case 4:
				division=div(numb1,numb2);
				printf("%f+i%f",division.real,division.comp);
				break;
			case 5:
				modulus=mod(numb1,numb2);
				printf("%f",modulus);		
				break;
				

				
		
			
			}
	if(ch==-1)
		flag=0;
}
	return 0;

	
	}
		complex add(complex c1,complex c2)
			{
				complex s1;
				s1.real=c1.real + c2.real;
				s1.comp=c1.comp+c2.comp;
				return s1;
			}
		complex sub(complex c1,complex c2)
			{
				complex s2;
				s2.real=c1.real - c2.real;
				s2.comp=c1.comp-c2.comp;
				return s2;
			}
		complex mul(complex c1,complex c2)
			{
				complex m;
				m.real=(c1.real*c2.real)-(c1.comp*c2.comp);
				m.comp=(c1.real*c2.comp)+(c1.comp*c2.real);
				return m;
			}
		complex div(complex c1,complex c2)
			{	if(c2.real !=0 && c2.comp!=0)
				{
				complex n,d;
				n.real=(c1.real*c2.real)+(c1.comp*c2.comp);
				n.comp=-(c1.real*c2.comp)+(c1.comp*c2.real);
				d.real = n.real / (sqrt((c2.real*c2.real)+(c2.comp*c2.comp)));
				d.comp = n.comp / (sqrt((c2.real*c2.real)+(c2.comp*c2.comp)));
				return d;
				}
				
				else
				printf("Invalid");		
			}

		float mod(complex c1,complex c2)
			{
				float a,b;
				float dis;
				a= pow((c1.real-c2.real),2);
				b=pow((c1.comp-c2.comp),2);
				dis=sqrt(a+b);
				return dis;
			}

#include<stdio.h>
#include<math.h>
struct Cmplx
{
	float r,c;
};

void add(struct Cmplx z1,struct Cmplx z2);
void sub(struct Cmplx z1,struct Cmplx z2);
void mul(struct Cmplx z1,struct Cmplx z2);
void div(struct Cmplx z1,struct Cmplx z2);
void dist(struct Cmplx z1,struct Cmplx z2);

int main()
{
	int function;
	int i=1;
	while(i==1)
	{
	struct Cmplx z1;
	struct Cmplx z2;
	scanf("%f %f \n %f %f", &z1.r, &z1.c, &z2.r, &z2.c);
	scanf("%d", &function);
	if(function==1)
		add(z1,z2);
	else if(function==2)
		sub(z1,z2);
	else if(function==3)
		mul(z1,z2);
	else if(function==4)
		div(z1,z2);
	else if(function==5)
		dist(z1,z2);
	else if(function==-1||function==0)
		return 0;
	}
	return 0;
}
void add(struct Cmplx z1,struct Cmplx z2)
{
	float rea,com;
	rea=z1.r+z2.r;
	com=z1.c+z2.c;
	if(com<0)
		printf("%f - %fi",rea,-1*com);
	else
		printf("%f + %fi",rea,com);
}
void sub(struct Cmplx z1,struct Cmplx z2)
{
	float rea,com;
	rea=z1.r-z2.r;
	com=z1.c-z2.c;
	if(com<0)
		printf("%f - %fi",rea,-1*com);
	else
		printf("%f + %fi",rea,com);
}
void mul(struct Cmplx z1,struct Cmplx z2)
{
	float rea,com;
	rea=z1.r*z2.r - z1.c*z2.c;
	com=z1.r*z2.c - z1.c*z2.r;
	if(com<0)
		printf("%f - %fi",rea,-1*com);
	else
		printf("%f + %fi",rea,com);
}
void div(struct Cmplx z1,struct Cmplx z2)
{
	float rea,com;
	rea=(z1.r*z2.r+z1.c*z2.c)/(z2.r*z2.r+z2.c*z2.c);
	com=(z1.c*z2.c-z1.r*z2.c)/(z2.r*z2.r+z2.c*z2.c);
	if(com<0)
		printf("%f - %fi ",rea,-1*com);
	else
		printf("%f + %fi",rea,com);
}
void dist(struct Cmplx z1,struct Cmplx z2)
{
	float dis;
	dis=sqrt((z1.r-z2.r)*(z1.r-z2.r)+(z1.c-z2.c)*(z1.c-z2.c));
	printf("%f",dis);
	//dist
}

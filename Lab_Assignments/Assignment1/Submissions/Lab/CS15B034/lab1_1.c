//Lab1 assignment 1 complex numbers by Raghavan S CS15B034
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*definition of complex structure
*/
typedef struct com
{
float re;
float im;
} compl;
/*printing the complex number a
*/
printc(compl a)
{
if(a.im>=0)
	printf("%f + %fi",a.re,a.im);
else
	printf("%f - %fi",a.re,a.im*-1);
}
/*adding 2 complex numbers p,q and returning the result as a complex r*/
compl add(compl p,compl q)
{
compl r;
r.re=p.re+q.re;
r.im=p.im+q.im;
return r;
}
/*subtracting 2 complex numbers p,q and returning the result as a complex r*/
compl sub(compl p,compl q)
{
compl r;
r.re=p.re-q.re;
r.im=p.im-q.im;
return r;
}
/*multiplying 2 complex numbers p,q and returning the result as a complex r*/
compl mul(compl p,compl q)
{
compl r;
r.re=p.re*q.re-p.im*q.im;
r.im=p.im*q.re+p.re*q.im;
return r;
}
/*dividing 2 complex numbers p,q and returning the result as a complex r*/
compl divi(compl p,compl q)
{
if(q.re==0&&q.im==0)
	{
		printf("Division by 0!");
		exit(0);
	}
compl r,s;	
float mod;
s=q;
s.im=-1*s.im;
r=mul(p,s);
mod=q.re*q.re+q.im*q.im;
r.re=r.re/mod;
r.im=r.im/mod;
return r;
}
/*calculating 2 complex numbers p,q and returning the result as a float d*/
void dis(compl a,compl b)
{
float d;
d=sqrt((a.re-b.re)*(a.re-b.re)+(a.im-b.im)*(a.im-b.im));
printf("%.6f",d);
}
int main()
{
int ch;// option input variable
compl a;
compl b;//complex number inputs
int fl=0;//flag to check sentinel variable
do
{
scanf("%f",&a.re);
scanf("%f",&a.im);
scanf("%f",&b.re);
scanf("%f",&b.im);//scanning the numbers
scanf("%d",&ch);	//scanning option
switch(ch)
{
	case 1:printc(add(a,b));break;
	case 2:printc(sub(a,b));break;
	case 3:printc(mul(a,b));break;
	case 4:printc(divi(a,b));break;
	case 5:dis(a,b);break;
	case 0:
	case -1:fl=1;break;
	default:break;
}
}while(fl==0);//checking whether sentinel input was pressed
return 0;
}

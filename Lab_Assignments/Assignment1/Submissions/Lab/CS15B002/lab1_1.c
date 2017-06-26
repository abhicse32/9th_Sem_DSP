#include<stdio.h>
#include<math.h>
typedef struct cmplx cmplx;              
 struct cmplx
        { float p;
          float q;
        };
void Add(cmplx cmplx1,cmplx  cmplx2)
{
	float p,q;
	p=cmplx1.p+cmplx2.p;
	q=cmplx1.q+cmplx2.q;
	printf("%f+%fi\n",p,q);
}
void Sub(cmplx cmplx1,cmplx  cmplx2)
{
	float p,q;
	p=cmplx1.p-cmplx2.p;
	q=cmplx1.q-cmplx2.q;
	printf("%f+%fi\n",p,q);
}
void Mul(cmplx cmplx1,cmplx  cmplx2)
{
	float p,q;
	p=cmplx1.p*cmplx2.p-cmplx1.q*cmplx2.q;
	q=cmplx1.p*cmplx2.q+cmplx2.p*cmplx1.q;
	printf("%f+%fi\n",p,q);
}
void Div(cmplx cmplx1,cmplx  cmplx2)
{
	float p,q,r;
	r=cmplx2.p*cmplx2.p+cmplx2.q*cmplx2.q;
	p=cmplx1.p*cmplx2.p+cmplx1.q*cmplx2.q;
	q=cmplx2.p*cmplx1.q-cmplx1.p*cmplx2.q;
	p=p/r;
	q=q/r;
	printf("%f+%fi\n",p,q);
}
void Mod(cmplx cmplx1,cmplx  cmplx2)
{
	float r1,r2;
	float p,q;
	p=cmplx1.p-cmplx2.p;
	q=cmplx1.q-cmplx2.q;
	r1=p*p+q*q;
	r2=sqrt(r1);
	printf("%f\n",r2);
}
int main()
{		
	struct cmplx cmplx1,cmplx2; int a;
	scanf("%f%f%f%f",&cmplx1.p,&cmplx1.q,&cmplx2.p,&cmplx2.q);
	scanf("%d",&a);
	if((a==0) || (a==-1)) return 1;
	if(a==1)Add(cmplx1,cmplx2);
	if(a==2)Sub(cmplx1,cmplx2);
	if(a==3)Mul(cmplx1,cmplx2);
	if(a==4)Div(cmplx1,cmplx2);
	if(a==5)Mod(cmplx1,cmplx2);
	return 0;
}


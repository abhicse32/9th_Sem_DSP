#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct complex{
	float p;
	float q;
};

struct complex AddComplex(struct complex cmplx1,struct complex cmplx2);
struct complex SubComplex(struct complex cmplx1,struct complex cmplx2);
struct complex MultComplex(struct complex cmplx1,struct complex cmplx2);
struct complex DivComplex(struct complex cmplx1,struct complex cmplx2);
float DisComplex(struct complex cmplx1,struct complex cmplx2);

void main()
{
	struct complex cmplx1;
	struct complex cmplx2;

	scanf("%f %f\n",&cmplx1.p,&cmplx1.q);
	scanf("%f %f\n",&cmplx2.p,&cmplx2.q);
	float d;
	int i;
	scanf("%d",&i);

	struct complex result;
	if(i==0||i==-1){
	 exit(EXIT_SUCCESS);
	 }

	else if(i==1)
	 {
	  result=AddComplex(cmplx1,cmplx2);
	  if(result.q>=0){
	    printf("%f + i%f",result.p,result.q);
	    }
	  else{
	    printf("%f - i%f",result.p,-result.q);
	    }
	 }
	else if(i==2)
	 {
	  result=SubComplex(cmplx1,cmplx2);
	  if(result.q>=0){
	   printf("%f + i%f",result.p,result.q);
	   }
	  else{
	    printf("%f - i%f",result.p,-result.q);
	    }

	 }
	else if(i==3)
	 {
	  result=MultComplex(cmplx1,cmplx2);
	  if(result.q>=0){
	   printf("%f + i%f",result.p,result.q);
	   }
	  else{
	    printf("%f - i%f",result.p,-result.q);
	    }
	 }
	else if(i==4)
	 {
	  result=DivComplex(cmplx1,cmplx2);
	  if(result.q>=0){
	   printf("%f + i%f",result.p,result.q);
	   }
	  else{
	    printf("%f - i%f",result.p,-result.q);
	    }
	 }
	else if(i==5)
	 {
	  d=DisComplex(cmplx1,cmplx2);
	  printf("%f",d);
	 }
	else{
	 printf("value of i is wrong");
	 }

}

struct complex AddComplex(struct complex cmplx1,struct complex cmplx2)
{
  struct complex temp;
  temp.p = cmplx1.p+cmplx2.p;
  temp.q = cmplx1.q+cmplx2.q;
  return temp;
}

struct complex SubComplex(struct complex cmplx1,struct complex cmplx2)
{
  struct complex temp;
  temp.p = cmplx1.p-cmplx2.p;
  temp.q = cmplx1.q-cmplx2.q;
  return temp;
}

struct complex MultComplex(struct complex cmplx1,struct complex cmplx2)
{
  struct complex temp;
  temp.p=(cmplx1.p*cmplx2.p)-(cmplx1.q*cmplx2.q);
  temp.q=(cmplx1.p*cmplx2.q)+(cmplx2.p*cmplx1.q);
  return temp;
}

struct complex DivComplex(struct complex cmplx1,struct complex cmplx2)
{
  struct complex temp;
  if(cmplx2.p==0 && cmplx2.q==0){
    printf("Complex2 is zero,Divison not possible");
     }
  else{
    temp.p=(cmplx1.p*cmplx2.p+cmplx1.q*cmplx2.q)/(cmplx2.p*cmplx2.p+cmplx2.q*cmplx2.q);
    temp.q=(cmplx1.q*cmplx2.p-cmplx1.p*cmplx2.q)/(cmplx2.p*cmplx2.p+cmplx2.q*cmplx2.q);
     }
  return temp;
}

float DisComplex(struct complex cmplx1,struct complex cmplx2)
{
  struct complex temp;
  temp.p=sqrt((cmplx1.p-cmplx2.p)*(cmplx1.p-cmplx2.p)+(cmplx1.q-cmplx2.q)*(cmplx1.q-cmplx2.q));
  return temp.p;
}


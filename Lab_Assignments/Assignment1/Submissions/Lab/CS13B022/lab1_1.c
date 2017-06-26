#include<stdio.h>
#include<math.h>

typedef struct _adt{
	float real,img;
	} adt;
	
adt add(adt a,adt b){
	adt c;
	c.real=a.real+b.real;
	c.img=a.img+b.img;
	return c;
	}
adt sub(adt a,adt b){
	adt c;
	c.real=a.real-b.real;
	c.img=a.img-b.img;
	return c;
	}
adt mul(adt a,adt b){
	adt c;
	c.real=a.real*b.real-a.img*b.img;
	c.img=a.real*b.img+a.real+b.img;
	return c;
	}
adt div(adt a,adt b){
	adt c;
	c.real=(a.real*b.real+a.img*b.img)/(b.real*b.real+b.img*b.img);
	c.img=(b.real*a.img-a.real*b.img)/(b.real*b.real+b.img*b.img);
	return c;
	}
float modulus(adt a,adt b){
	return sqrt((a.real-b.real)*(a.real-b.real)+(a.img-b.img)*(a.img-b.img));
		}	

int main(){
	adt i,j,l;
  int k;
  float h;
  scanf("%f",&i.real);
  scanf("%f",&i.img);
  scanf("%f",&j.real);
  scanf("%f",&j.img);
  scanf("%d",&k);
  if(k==1){
		l=add(i,j);
		printf("%f + %fi\n",l.real,l.img);
  }
  else if(k==2){
		l=sub(i,j);
    printf("%f + %fi\n",l.real,l.img);
  }
  else if(k==3){
		l=mul(i,j);
    printf("%f + %fi\n",l.real,l.img);
  }
	else if(k==4){
		l=div(i,j);
    printf("%f + %fi\n",l.real,l.img);
  }
	else if(k==5){
		h=modulus(i,j);
    printf("%f\n",h);
  }	
	else if(k==0 || k==-1)
	{
    printf("\n");
  }	
}

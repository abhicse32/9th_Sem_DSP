// lab1_1 Complex number 

#include<stdio.h>
#include<math.h>

//typedef struct complex complex

struct complex
{
	float p;
	float q;	
};

//function prototypes

struct complex add(struct complex,struct complex);
struct complex subtract(struct complex,struct complex);
struct complex mutiply(struct complex,struct complex);
struct complex divide(struct complex,struct complex);
float distance(struct complex,struct complex);
void printcomp(struct complex);

//function definitions

struct complex add(struct complex s,struct complex t)   
{
	struct complex r;
	
	r.p=s.p+t.p;
	r.q=s.q+t.q;		         // r=s+t
	return r;	
}

struct complex subtract(struct complex s,struct complex t)   
{
	struct complex r;
	
	r.p=s.p-t.p;
	r.q=s.q-t.q;		         // r=s-t
	return r;	
}

struct complex multiply(struct complex s,struct complex t)   
{
	struct complex r;

	r.p= s.p*t.p - s.q*t.q;
	r.q= s.p*t.q + s.q*t.p;          // a+ib * c+id = (ac-bd) + i(ad+bc)
	return r;
}

struct complex divide(struct complex s,struct complex t)  
{
	struct complex r;
	float mod;		         // prod= (a+ib)*(c-id)/ (c^2+d^2)
 
	mod = t.p*t.p + t.q*t.q;
	r.p = (s.p*t.p + s.q*t.q)/mod;
	r.q = (-s.p*t.q + s.q*t.p)/mod;
	return r;
}

float distance(struct complex s,struct complex t) 
{				
	float value;				 // s-t
	value= sqrt( (s.p-t.p)*(s.p-t.p) + (t.p-t.q)*(t.p-t.q) );
	return value;		
}

void printcomp(struct complex val)
{
	printf("%f + %fi", val.p ,val.q);
}	   


void main()
{	
	struct complex first,second;
	struct complex val;
	float val1;
	int n;

	scanf("%f %f", &first.p , &first.q);
	scanf("%f %f", &second.p, &second.q);
	scanf("%d",&n);

	switch(n)
	{
		case 1:  val=add(first,second); printcomp(val); break;
		case 2:  val=subtract(first,second); printcomp(val);break;
		case 3:  val=multiply(first,second); printcomp(val);break;
		case 4:  val=divide(first,second); printcomp(val);break;
		case 5:  val1=distance(first,second); printf("%f",val1);break;
		case 0:  break;	  
	}

}


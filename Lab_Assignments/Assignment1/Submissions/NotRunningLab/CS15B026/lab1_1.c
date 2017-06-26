#include<stdio.h>
#include<math.h>

struct complx
{
	float a;//real number
	float b;//imaginary number
	};



void add(struct complx complexx,struct complx comlpexy);


void sub(struct complx complexx,struct complx comlpexy);

	
void mul(struct complx complexx,struct complx comlpexy);


void div(struct complx complexx,struct complx complexy);


float mod(struct complx complex);

void print(struct complx complex);

void dist(struct complx complexx,struct complx complexy);


int main()
{
	int code=10;
	struct complx complex[3];
	
	scanf("%f %f %f %f", &complex[0].a,&complex[0].b,&complex[1].a,&complex[1].b);
	while(code!=0 && code!=-1)
	{
		scanf("%d", &code);
		switch (code)
		{
			case 1:
				add(complex[0],complex[1]);
				break;
			case 2:
				sub(complex[0],complex[1]);
				break;
			case 3:
				mul(complex[0],complex[1]);
				break;
			case 4:
				div(complex[0],complex[1]);
				break;
			case 5:
				dist(complex[0],complex[1]);
				break;
			default:
				break;
			}
		}
	return 0;
	}
				

void add(struct complx complexx,struct complx complexy)
{
	struct complx complexz;
	complexz.a=complexx.a+complexy.a;
	complexz.b=complexx.b+complexy.b;
	print(complexz);
	return;
	}

void sub(struct complx complexx,struct complx complexy)
{
	struct complx complexz;
	complexz.a=complexx.a-complexy.a;
	complexz.b=complexx.b-complexy.b;
	print(complexz);
	return;
	}
	
void mul(struct complx complexx,struct complx complexy)
{
	struct complx complexz;
	complexz.a=complexx.a*complexy.a-complexx.b*complexy.b;
	complexz.b=complexx.a*complexy.b+complexx.b*complexy.a;
	print(complexz);
	return;
	}

void div(struct complx complexx,struct complx complexy)
{
	struct complx complexz;
	complexz.a=(complexx.a*complexy.a+complexx.b*complexy.b)/mod(complexy);
	complexz.b=(-complexx.a*complexy.b-complexx.b*complexy.a)/mod(complexy);
	print(complexz);
	return;
	}

float mod(struct complx complex)
{
	float modulus;
	modulus=complex.a*complex.a+complex.b*complex.b;
	return modulus;
	}

void print(struct complx complex)
{
	printf("%f %f\n",complex.a,complex.b);
	}

void dist(struct complx complexx,struct complx complexy)
{
	float dist;
	dist=sqrt((complexx.a-complexy.a)*(complexx.a-complexy.a)+(complexx.b-complexy.b)*(complexx.b-complexy.b));
	printf("%.6f\n", dist);
	return;
	}

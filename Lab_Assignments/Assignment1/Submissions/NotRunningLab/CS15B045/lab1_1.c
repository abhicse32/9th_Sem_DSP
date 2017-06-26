#include<stdio.h>
#include<math.h>

struct Complex
{
	float real;
	float img;
};

struct Complex Add(struct Complex p,struct Complex q)
{
	struct Complex result;

	result.real = p.real + q.real;
	result.img = p.img + q.img;

	return result;
}

struct Complex Sub(struct Complex p,struct Complex q)
{
	struct Complex result;

	result.real = p.real - q.real;
	result.img = p.img - q.img;

	return result;
}

struct Complex Mult(struct Complex p,struct Complex q)
{
	struct Complex result;

	result.real = (p.real*q.real)-(p.img*q.img);
	result.img = (p.real*q.img)+(p.img*q.real);

	return result;
}

struct Complex Div(struct Complex p,struct Complex q)
{
	struct Complex result;

	result.real = ((p.real*q.real)+(p.img*q.img))/(q.real*q.real + q.img*q.img);
	result.img = ((p.img*q.real)-(p.real*q.img))/(q.real*q.real + q.img*q.img);

	return result;
}

float Mod(struct Complex p)
{
	float result;

	result = sqrt((p.real*p.real)+(p.img*p.img));

	return result;
}

float Dist(struct Complex p,struct Complex q)
{
	struct Complex a;
	float distance;
	a = Sub(p,q);
	distance = Mod(a);

	return distance;
}

void complexprint(struct Complex p)
{
	printf("%f + %fi\n",p.real,p.img);
}

int main()
{
	struct Complex p,q;
	int c;

	/*struct Complex Add(struct ,struct );
	struct Complex Sub(struct ,struct );
	struct Complex Mult(struct ,struct );
	struct Complex Div(struct ,struct );
	struct Complex Mod(struct );
	struct Complex Dist(struct ,struct );
	void complexprint(struct );*/

	do{
		scanf("%d",&c);
		switch(c)
			{
				case 1:
				scanf("%f",&p.real); 
				scanf("%f",&p.img);
				scanf("%f",&q.real);
				scanf("%f",&q.img);

				complexprint(Add(p,q));
				break;

				case 2:
				scanf("%f",&p.real); 
				scanf("%f",&p.img);
				scanf("%f",&q.real);
				scanf("%f",&q.img);

				complexprint(Sub(p,q));
				break;

				case 3:
				scanf("%f",&p.real); 
				scanf("%f",&p.img);
				scanf("%f",&q.real);
				scanf("%f",&q.img);

				complexprint(Mult(p,q));
				break;

				case 4:
				scanf("%f",&p.real); 
				scanf("%f",&p.img);
				scanf("%f",&q.real);
				scanf("%f",&q.img);

				complexprint(Div(p,q));
				break;

				case 5:
				scanf("%f",&p.real); 
				scanf("%f",&p.img);

				printf("%.6f\n",Mod(p));
				break;

				case 6:
				scanf("%f",&p.real); 
				scanf("%f",&p.img);
				scanf("%f",&q.real);
				scanf("%f",&q.img);

				printf("%f\n",Dist(p,q));
				break;

				case 0:
				return 0;

				default:
				printf("Invalid options");
			}
	}while(c!=0);

}

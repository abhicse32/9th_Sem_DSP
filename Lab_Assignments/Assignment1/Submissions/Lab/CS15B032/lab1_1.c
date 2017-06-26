/*
Program to operate on struct complex number
and print the result
cs15b032
8/7/16
*/

#include<stdio.h>
#include<math.h>

/*
variable to store complex number
*/
struct complex
{
float p,q;
};

/*
Function to add and return answer
*/
struct complex add(struct complex a,struct complex b)
{
struct complex ans;
ans.p=a.p+b.p;
ans.q=a.q+b.q;
return ans;
}

/*
Function to subtract and return answer
*/
struct complex sub(struct complex a,struct complex b)
{
struct complex ans;
ans.p=a.p-b.p;
ans.q=a.q-b.q;
return ans;
}

/*
Function to multiply and return answer
*/
struct complex mul(struct complex a,struct complex b)
{
struct complex ans;
ans.p=a.p*b.p-a.q*b.q;
ans.q=a.p*b.q+b.p*a.q;
return ans;
}

/*
Function to divide (i.e. multiply conjugate and divide by mod square) and return answer
*/
struct complex div(struct complex a,struct complex b)
{
struct complex ans;
ans.p=(a.p*b.p+a.q*b.q)/(b.p*b.p+b.q*b.q);
ans.q=(b.p*a.q-a.p*b.q)/(b.p*b.p+b.q*b.q);
return ans;
}

/*
Function to find modulus and return answer
*/
float mod(struct complex a)
{
return sqrt(a.p*a.p+a.q*a.q);
}

/*
Function to find distance (i.e. modulus of difference in complex numbers) and return answer
*/
float dis(struct complex a,struct complex b)
{
struct complex ans1;
float ans;
ans1=sub(a,b);
ans=mod(ans1);

return ans;
}

int main()
{
struct complex a,b,res;
int flag=0,choice;
	while(flag==0)
	{
	
	scanf("%f %f",&a.p, &a.q);
	scanf("%f %f",&b.p, &b.q);
	scanf("%d",&choice);

	/*
	to evaluate the entered choice or to quit
	*/
	switch (choice)
		{
		case 1:
		res=add(a,b);
		printf("%.6f ",res.p);
		if(!(res.q<0))
		printf("+");
		printf("%.6fi\n",res.q);
		break;
		
		case 2:
		res=sub(a,b);
		printf("%.6f ",res.p);
		if(!(res.q<0))
		printf("+");
		printf("%.6fi\n",res.q);
		break;
		
		case 3:
		res=mul(a,b);
		printf("%.6f ",res.p);
		if(!(res.q<0))
		printf("+");
		printf("%.6fi\n",res.q);
		break;
		
		case 4:
		res=div(a,b);
		printf("%.6f ",res.p);
		if(!(res.q<0))
		printf("+");
		printf("%.6fi\n",res.q);
		break;
		
		case 5:
		printf("%.6f\n",dis(a,b));
		break;
		
		case 0:
		case -1:	
		flag=1;
		break;
	
		default:
		flag=1;
		};
	};
return(0);
}




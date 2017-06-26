#include<stdio.h>
#include<math.h>
struct complex {
	float p;
	float q;
	}; /* declaration of complex number as a structure*/ 
void add(struct complex c1,struct complex c2);/*declaration of functions such as complex number addition*/
void sub(struct complex c1,struct complex c2);/*no return value required as void type is used*/
void mult(struct complex c1,struct complex c2);
void div(struct complex c1,struct complex c2);
void distance(struct complex c1,struct complex c2);
void print(struct complex ans);/*using print function */
int main()
{
	struct complex c1,c2,ans;/*three complex numbers are declared*/
	int i=11;
	scanf("%f %f",&c1.p,&c1.q);/*taking input of two complex numbers*/
	scanf("%f %f",&c2.p,&c2.q);
	while(i!=-1)/*using sentinel to terminate program*/
	{
	scanf("%d",&i);
	if(i==1){
	add(c1,c2);
		}
	else if(i==2){
	sub(c1,c2);
		}
	else if(i==3){
	mult(c1,c2);
		}
	else if(i==4){
	div(c1,c2);
		}
	else if(i==5){
	distance(c1,c2);
		}
	}
return 0;
}
	void print(struct complex ans){/*using print function to print the output*/
	printf("%.6f + %.6fi\n",ans.p,ans.q);
	}
	void add(struct complex c1,struct complex c2){
	struct complex ans;
	ans.p=c1.p+c2.p;
	ans.q=c1.q+c2.q;
	print(ans);/* calling the print function */
	}
	void sub(struct complex c1,struct complex c2){
	struct complex ans;
	ans.p=c1.p-c2.p;
	ans.q=c1.q-c2.q;
	print (ans);
	}
	void mult(struct complex c1,struct complex c2){
	struct complex ans;
	ans.p=(c1.p*c2.p-c1.q*c2.q);
	ans.q=(c1.p*c2.q+c1.q*c2.p);
	print (ans);
	}
	void div(struct complex c1,struct complex c2){/*using function for division of two Complex Numbers*/
	struct complex ans;
	ans.p=((c1.p*c2.p)+(c1.q*c2.q))/((c2.p*c2.p)+(c2.q*c2.q));
	ans.q=((c1.q*c2.p)-(c1.p*c2.q))/((c2.p*c2.p)+(c2.q*c2.q));
	print (ans);
	}
	void distance(struct complex c1,struct complex c2){/*using function for distance between two Complex Numbers*/
	struct complex ans;
	ans.p=sqrt((c1.p-c2.p)*(c1.p-c2.p)+(c1.q-c2.q)*(c1.q-c2.q));/*using sqrt as math library is included */
	printf("%.6f\n",ans.p);/*foating point value precise upto 6 digits after decimal */
	}

#include<stdio.h>
#include<math.h>

struct complex
{
	float real;
	float img;
};

struct complex Add(struct complex num1,struct complex num2)
{
	struct complex ans;
	ans.real = num1.real + num2.real;
	ans.img = num1.img + num2.img;
	return ans;
}

struct complex Subtract(struct complex num1,struct complex num2)
{
	struct complex ans;
	ans.real = num1.real - num2.real;
	ans.img = num1.img - num2.img;
	return ans;
}

struct complex Mult(struct complex num1,struct complex num2)
{
	struct complex ans;
	ans.real = num1.real*num2.real - num1.img*num2.img;
	ans.img = num1.real*num2.img + num1.img*num2.real;
	return ans;
}

float Dist(struct complex num1,struct complex num2)
{
	float ans;
	ans = (num1.real-num2.real)*(num1.real-num2.real) + (num1.img-num2.img)*(num1.img-num2.img) ;
	ans = sqrt(ans);
	return ans;
}

struct complex Div(struct complex num1,struct complex num2)
{
	struct complex in1,in2,temp,ans;
	temp.real=0;
	temp.img=0;
	// Division is performed as mult of (num1*num2_conjugate)/(modulus(num2))^2
	// num1/num2= Mult((num1/modnum2),(num2_conjugate/modnum2))

	in1.real = (num1.real)/Dist(num2,temp) ; // Dist(num2,temp) -->modulus of num2
	in1.img = (num1.img)/Dist(num2,temp) ;
	in2.real = num2.real/Dist(num2,temp) ;
	in2.img = -num2.img/Dist(num2,temp);

	ans = Mult(in1,in2);	
	
	return ans;
}

int main()
{
	struct complex num1,num2,ans;
	int choice;
	float dist;
        //Scan Input 
	scanf("%f%f",&num1.real,&num1.img);
	scanf("%f%f",&num2.real,&num2.img);
	
	scanf("%d",&choice);
	while(choice!=-1)  //-1 --> sentinel value for exiting program
	{
		if(choice==1) //add
		{
			ans = Add(num1,num2);
			if(ans.img>=0)
				printf("%.6f+%.6fi\n",ans.real,ans.img);
			else
				printf("%.6f%.6fi\n",ans.real,ans.img);
		}	
		else if(choice==2) //sub
		{
			ans = Subtract(num1,num2);
			if(ans.img>=0)
				printf("%.6f+%.6fi\n",ans.real,ans.img);
			else
				printf("%.6f%.6fi\n",ans.real,ans.img);

		}
		else if(choice==3) //mult
		{
			ans = Mult(num1,num2);
			if(ans.img>=0)
				printf("%.6f+%.6fi\n",ans.real,ans.img);
			else
				printf("%.6f%.6fi\n",ans.real,ans.img);

		}
		else if(choice==4) //div
		{
		
			if(num2.real==0 && num2.img==0)  //error check
				printf("Divide by 0 Error\n");
			else
			{
				ans = Div(num1,num2);
			
				if(ans.img>=0)
					printf("%.6f+%.6fi\n",ans.real,ans.img);
				else
					printf("%.6f%.6fi\n",ans.real,ans.img);
			}
		}
		else if(choice==5)  //dist
		{
			dist = Dist(num1,num2);
			printf("%f\n",dist);
		}
		scanf("%f%f",&num1.real,&num1.img);
		scanf("%f%f",&num2.real,&num2.img);
		scanf("%d",&choice);
	}	
	return 0;
}

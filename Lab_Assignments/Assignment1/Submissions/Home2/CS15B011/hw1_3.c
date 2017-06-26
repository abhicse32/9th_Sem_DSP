													/*program to find prime common factors by Akshay Kumar*/

#include<stdio.h>

void main()
{
	int i,a,b,t;														/*declaration of variables*/
	scanf("%d %d",&a,&b);
	if(a>b)
	{
		t=a;
		a=b;
		b=t;
	}
	for(i=2;i<=a;i++)
	{
		if(((a%i)==0)&&((b%i)==0)&&(prime(i)==1))
		printf("%d ",i);
	}
	printf("\n");
}

int prime(int n)
{
	int i,flag=0;
	for(i=2; i<=n/2; ++i)
    {
        if(n%i==0)
        {
            flag=1;
            break;
        }
    }

    if (flag==0)
        return 1;
    else
        return 0;

}

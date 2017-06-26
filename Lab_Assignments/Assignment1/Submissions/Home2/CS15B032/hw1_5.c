
/* project completed 
	by R.D.Nishal Singh, CS15B032 on 13.8.16
*/

int main()
{
int n;
scanf("%d",&n);
double p=10;
for(i=0;m!=0;i++)
	{
	m=n/10;
	if(i%2==0)
	p/=10;	
	}
int k=15+(i)/2;

double a,b;

for(i=0;i<k;i++)
	{
	for(j=0;j<10;j++)
		{
		b=a+((double)(j+1))/p;
		a=a+((double)j)/p;

		if(a*a<=n&&b*b>n)
		break;
		}
	p*=10;
	}

	printf("%.15f", a);
	return 0;
}

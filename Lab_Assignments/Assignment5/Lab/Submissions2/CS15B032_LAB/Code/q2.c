#include<stdio.h>
#include<string.h>

int main()
{
int t;
scanf("%d",&t);
int s;
int rev,n;
char A[1000];
for(;t>0;t--)
	{
	rev=0;
	n=0;
	scanf("%s",A);
	s=strlen(A);
	if(s%2==1)
		{
		printf("-1\n");
		continue;
		}
	for(;s>0;s--)
		{
		if(A[s-1]=='}')
		n++;
		else
			{
			if(n>0)
			n--;
			else
				{
				rev++;
				n++;
				}
			}
		}
	rev+=n/2;
	printf("%d\n",rev);

	}

return 0;
}



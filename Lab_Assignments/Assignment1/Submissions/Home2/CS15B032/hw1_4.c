
/* project completed 
	by R.D.Nishal Singh, CS15B032 on 13.8.16
*/

int locate(char* a,int l,char b)
{
	int i=0;
	while(i<l)
	{	if(a[i]==b)
		{
		a[i]='0';
		return 1;
		}
	}
return 0;	
}
int main()
{
	char a[100];
	char b[100];

	scanf("%s %s", a, b);
	
	int l=strlen(a);
	
	if(l!=strlen(b))
	{
	printf("0");
	return 0;
	}
	
	int i,flag=0;

	for(i=0;i<l;i++)
	{
		if(locate(a,l,b[i]))
		{
		flag=0;
		break;
		}
	}
printf("%d",flag);
return 0;
}

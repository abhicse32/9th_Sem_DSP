#include<stdio.h>
#include<string.h>
void main()
{
	char a[100];
	char b[100];
	scanf("%s",a);
	scanf("%s",b);
	int n1 = strlen(a);
	int n2 = strlen(b);
	if(n1 != n2)
		printf("0");
	else
	{
		int a1[26] = {0};
		int a2[26] = {0};
		int c = 0;
		while(a[c]!='\0')
		{
			a1[a[c] - 'a']++;
			c++;
		}
		
		c = 0;
		while(b[c]!='\0')
		{
			a2[b[c] - 'a']++;
			c++;
		}
		
		c = 0;
		for(c = 0;c<26;c++)
		{
			if(a1[c] != a2[c])
			{	
				printf("0");
				break;
			}
		}
		if(c == 26)
			printf("1");
	}
}	
	
	


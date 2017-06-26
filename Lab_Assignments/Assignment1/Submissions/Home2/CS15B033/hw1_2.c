#include <stdio.h>
#include <string.h>

/* Completed by R.Gokulan, Roll num.CS15B033 on 14.8.16*/

char out[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
char hex(int x)
{
	return out[x];
}
int main()
{
	long int n;
	int i = 0;
	scanf("%ld", &n);
	char ans[8];
	while(i<8)
	{
		ans[7-i] = hex(n%16);
		n = n/16;
		i++;
	}
	int l = strlen(ans);
	printf("0x");
	for( i = 0; i <= l; i++)
	{
		printf("%c",ans[i]);
	}
}

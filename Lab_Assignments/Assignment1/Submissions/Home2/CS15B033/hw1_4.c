#include <stdio.h>
#include <string.h>

/* Completed by R.Gokulan, Roll num.CS15B033 on 11.8.16*/


void search(char* a, int len, char b )
{
	int i = 0;
	while( i < len)
	{
		if( *(a+i) == b)
		{
			*(a+i) = '0';
		}
		i++;

	}
}

int main()
{
	char a[100];
	char b[100];

	scanf("%s %s", a, b);
	int l = strlen(a);
	int j;
	for( j = 0; j<l ; j++)
	{
		search(a,l,b[j]);
	}

	int flag = 0;
	int k = 0;
	while(flag == 0 && k<l)
	{
		if( *(a+k) != '0')
		{
			flag = -1;
			break;
		}
		k++;
	}
	if( flag == 0)
		printf("1\n");
	else
		printf("0\n");


}

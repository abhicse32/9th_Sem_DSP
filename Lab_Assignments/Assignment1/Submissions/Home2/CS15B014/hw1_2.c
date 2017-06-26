/* Hexadecimal equivalent of the input integer*/
/*name D Teja Vardhan Reddy cs15b014 date 14/8/16*/
#include <stdio.h>
int main(){				/*main function*/
	int n,i,a[10];
	scanf("%d",&n);
	for ( i = 0; i < 8; ++i)
	{
		a[i]=n%16;
		n=n/16;
	}
	printf("0x");				/*printf function*/
	for (int i = 7; i >=0; --i)
	{
		if(a[i]>=10)
			printf("%c",(char)a[i]+87);			/*type casting */
		else
			printf("%d",a[i]);

		
		
	}
	printf("\n");
}
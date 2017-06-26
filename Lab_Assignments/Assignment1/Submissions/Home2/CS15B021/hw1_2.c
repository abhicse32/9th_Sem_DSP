#include<stdio.h>

int main()
{
int x[8], p[8],i;

scanf("%d",&p[0]);

for( i=0; i<=8; i++ )
{
  x[i] = p[i]%16;
  p[i+1] = p[i]/16;
}

printf("0x");

for( i=8; i>=0; i-- )
{
  if( x[i]<=9 ) {

    printf("%d",x[i]);

		}

  else if( x[i]>9 ) {

    switch(x[i]) {
		  case 10 : printf("a");
			break;
		  case 11 : printf("b");
			break;
		  case 12 : printf("c");
			break;
		  case 13 : printf("d");
			break;
		  case 14 : printf("e");
			break;
		  case 15 : printf("f");
			break;
		 }
	            }
}
printf("\n");

return 0;
}

#include<stdio.h>
void print(int z);/* declaring the function print */
int main()
{
  int n,i;
  int hexadecimal[8];/*declaring an array */
	scanf("%d",&n);/*taking input */
	for(i=0;i<8;i++)
	{
	   hexadecimal[i]=(n%16);/*converting decimal to hexadecimal equivalent */
	   n=n/16;
	}
	     printf("0x");
	     for(i=8;i>-1;i--)
	     {
	       print(hexadecimal[i]);
	     }
	        printf("\n");
  return 0;
}
void print(int z)/*using a function to print the hexadecimal equivalent */
{
	if(z>=0 && z<10)
	printf("%d",z);
	else
	{
	   if(z==10) printf("a");
	   if(z==11) printf("b");
	   if(z==12) printf("c");
	   if(z==13) printf("d");
	   if(z==14) printf("e");
	   if(z==15) printf("f");
	}
}


/* A program to convert a decimal number to hexadecimal.
   Author:CS15B046 Jahnvi Patel
   Date:August 9, 2016
*/

#include <stdio.h>
/* A function that converts to hexadecimal by remainder method and assigns 0 to all empty bits in the array.
   Return type:none
   Parameters: n the decimal number*/


void hexa(int n)
{
 int i;
char h[8];
int pos=0,rem;
while(n>0)
{
 
  rem=n%16;
  if(rem>=10)
    { if(rem==10)
         h[pos]='a';
    	else if(rem==11)
 			h[pos]='b';
		else if(rem==12)
			h[pos]='c';
		else if(rem==13)
			h[pos]='d';
		else if(rem==14)
			h[pos]='e';
		else if(rem==15)
			h[pos]='f';}
  else h[pos]=48+rem;
  n/=16;
pos++;
}
//Assigning empty bits to zero
 for(i=pos;i<8;i++)
   h[i]=48;
 printf("0x");
 for(i=7;i>=0;i--)
  printf("%c",h[i]); //Printing the final hexadecimal output
 printf("\n");
}

void main()
{
	int n;
	scanf("%d",&n); // Decimal number to be converted
    hexa(n);
 }



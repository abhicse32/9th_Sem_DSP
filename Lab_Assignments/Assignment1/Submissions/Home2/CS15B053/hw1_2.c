#include<stdio.h>
#include<stdlib.h>
#include<string.h>

reverse(char *s)
{
	int i = 0, j = strlen(s) - 1;
	char tempchar;
	 
	while (i < j) 
	{	
	      tempchar = s[i];
	      s[i] = s[j];
	      s[j] = tempchar;
	      i++;
	      j--;
   	}
}

int convertbase(int num, char *hx)
{		
	int hxcount=0;
	int remainder;
	char values[]="0123456789abcdef";
	do
	{	
		remainder = num%16;
		num = num/16;
		hx[hxcount++] = values[remainder];
		
	}while(num>0);
	
	int zeroesrequired = 8-(hxcount%8);
	int zerocount;
	for(zerocount=0; zerocount<zeroesrequired; zerocount++)
	{
		hx[hxcount++] = '0';
	}
	
	int i = 0, j = hxcount-1;
	char tempchar;
	 
	while (i < j) 
	{	
	      tempchar = hx[i];
	      hx[i] = hx[j];
	      hx[j] = tempchar;
	      i++;
	      j--;
   	}
	
	return hxcount;
		
	
}


void main()
{
	int num;
	char hx[100];
		
	scanf("%d",&num);
	
	int hexlength = convertbase(num, hx);
	int i;
	
	printf("0x");
	
	for(i=0; i<hexlength; i++)
	{
		printf("%c", hx[i]);
	}
	
}
	

#include<stdio.h>
void main()
{
	int n;
	printf("enter the value of n:");
	scanf("%d",&n);
	char array[10];
	int i = 0;
	int c = n;
	int k;
	
	while(c!=0)
	{	
		k = c%16;
		if(k == 0)
		 array[i] = '0';
		if(k == 1)
		 array[i] = '1';
		if(k == 2)
		 array[i] = '2';
		if(k == 3)
		 array[i] = '3';
		if(k == 4)
		 array[i] = '4';
		if(k == 5)
		 array[i] = '5';
		if(k == 6)
		 array[i] = '6';
		if(k == 7)
		 array[i] = '7';
		if(k == 8)
		 array[i] = '8';
		if(k == 9)
		 array[i] = '9';
		 
		
		
		if(k == 10)
	         array[i] = 'A';
		if(k == 11)
		 array[i] = 'B';
		if(k == 12)
		 array[i] = 'C';
		if(k == 13)
		 array[i] = 'D';
		if(k == 14)
		 array[i] = 'E';
		if(k == 15)
		 array[i] = 'F';
		
		c = c/16;
		i++;
	}
	printf("0x");
	int l = i;
	for(l = i;l < 8;l++)
	{
		array[l] = '0';
		printf("%c",array[l]);
	}	
	int j = i-1;
	for(j = i-1;j > -1;j = j-1)
	{
		printf("%c",array[j]);
	}
	
		
}
			

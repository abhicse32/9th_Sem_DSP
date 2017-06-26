#include<stdio.h>
int main() 
{
   long int n,r,q;
   int i=1,j,temp;
   char number[100];
   scanf("%ld",&n);  // read the number
   for(q=n;q!=0;q=q/16)
   {
      temp=q%16;  	//To convert integer into character
      if(temp<10)
          temp=temp + 48; //To convert the integer to respective ascii value
      else
    	   temp=temp + 55;
    	number[i++]= temp;
    }
   for (j= i-1;j>0;j--)
    {
        printf("%c",number[j]);
    }
   return 0;
 }

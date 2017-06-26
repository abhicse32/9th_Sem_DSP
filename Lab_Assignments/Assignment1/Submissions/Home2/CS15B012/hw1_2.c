#include<stdio.h>
#include<assert.h>
#include<stdlib.h>


int main()
 {
   long long int n;//As the input is 10(pow 9)
   scanf("%lld",&n);
   assert((n>=1)&&(n<=1000000000));// checking wether the number is in the reserved boundary or not
   int *r;
r=(int *)malloc(n*sizeof(int));// dynamic allocation of space
 if(r==0)
{return 1;}
int i;// calucating digits in hexa
      for(i=0;n!=0;i++)  
	{
         r[i]=(n%16);
	  n=(n/16);
	}
int k=i-1;
printf("0x");// formatting the way of printing
int j=k;
for(;j<=8-k;j++)
{printf("0");}

       for(i=k;i>=0;i--)   //assigning variabls to different the remainders so that it matches with hexadecimal format
           { switch(r[i])
		{case 10:printf("a");
			 break;
                case 11:printf("b");
			 break;
                case 12:printf("c");
			 break;
                case 13:printf("d");
			 break;
                case 14:printf("e");
			 break;
                case 15:printf("f");
			 break;
                
                default:printf("%d",r[i]);
                        break;
                }
        	   }
free((int *)r);// freeing dynamically allocated space

 return 0;
 }

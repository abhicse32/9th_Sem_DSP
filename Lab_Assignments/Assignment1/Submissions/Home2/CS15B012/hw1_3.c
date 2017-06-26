#include<stdio.h>
#include<math.h>
int main()
 {
  int n1,n2,x;
  scanf("%d %d",&n1,&n2);//scaning 2 inputs
  if(n2>n1)
	{
          x=n2;
          n2=n1;
	  n1=x;
	} 
     int i,j;
    if((n1%2==0)&&(n2%2==0))// if both are even then 2 will definetly be prime factor 
    printf("2 ");
       for(i=3;i<=n2;)// minimising the opertions by computing with only odd since other evens are composite
 	 {
	   if((n1%i==0)&&(n2%i==0))
             {
		for(j=2;j<sqrt(i);j++)
	            {
			if(i%j==0)
                        break;
		    }
		if((j-1)==((int)sqrt(i)))// it is enough to compute till root of i.
			{printf("%d ",i);}                
             }
         i=i+2;
	 }
return 0;
 }

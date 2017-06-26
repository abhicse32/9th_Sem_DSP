#include<stdio.h>
#include<assert.h>
int main()
{
  int n,i;
  scanf("%d",&n);// reading number of integers input
 assert((n>=1)&&(n<=100));// checking the condition for the number of inputs
  int num[n];
for(i=0;i<n;i++)// reading inputs
   {
     scanf("%d",&num[i]);
   }
  int maxi=num[0],mini=num[0];// declaration of required variables and temparary assignment
    if((n%2)==0)//doing it for even numbers
      {
       for(i=0;i<n;)
	{
          if(num[i]>num[i+1])// updating the temparory maximum and minimum
           {
            if(num[i]>maxi)
            maxi=num[i];
	    if(num[i+1]<mini)
            mini=num[i+1]; 
           }
          else
           {
            if(num[i+1]>maxi)
            maxi=num[i+1];
	    if(num[i]<mini)
            mini=num[i]; 
                     
           } i=i+2;	
        }
       printf("%d %d\n",mini,maxi);// printing the min and max
     }

    if((n%2)==1)// for ood numbers
      {
       for(i=1;i<n;)
	{
          if(num[i]>num[i+1])
           {
            if(num[i]>maxi)
            maxi=num[i];
	    if(num[i+1]<mini)
            mini=num[i+1]; 
           }
          else
           {
            if(num[i+1]>maxi)
            maxi=num[i+1];
	    if(num[i]<mini)
            mini=num[i]; 
                     
           } i=i+2;	
        }
       printf("%d %d\n",mini,maxi);
     }
return 0;
}

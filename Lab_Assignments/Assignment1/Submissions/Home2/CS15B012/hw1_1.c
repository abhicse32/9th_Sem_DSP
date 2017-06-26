#include<stdio.h>
#include<assert.h>

int main()
 {
     long int n,i;
     scanf("%ld",&n);//input of number of integers
     assert((n>=2)&&(n<=100000));// to check the condition or limitation on number of integers
     int num[n];//defining the array ot store numbers
     for(i=0;i<n;i++)
       {  
 	 scanf("%d",&num[i]);
       }
	int max1,max2;
        if(num[0]>num[1])//temperary asignment of variables
	  {
	    max1=num[0];
	    max2=num[1];
	  }
	else
	  {
	    max1=num[1];
	    max2=num[0];
	  }
     	if(n%2==0)// finding max and next max for even numbers
	   { for(i=2;i<n;)
		{  if(num[i+1]>num[i])
		     { if(num[i+1]>max1)
			  {
  			    max1=num[i+1];
		            if(num[i]>max2)
			    max2=num[i];
			  }
                       else
			  {
			   if(num[i+1]>max2)
			    max2=num[i+1];
			  }
			
		     }
		else
		     { if(num[i]>max1)
			  {
  			    max1=num[i];
		            if(num[i+1]>max2)
			    max2=num[i+1];
			  }
                       else
			  {
			   if(num[i]>max2)
			    max2=num[i];
			  }
		     }
  		   i=i+2;
	   
		}
          
 	printf("%d %d\n",max1,max2); 
	  }
	if(n%2==1)// finding max and next max for odd numbers
	   { for(i=1;i<n;)
		{  if(num[i+1]>num[i])
		     { if(num[i+1]>max1)
			  {
  			    max1=num[i+1];
		            if(num[i]>max2)
			    max2=num[i];
			  }
                       else
			  {
			   if(num[i+1]>max2)
			    max2=num[i+1];
			  }
		     }
		else
		     { if(num[i]>max1)
			  {
  			    max1=num[i];
		            if(num[i+1]>max2)
			    max2=num[i+1];
			  }
                       else
			  {
			   if(num[i]>max2)
			    max2=num[i];
			  }
		     }
  		   i=i+2;
	   
		}
 	printf("%d %d\n",max1,max2);
           }
	     
return 0;
}

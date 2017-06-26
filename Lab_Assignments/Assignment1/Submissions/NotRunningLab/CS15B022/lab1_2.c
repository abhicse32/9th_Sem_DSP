#include<stdio.h>
void maxmin(int array[],int n);
void main()
{
	int n;
	scanf("%d",&n);
	int array[100];
	int i = 0;
	for(i = 0;i<n;i++)
	  {
	    scanf("%d",&array[i]);
	   }
	maxmin(array,n);
}
void maxmin(int array[],int n)
{	int i = 2;int j = 1;int max;int min;
	if(n%2 == 0)
	 {
	   if(array[0]>array[1])
	     {
	       max = array[0];
	       min = array[1];
	     }
	   else
	     {
	       max = array[1];
	       min = array[0];
	     }

	   for(i = 2; i<n ; i=i+2)
	     {
               if(array[i]>array[i+1])
		{
		  if(array[i]>max)
		    max = array[i];
		  if(array[i+1]<min)
		    min = array[i+1];
		}
	       else
		{
		  if(array[i+1]>max)
		    max = array[i+1];
		  if(array[i]<min)
		    min = array[i];
		}
	      }
	}
	else
	  {
	    max = array[0];
	    min = array[0];
	    for(j=1;j<n;j = j+2)
             {
	      if(array[j]>array[j+1])
		{
		  if(array[j]>max)
		   max = array[j];
		  if(array[j+1]<min)
		   min = array[j+1];
		}
	      else
		{
                 if(array[j+1]>max)
		   max = array[j+1];
		 if(array[j]<min)
		   min = array[j];
		}
	       }
	  } 
	printf("%d %d\n",max,min);
}	
		  
		  
		
	      
		
		  
		  
		
	  
	  


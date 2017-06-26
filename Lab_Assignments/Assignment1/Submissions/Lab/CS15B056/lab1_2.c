#include <stdio.h>

int main () {

	int minn,maxx,n,i,j,l,r,k=0;
	scanf ("%d",&n);
	r=n;                          //as the value of n is altered later in code
	int max[(n/2)+1],min[(n/2)+1];	
	int a[n];
	for (i=0;i<n;i++)
	 scanf("%d",&a[i]);           //input the elements of array
	 maxx=a[0];minn=a[0];         //initialise minn and maxx
	 if (n%2==1)                  //if n is odd
	 {
	  
	   max[n/2]=a[n-1];
	   min [n/2]=a[n-1];
	   
	    n=n-1;                   //if n is odd,n-1 is even
	   }   
	  
	if (n%2==0)                  //divides the elements into two arrays, one containing min and other max elements
	 {
	  
	   for (j=0;j<n;j=j+2)  {
	     if (a[j]>=a[j+1]) {
	      max[k]=a[j];
	      min[k]=a[j+1];
	      k++;
	       }
	     else   {
	      max[k]=a[j+1];
	      min[k]=a[j];
	      k++;
	        }
	 }
	 max[n/2]=a[r-1];            //to keep the number of elements as n/2+1
	 min[n/2]=a[r-1];
	  } 
	 for (l=0;l<n/2+1;l++)        //to compute maxx and minn
	  {
	    if (max[l]>maxx)       
	     maxx=max[l];
	    if (min[l]<minn)
	     minn=min[l];          
	  }
	   printf ("%d %d",minn,maxx);
	   return 0;
	   
	   }
	        
	     
	    

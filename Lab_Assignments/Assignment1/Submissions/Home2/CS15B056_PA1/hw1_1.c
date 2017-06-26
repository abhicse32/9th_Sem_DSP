//Program to find maximum and next maximum of an array

# include <stdio.h>

int main ()
 {
  int n;
  scanf("%d",&n);
  int a[n],i,max,n_max,min;
  
  for (i=0;i<n;i++)         //input array
   scanf("%d",&a[i]);
  
  min=a[0];
	
	for (i=0;i<n;i++)
		if(a[i]<min)    //for finding minimum element of array
		min=a[i];
	n_max=min-1; 
	max=min-1;
	
	
  
  for (i=0;i<n;i++)           //for finding maximum element of array
   {
    if(a[i]>=max)
	{
		n_max=max;     
		max=a[i];
	}
     	 
    else if (a[i]>n_max)
		n_max=a[i];
		
   }
 
  printf("%d %d",max,n_max);       //printing maximum and next maximum element
  return 0;
 
 }     
   

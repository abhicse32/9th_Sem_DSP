#include<stdio.h>
//MAX AND SECOND MAX
void main()
{	
	int n;
	int a[10000];
	int k;
	scanf("%d",&n);

	int i=0;
	
	for (i = 0; i < n; i++)		scanf("%d",&a[i]);	   
 	int max1 = a[0];
 	int max2 = a[1];

    	if (max1 < max2)	    		
	{
		k = max1;
        	max1 = max2;
        	max2 = k;
    	}
	
    	for (i = 2;i < n;i++)
    	{
        	if (a[i] >= max1)
        	{
        	    	max2 = max1;
        	    	max1 = a[i];
        	}
	
        	else if (a[i] > max2)		max2 = a[i];
	
    	}
	
    	printf("%d %d\n",max1,max2);
 	 
}					

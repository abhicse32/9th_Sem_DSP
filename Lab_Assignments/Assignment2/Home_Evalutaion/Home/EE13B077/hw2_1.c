
/*

Author Name: Gudur Phani Karan Reddy (EE13B077)
Time: Sun Aug 21 21:15:45 IST 2016

Description:
This program takes a matrix of order 'n' as input and outputs its determinant.

*/


#include <stdio.h>

int matrix[20][20],n;

int det(int f[20][20],int x)
{

/*
	returns the determinant of the matrix passed
*/	

	int pr,c[20],d=0,b[20][20],j,p,q,t;

	if(x==2)
	{
		d=(f[1][1]*f[2][2])-(f[1][2]*f[2][1]);
		return(d);
	}

	else
	{
		for(j=1;j<=x;j++)
		{        
			int r=1,s=1;
			for(p=1;p<=x;p++)
		    	for(q=1;q<=x;q++)
		        	if(p!=1&&q!=j)
		          	{
			            b[r][s]=f[p][q];
			            s++;
			            if(s>x-1)
			            {
			                r++;
			                s=1;
		            	}
		          	}

	  		for(t=1,pr=1;t<=(1+j);t++)
	 			pr=(-1)*pr;

	  		c[j]=pr*det(b,x-1);
		}

		for(j=1,d=0;j<=x;j++)
    		d=d+(f[1][j]*c[j]);
		  
		return(d);
	}
}


int main()
{
  int i,j;
 
  printf("Order of matrix? \n");
  scanf("%d",&n);
  
  printf("Elements of matrix? \n");
 
  for(i=1;i<=n;i++)
  	for(j=1;j<=n;j++)
 	  scanf("%d",&matrix[i][j]);
 
 
  printf("%d \n",det(matrix,n));
  
  return 0;
}


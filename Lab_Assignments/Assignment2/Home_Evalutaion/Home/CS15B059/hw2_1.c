/* CS15B059 KOMMURU ALEKHYA REDDY 21AUG2016
TO OBTAIN THE DETERMINANT OF A MATRIX USING RECURSION*/
#include<stdio.h>
#include<math.h>
long determinant(int n,int a[10][10]);//defining the function prototypes
void main()
{
	int n;
	printf("Enter the size of the matrix");
	scanf("%d",&n);//to obtain the size of the matrix
	int a[10][10];
	int i,j,row=0,col=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);//to input all the values into the matrix
		}
	}
	long det=determinant(n,a);//calling the function determinant which returns a long value
	printf("%ld\n",det);
}

long determinant(int n,int a[10][10])
{
	int i,j,k,l, p,b[10][10];
	long dete= 0;
	if(n == 2)//base case if n==2, then caluculate the determinant using the following formula
		return (long)(a[0][0]*a[1][1]-a[1][0]*a[0][1]);
	else// if n >2 then do the following
		{
		for(p=0;p<n;p++)//p is used to increment the column while keeping the row index fixed as 0
		{
			k = 0, l = 0;// k and l are the row and column indices of the new matrix
			for(i = 1; i < n; i++)
			{
				l = 0;//l must be initailised to one after every row has been traversed
				for(j = 0; j < n; j++)
				{
					if(j != p)
					{
					b[k][l]=a[i][j];//assigning the values into the new matrix 
					l++;	//incrementing the column number by 1 after assigning a value to the new matrix
					}				
				}
				k++;//after traversing a row the row index of the new array must be increased by 1
			}
				dete=dete + a[0][p] * pow(-1,p) * determinant(n-1,b);	//calculates the determinant using recursion	
		}
	return dete;//finally returns the value of the determinant
	}
	
}


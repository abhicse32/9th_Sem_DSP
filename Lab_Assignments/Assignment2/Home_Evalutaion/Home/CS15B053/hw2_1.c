#include<stdio.h>
#include<stdlib.h>

int determinant(int matrix[10][10], int n)
{
	if(n==1)
		return matrix[0][0];
	
	else if(n==2)
	{
		return (matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0]);
	}
	
	else
	{
		int sum=0, temp;
		int i, j, k, p, q;
		int newmatrix[10][10];
		for(i=0; i<n; i++)
		{
			for(p=1; p<n; p++)
			{
				for(q=0,k=0; q<n; q++)
				{
					if(q!=i)
					{
						newmatrix[p-1][k] = matrix[p][q];
						k++;
					}
				}
			}
					
			temp = determinant(newmatrix, n-1);
			if(i%2==0)
				sum = sum + matrix[0][i] * temp;
			else
				sum = sum - matrix[0][i] * temp;
		}
		return sum;
	}
}

void main()
{
	int n;
	int matrix[10][10];
	
	scanf("%d", &n);
	
	int i,j;
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			scanf("%d", &matrix[i][j]);
			
	long det = determinant(matrix, n);
	printf("%ld", det);
}

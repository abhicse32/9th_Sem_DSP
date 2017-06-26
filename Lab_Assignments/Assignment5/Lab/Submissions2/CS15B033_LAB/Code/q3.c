#include <stdio.h>
#include <stdlib.h>
	
int main()
{
	int t;
	scanf("%d", &t);		//testcases
	int i;
	
	for(i=0; i<t; i++)
	{
		int n;
		scanf("%d", &n);		//no. of elements
		
		int *a = (int*) malloc( n*sizeof(int));
		int j;
		for( j=0; j<n; j++)
			scanf("%d", a+j);		//scans input
		
		int *A = (int*) malloc( n*sizeof(int));
		int top = -1;
		
		for( j=0; j<n; j++)
		{
			top++;
			A[top] = a[j];
			int k;
			for( k=j+1; k<n; k++)
			{
				if( a[k] <= a[j])
				{
					top++;
					A[top] = a[k];		
				}
				else
				{
					printf("%d ", a[k]);
					top = -1;
					break;
				}
			}
			if( k == n)
				printf("-1 ");		//if greater element is not found
		}
		free(a);
		free(A);
		printf("\n");
	}
	return 0;
}

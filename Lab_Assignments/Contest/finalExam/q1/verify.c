#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

long long int a[1002][1002];
long long int b[1002][1002];
long long int up[1002],down[1002];
long long x,y;

void print(long long int d[][1002], int n)
{
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            printf("%4lld", d[i][j]);
        printf("\n");
    }
    printf("\n");
}

long long int min(long long int x1, long long int y1)
{
    if(x1<y1)
        return x1;
    return y1;
}

int main() {
    int n,i,j,k;
    long long int m;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%lld",&a[i][j]);
            b[i][j]=-1;
        }
    }

    if (n == 1) {
      m = a[0][0];
    } else {
      //find the min cost for last column
      for (int i=0; i<n; i++)
	b[i][n-1] = a[i][n-1];

      //recursively calculate the cost
      for (int i = n-2; i >=1 ; i--) {
	up[0] = a[0][i] + b[0][i+1];
	for (int j=1; j<n; j++) {
	  up[j]  = a[j][i];

	  x=b[j][i+1];
	  y=up[j-1];	  
	  up[j] += min (x, y);
	}

	down[n-1] = a[n-1][i] + b[n-1][i+1];
	for (int j=n-2; j>=0; j--) {
	  down[j]  = a[j][i];

	  x=b[j][i+1];
	  y=down[j+1];	  
	  down[j] += min (x,y);
	}

	for (int j=0; j<n; j++)
	  b[j][i] = min (up[j], down[j]);
      }

      //find the min cost for first column
      for (int i=0; i<n; i++)
	b[i][0] = a[i][0]+b[i][1];

      //find min
      m=b[0][0];
      for (int i=1; i<n; i++) {
	if (m > b[i][0])
	  m = b[i][0];
      }
    }
    printf("%lld\n",m);
    return 0;
}

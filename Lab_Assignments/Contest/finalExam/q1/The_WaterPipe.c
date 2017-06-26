#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long long int a[1002][1002];
long long int b[1002][1002];

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

long long int min(long long int x, long long int y)
{
    if(x<y)
        return x;
    return y;
}

int main() {
    int n,i,j,k;
    long long int minimum=999;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%lld",&a[i][j]);
            b[i][j]=a[i][j];
        }
    }
    for(j=2;j<=n;j++)
    {
        k = j-1;
        b[1][j] += b[1][k];
        for(i=2;i<=n;i++)
        {
            b[i][j]+=min(b[i-1][j], b[i][k]);
        }

        b[n][j] = min(b[n][j], a[n][j]+b[n][k]);

        for(i=n-1;i>=1;i--)
        {
            b[i][j] = min(b[i+1][j]+a[i][j], b[i][j]);
            b[i][j] = min(b[i][k]+a[i][j], b[i][j]);
        }
    }
    minimum = b[1][n];
    for(i=2;i<=n;i++)
        if(minimum>b[i][n])
            minimum = b[i][n];
    printf("%lld\n",minimum);
    return 0;
}

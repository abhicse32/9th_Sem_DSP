#include<stdio.h>
#include<limits.h>

int main()
{
    int n;
    scanf("%d",&n);
    int A[(2*n)];
    int i;

    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }

    for(i=n;i<(2*n);i++)
    {
        A[i]=INT_MIN;
    }

    int j;
    int max;
    int nextmax;

    for(j=0,i=n; (i-j)>1 && (i<(2*n)) ; i++, j=j+2)
    {
        if(A[j]>A[j+1]) A[i]=A[j];
        else A[i]=A[j+1];
    }


    if(A[(2*n)-1] > A[(2*n)-2] ) max=A[(2*n)-1];
    else max=A[(2*n)-2];

    nextmax=INT_MIN;


    for(j=0;j<(2*n);j++)
    {
        if((A[j]==max) && (j%2)==0 ) { if ( A[j+1] > nextmax ) nextmax = A[j+1]; }
        if ((A[j]==max) && (j%2)==1 ) { if ( A[j-1] > nextmax ) nextmax = A[j-1]; }

    }

    printf("%d %d",max,nextmax);

}

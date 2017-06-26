#include<stdio.h>
int main()
{
    int n,m,s=0,r=0,i,j,k;
    scanf("%d%d",&n,&m);
    int a[n],b[m];
    for(i=1;i<=n/2;i++)
    {
        k = 0;
        if (n%i == 0)
        {
            for(j=1;j<=i;j++)
            {
                if (i%j == 0)
                k++;
            }
            if (k == 2)
              a[r++]=i;
        }
    }
    for(i=1;i<=m/2;i++)
    {
        k = 0;
        if (m%i == 0)
        {
            for(j=1;j<=i;j++)
            {
                if (i%j == 0)
                k++;
            }
            if (k == 2)
              b[s++]=i;
        }
    }
   for ( i=0;i<=n/2;++i)
   {
    for (j=0;j<=m/2;++j)
    {
        if (a[i] == b[j])
        {
            printf("%d",a[i]);
        }
    }
}
}

#include<stdio.h>
#include<stdlib.h>


 
int main()
{ int n,m,i,j,k,temp;

  scanf("%d",&n);
  int* a=(int*)malloc(n*sizeof(int));
  for(i=0;i<n;i++)
   scanf("%d",&a[i]);
 
   scanf("%d",&m);
  int* b=(int*)malloc(m*sizeof(int));
  for(j=0;j<m;j++)
   scanf("%d",&b[j]);

  for(i=m-1;i>=0;i--)
   { if(b[i]>a[n-1])
       continue;

     for(j=n-2;j>=-1;j--)
      { 
        if(a[j]<b[i] || j==-1)
         { 
           temp=a[n-1];
           for(k=n-1;k>j+1;k--)
             { a[k]=a[k-1];
             }
           a[j+1]=b[i];
           b[i]=temp;

 

           break;
         }
      }
    }

  for(i=0;i<n;i++)
   printf("%d ",a[i]);
  printf("\n");
  for(j=0;j<m;j++)
   printf("%d ",b[j]);
  printf("\n");  
  return 0;
}

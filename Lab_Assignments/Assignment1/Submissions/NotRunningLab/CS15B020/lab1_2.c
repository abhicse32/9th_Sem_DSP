#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

void travm(int *a,int b)
 {
  int i,max;
  max=a[0];
  for(i=0;i<b;i++)
  {
    if(a[i]>max) max=a[i];
   }
  printf("%d\n",max);
 }

void travl(int *a,int b)
 {
  int i,min;
  min=a[0];
  for(i=0;i<b;i++)
  {
    if(a[i]<min) min=a[i];
   }
  printf("%d\n",min);
 }

int maxcmp(int a, int b)
{
 if(a>b) return a;
 else return b;
}

int mincmp(int a, int b)
{
 if(a<b) return a;
 else return b;
}
 
void max(int *a,int b)
{
 int i,j,k;
 int *maxarray;
 if(b%2!=0){j=b/2+1;k=b-3;}
 else {j=b/2;k=b-2;}
 maxarray=(int*)malloc(j*sizeof(int));     
 
for(i=0;i<=k;i=i+2)
  {
   maxarray[i/2]=maxcmp(a[i],a[i+1]);
 if(b%2!=0){maxarray[j-1]=a[b-1];}
  }
  travm(maxarray,j);
}
 
void min(int *a,int b)
{
 int i,j,k;
 int *minarray;
 if(b%2!=0){j=b/2+1;k=b-3;}
 else {j=b/2;k=b-2;}
 minarray=(int*)malloc(j*sizeof(int));     
 
for(i=0;i<=k;i=i+2)
  {
   minarray[i/2]=mincmp(a[i],a[i+1]);
 if(b%2!=0){minarray[j-1]=a[b-1];}
  }
  travl(minarray,j);
}
 


int main()
{
 int i,j;
 scanf("%d",&j);

 int *array;
 array=(int*)malloc(j*sizeof(int));
 for(i=0;i<j;i++)
 {
  scanf("%d",&array[i]);
  }
 max(array,j);
 min(array,j);
}

#include<stdio.h>
int max(int a[], int n)
{ int Max;
 if(n%2==0)
 {
  int b[n/2],i,j=0;
  for(i=0;i<n;i=i+2)
  { 
  
   if(a[i]>a[i+1])
   {
    b[j]=a[i];
   }
   else
   {
    b[j]=a[i+1];
   }
   j++;
   
  }
  Max=max(b, n/2);
  return Max;
 }
 else
 {
  int b[n/2+1],i,j=0;
  if(n==1)
  {
   Max=a[0];
   return Max;
  }
  else
  {
   
   for(i=0;i<n;i=i+2)
   {  
  
    if(a[i]>a[i+1])
    {
     b[j]=a[i];
    }
    else
    {
     b[j]=a[i+1];
    }
    j++;
   
   }
  }
 b[n/2]=a[n-1];  
 Max=max(b, n/2+1);
 return Max;
 }
  
}

int min(int a[], int n)
{ int Min;
 if(n%2==0)
 {
  int b[n/2],i,j=0;
  for(i=0;i<n;i=i+2)
  { 
  
   if(a[i]<a[i+1])
   {
    b[j]=a[i];
   }
   else
   {
    b[j]=a[i+1];
   }
   j++;
   
  }
  Min=min(b, n/2);
  return Min;
 }
 else
 {
  int b[n/2+1],i,j=0;
  if(n==1)
  {
   Min=a[0];
   return Min;
  }
  else
  {
   
   for(i=0;i<n;i=i+2)
   {  
  
    if(a[i]<a[i+1])
    {
     b[j]=a[i];
    }
    else
    {
     b[j]=a[i+1];
    }
    j++;
   
   }
  }
 b[n/2]=a[n-1];  
 Min=min(b, n/2+1);
 return Min;
 }
  
}
int main()
{
 int n,Max,Min;
 scanf("%d",&n);
 int a[n],k;
 for(k=0;k<n;k++)
 {
  scanf("%d",&a[k]);
 }
 if(n%2==0)
 {
  int b[n/2],c[n/2],i,j=0;
  for(i=0;i<n;i=i+2)
  { 
  
   if(a[i]>a[i+1])
   {
    b[j]=a[i];
    c[j]=a[i+1];
   }
   else
   {
    c[j]=a[i];
    b[j]=a[i+1];
   }
   j++;
   
  }
  Max= max(b, n/2);
  Min=min(c, n/2);
 }
 else
 {
  int b[n/2+1],c[n/2+1],i,j=0;
  for(i=0;i<n;i=i+2)
  { 
  
   if(a[i]>a[i+1])
   {
    b[j]=a[i];
    c[j]=a[i+1];
   }
   else
   {
    c[j]=a[i];
    b[j]=a[i+1];
   }
   j++;
   
  }
  b[n/2]= a[n-1];
  c[n/2]=a[n-1];
  Max= max(b, n/2+1);
  Min=min(c, n/2+1);
 }
 printf("%d  %d/n", Max,Min);
 return 0;
}


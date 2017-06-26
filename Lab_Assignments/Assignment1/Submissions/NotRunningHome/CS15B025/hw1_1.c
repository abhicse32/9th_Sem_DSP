#include<stdio.h>
/*
  To find maximum and next maximum element of an array
*/
int maximum(int a[],int l)             //Finding maximum element in an array
{
  int j;
  if(l==1)
    return a[0];
  if((l%2)!=0)
  {
    int b[(l/2)+1];
    for(j=0;j<(l-1);j+=2)
    {
      if(a[j]>a[j+1])
        b[j/2]=a[j];
      else
        b[j/2]=a[j+1];
    }
    b[l/2]=a[l-1];
    return(maximum(b,(l/2+1)));
  }
  if((l%2)==0)
  {
    int b[l/2];
    for(j=0;j<(l-1);j+=2)
    {
      if(a[j]>a[j+1])
        b[j/2]=a[j];
      else
        b[j/2]=a[j+1];
    }
    return(maximum(b,l/2));
  }
  return 0;
}
int minimum(int a[],int l)             //Finding minimum element in an array
{
  int j;
  if(l==1)
    return a[0];
  if((l%2)!=0)
  {
    int b[(l/2)+1];
    for(j=0;j<(l-1);j+=2)
    {
      if(a[j]<a[j+1])
        b[j/2]=a[j];
      else
        b[j/2]=a[j+1];
    }
    b[l/2]=a[l-1];
    return(minimum(b,(l/2+1)));
  }
  if((l%2)==0)
  {
    int b[l/2];
    for(j=0;j<(l-1);j+=2)
    {
      if(a[j]<a[j+1])
        b[j/2]=a[j];
      else
        b[j/2]=a[j+1];
    }
    return(minimum(b,l/2));
  }
  return 0;
}
int main()
{
  int n;
  scanf("%d",&n);                      //Taking input
  int arr[n];
  int i;
  for(i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  int max = maximum(arr,n);
  int nmax;
  int min = minimum(arr,n);
  for(i=0;i<n;i++)                     //Finding index of maximum element
    if(arr[i]==max)
     break;
  printf("%d ",max);                   //Printing output
  arr[i] = min-1;                      //Replacing maximum element with min-1
  nmax=maximum(arr,n);                 //Since next maximum is the maximum now
  printf("%d",nmax);
  return 0;
}

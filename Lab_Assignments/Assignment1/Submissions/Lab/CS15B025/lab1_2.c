#include<stdio.h>
int main()
{
  int n;
  int i;
  int max;
  int min;
  scanf("%d",&n);                      //Taking in number of elements
  int arr[n];
  for(i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);              //Taking in array elements
  }
  if(arr[0]>arr[1])                   //Cosiderin the bigger element to be max and smaller to be min
  {
    min = arr[1];
    max = arr[0];
  }
  else
  {
    min = arr[0];
    max = arr[1];
  }
  if((n%2)==0)
  {
    for(i=2;i<n;i+=2)
    {
      if(arr[i]>=arr[i+1])             //Checking other elements
      {
        if(arr[i]>max)
          max = arr[i];
        if(arr[i+1]<min)
          min = arr[i+1];
      }
      else
      {
        if(arr[i+1]>max)
          max = arr[i+1];
        if(arr[i]<min)
          min = arr[i];
      }
    }
  }
  else
  {
    for(i=2;i<(n-1);i+=2)
    {
      if(arr[i]>=arr[i+1])             //Checking other elements
      {
        if(arr[i]>max)
          max = arr[i];
        if(arr[i+1]<min)
          min = arr[i+1];
      }
      else
      {
        if(arr[i+1]>max)
          max = arr[i+1];
        if(arr[i]<min)
          min = arr[i];
      }
    }
    if(arr[n-1]>max)
      max = arr[n-1];
    if(arr[n-1]<min)
      min = arr[n-1];
  }
  printf("%d %d",min,max);
}

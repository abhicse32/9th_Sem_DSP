#include<stdio.h>
#include<math.h>
int main()
{
int n;
int i;
int min;
int max;
int temp;
int c;
scanf("%d",&n);
int arr[n];
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
max=arr[0];
min=arr[1];
if(arr[1]>arr[0])
{
max=arr[1];
min=arr[0];
}
else
{
max=arr[0];
min=arr[1];
}
if (n%2==0)
{
for(i=2;i<n;i=i+2)
{
if(arr[i]>arr[i+1])
{
if(arr[i]>max)
{
max=arr[i];
}
if(arr[i+1]<min)
{
min=arr[i+1];
}
}
else
{
if(arr[i]<min)
{
min=arr[i];
}
if(arr[i+1]>max)
{
max=arr[i+1];
}
}
}
}
else
{
for(i=2;i<n-1;i=i+2)
{
if(arr[i]>arr[i+1])
{
if(arr[i]>max)
{
max=arr[i];
}
if(arr[i+1]<min)
{
min=arr[i+1];
}
}
else
{
if(arr[i]<min)
{
min=arr[i];
}
if(arr[i+1]>max)
{
max=arr[i+1];
}
}
}
}
if(arr[n-1]>max)
{
max=arr[n-1];
}
else
{
if(arr[n-1]<min)
{
min=arr[n-1];
}
}
printf("\nmax is %d and min is %d",max,min);
return 0;
}



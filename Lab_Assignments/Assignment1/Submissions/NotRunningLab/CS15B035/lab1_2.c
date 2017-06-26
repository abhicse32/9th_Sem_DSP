#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
 int n;
 if(n==0) return 0;
 scanf("%d",&n);
 int a[n];
 int i=0;
 for(i=0;i<n;i++) scanf("%d",&a[i]);
 int max=a[0],min=a[0];
 for(i=0;i<n-1;i+=2) {
     
     if(a[i]>=a[i+1]) {
      if(a[i]>=max) max=a[i];
      if(a[i+1]<=min) min=a[i+1];
     }
     else {
       if(a[i+1]>=max) max=a[i+1];
       if(a[i]<=min) min=a[i];
     }
  }
    if(n%2==1) {
        if(a[n-1]>=max) max=a[n-1];
        else if(a[n-1]<=min) min=a[n-1];
    } 
    
  printf("%d %d\n",min,max);
  return 0;

}

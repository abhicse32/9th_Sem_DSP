#include <stdio.h>
#include <limits.h>
int main(){

    int n,i;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
      scanf("%d",&arr[i]);
    }
    int max = INT_MIN,min = INT_MAX;
    if(n==0){
      max = 0;
      min = 0;
    }
    for(i=0;i<n-1;i=i+2){
      if(arr[i]>arr[i+1]){
        if(arr[i]>max)
          max = arr[i];
       	if(arr[i+1]<min)
       	  min =arr[i+1];
      }else{
        if(arr[i+1]>max)
          max = arr[i+1];
       	if(arr[i]<min)
       	  min =arr[i];
      }
    }
    if(n%2==1){
      if(arr[n-1]>max){
        max = arr[n-1];
      }
      if(arr[n-1]<min){
        min = arr[n-1];
      }
    }
    printf("%d %d\n",min,max);
    return 0;
}

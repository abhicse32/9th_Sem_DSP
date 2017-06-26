#include <stdio.h>
#include <limits.h>
#define size 100005
int main(){
	int n,i;
	int arr[size];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int max1=INT_MIN,max2=INT_MIN;
	for(i=0;i<n;i++){
		if(arr[i]>max1){
			max2=max1;
			max1=arr[i];
		}else if(arr[i]>max2)
			max2=arr[i];
	}
	printf("%d %d\n",max1,max2);
}

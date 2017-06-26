#include <stdio.h>
#include <limits.h>
int min(int a,int b){return a<b?a:b;}
int max(int a,int b){return a>b?a:b;}

int main(){
	int n,i,j;
	int arr[105];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int min_ = INT_MAX,max_= INT_MIN;
	int temp_min, temp_max;

	i=0; j=n-1;
	while(i<j){
		if(arr[i]< arr[j]){
			temp_min=arr[i];
			temp_max=arr[j];
		}else{
			temp_min=arr[j];
			temp_max=arr[i];
		}
		if(min_ > temp_min)
			min_= temp_min;
		if(max_ < temp_max)
			max_= temp_max;
		i++; j--;                   // max 3n/2+1 comparisons
	}
	if(i==j){
		if(arr[i] > max_)
			max_=arr[i];
		else if(arr[i] < min_)
			min_= arr[i];
	}
	printf("%d %d\n",min_,max_);
	return 0;
}
#include<stdio.h>
void main(){
	int a[100],n,i,min,max;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	min=a[0];
	max=a[0];
	for(i=0;i<n;i++){
		if(a[i]>min){
			if(a[i]>max)
				max=a[i];
		}
		else
			min=a[i];
	}
	printf("%d %d\n",min,max);
}

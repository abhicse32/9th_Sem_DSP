#include <stdio.h>
int main(){
	int max1,max2;
	int n;
	scanf("%d",&n);
	int a[n];
	int i,j;
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	max1=a[0];
    max2=a[1];
    for(i=0;i<n;i++){
    	if(a[i]>=max1) {
    		max1=a[i];
    		j=i;	
    }
}
    for(i=0;i<n;i++){
    	if(a[i]>=max2&&(a[i]<=max1&&i!=j)){
    		max2=a[i];
    	}
    }
    printf("%d %d\n",max1,max2);
    return 0;
}
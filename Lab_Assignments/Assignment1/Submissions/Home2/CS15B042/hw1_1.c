#include <stdio.h>
#include<limits.h>

int main(){
	int n,i,secmax;
	scanf("%d",&n);
	int a[(2*n) -1];
	
	for(i = (2*n) - 2;i >= n - 1;i--){
		scanf("%d",&a[i]);
	}
	

	for(i = (2*n) - 2;i > 1;i -= 2){
		if(a[i - 1] > a[i]) a[i/2 - 1] = a[i - 1];
		else a[i/2 - 1] = a[i];
	}
		 
	printf("%d",a[0]);
	if(a[1] == a[0]) {
		secmax = a[2];
		i = 2;
	}
	else{
		secmax = a[1];
		i = 3;
	}		 
	while(i <= n - 1){
		if(a[2*i] == a[0]){
			if(a[(2*i)-1] > secmax) secmax = a[(2*i)-1];
			i = (2*i) + 1;
		}
		else{
			if(a[2*i] > secmax)	secmax = a[2*i];
			i = 2*i;
		}
	}
	printf(" %d\n",secmax);		
	return 0;
}

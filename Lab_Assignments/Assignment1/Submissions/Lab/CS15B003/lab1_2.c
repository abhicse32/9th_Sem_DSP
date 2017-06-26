/*Finding the maximum and minimum of the given array of numbers - CS15B003 - 08/08/16 */
#include<stdio.h>

int maxm(int arr[], int n);
int minm(int arr[], int n);

void main(){
	int n,i;
	int arr[n];
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&arr[i]);
	
	printf("%d %d\n",minm(arr,n),maxm(arr,n));
}

int maxm(int arr[], int n){				//Finds maximum of the given numbers
	int a[n/2],b[n-n/2];
	int i;
	if(n==1) return arr[0];
	for(i=0;i<n/2;i++) a[i]=arr[i];
	for(i=0;i<(n-n/2);i++) b[i]=arr[n/2 + i];
	if((maxm(a, n/2))<(maxm(b,(n-n/2))))
					return maxm(b,(n-n/2));							
	else return maxm(a, n/2);
		  	
}

int minm(int arr[], int n){				//Finds minimum of the given numbers
	int a[n/2],b[n-n/2];
	int i;
	if(n==1) return arr[0];
	for(i=0;i<n/2;i++) a[i]=arr[i];
	for(i=0;i<(n-n/2);i++) b[i]=arr[n/2 + i];
	if((minm(a, n/2))<(minm(b,(n-n/2))))
					return minm(a, n/2);							
	else return minm(b,(n-n/2));
		  	
}

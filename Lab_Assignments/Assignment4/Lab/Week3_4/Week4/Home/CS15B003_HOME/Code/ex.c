#include<stdio.h>
#include<stdlib.h>

int main(){

	int *(*a);
	
	printf("%d\n",sizeof(long int));
	
	int n,i,j;
	
	scanf("%d",&n);
	
	printf("%d %d %d\n",a,a+1,a+2);
	
	a = (int**)malloc(n*sizeof(int*));
	
	for(i = 0; i < n; i++) *(a+i) = (int*)malloc(n*sizeof(int));
	
		printf("%d %d %d\n",a,a+1,a+2);
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++)
		scanf("%d",*(a+i)+j);
//		a++;
	}
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++)
		printf("%d\n",(*(a+i)+j));
//		a++;
	}
	
	for(i = 0; i < n; i++) printf("%d\n",(a+i));
	
//	for(i = 0; i < n; i++){
//		for(j = 0; j < n; j++)
//		printf("%d %d %d\n",*(*(a+j)),*(a+j),a+j);
//		a++;
//	}
}

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
long long iterativeFib(int n){
	long long temp,fib1=1, fib2=1;
	int i;
	for(i=3;i<=n;i++){
		temp=fib2;
		fib2+=fib1;
		fib1=temp;
	}
	return fib2;
}

long long recursiveFib(int n){
	if(n==1 || n==2)
		return 1;
	return recursiveFib(n-1)+recursiveFib(n-2);
}

int main(int argc, char **argv){
	int n,i,t;
	FILE* fp;
	printf("%ld\n",CLOCKS_PER_SEC);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		clock_t start= clock();
		long long iter_val= iterativeFib(n);
		clock_t end= clock();
		printf("%.10lf\n",((double)(end -  start))/CLOCKS_PER_SEC);
		start=clock();
		long long rec_val= recursiveFib(n);
		end=clock();
		printf("%.10lf\n",((double)(end-start))/CLOCKS_PER_SEC);
	}
	return 0;
}
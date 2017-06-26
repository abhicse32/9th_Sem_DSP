#include<stdio.h>
#include<sys/time.h>
#include<time.h>

static int fibr[100];
int* iterative_fib(int n){
	static int i,fib[100];
	for(i=1;i<=n;i++){
		if(i==1 || i==2)
			fib[i-1]=1;
		else
			fib[i-1]=fib[i-2]+fib[i-3];
	}
	return fib;
}

int recursive_fib(int n){
	if (n==1 || n==2)
		fibr[n-1]=1;
	else
		fibr[n-1]=recursive_fib(n-1)+recursive_fib(n-2);
	return fibr[n-1];
}



void main(){
	int n,i,*fib1,*fib2;
	struct timeval start,stop;
	FILE *fp;
	fp=fopen("output.csv", "w");
	for(n=1;n<=25;n++){
		gettimeofday (&start, NULL);
			fib1=iterative_fib(n);
		gettimeofday (&stop, NULL);
		double iter=(double)(stop.tv_usec - start.tv_usec)/1000000+(stop.tv_sec - start.tv_sec);
	
		gettimeofday (&start, NULL);
			recursive_fib(n);
		gettimeofday (&stop, NULL);
		double recur=(double)(stop.tv_usec - start.tv_usec)/1000000+(stop.tv_sec - start.tv_sec);
		fprintf(fp, "%lf,%lf\n",iter,recur);
	}
}



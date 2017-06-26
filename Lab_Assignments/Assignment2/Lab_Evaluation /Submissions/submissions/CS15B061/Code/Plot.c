#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned long long int ull;
void fib_recurdr(ull num, ull ar[]);
ull fib_recur(ull);
void fib_iter(ull, ull*);

ull fib_recur(ull num){
	if(num == 1)
		return 0;
	if(num == 2)
		return 1;
	return (fib_recur(num-1)+fib_recur(num-2));
}

void fib_recurdr(ull num, ull ar[]){
	ull i;
	for(i=0;i<num;i++){
		ar[i]=fib_recur(i+1);
	}


}


void fib_iter(ull num, ull ar[]){
	ull i,pfib=0,nfib=1,fib;
	ar[0]=0;
	ar[1]=1;
	for(i=2;i<num;i++){
		fib=pfib+nfib;
		ar[i] = fib;
		pfib=nfib;
		nfib=fib;	
	}

}

int main(void){
	int i=1;
	FILE * fptr=fopen ("output.csv","w");
	for(;i<=20;i++){
	ull n=i;
	
	struct timeval t1, t2;
	
	ull *ar1 = (ull *)malloc(n*sizeof(ull));
	ull *ar2 = (ull *)malloc(n*sizeof(ull));
	
	gettimeofday(&t1,NULL);
	fib_iter( n, ar1);
	gettimeofday(&t2,NULL);
	double timetaken1 = (double)(t2.tv_usec-t1.tv_usec)+(double)(t2.tv_sec-t1.tv_sec)*1000000.0;

	gettimeofday(&t1,NULL);
	fib_recurdr(n, ar2);
	gettimeofday(&t2,NULL);
	double timetaken2 = (double)(t2.tv_usec-t1.tv_usec)+(double)(t2.tv_sec-t1.tv_sec)*1000000.0;
	fprintf(fptr,"%lf,%lf\n",timetaken1,timetaken2);
	printf("%d\n",i);

		
	}	
	return 0;
}

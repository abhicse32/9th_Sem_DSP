
/*-----------------------------------------------------------------------------
 *  Program: To print first n Fibbionacci numbers using recursive and iteration functions
 *  Date: 18/8/16
 *  Author: Harshavardhan.P.K.
 *  Roll No: CS15B061
 *-----------------------------------------------------------------------------*/
#include <stdio.h>

#include <stdlib.h>
#include <time.h>

typedef unsigned long long int ull;
void fib_recurdr(ull num, ull ar[]);
ull fib_recur(ull);
void fib_iter(ull, ull*);

/*-----------------------------------------------------------------------------
 *  Function: fib_recur - To implement Fibionacci sequence by recursion
 *  Input: num - the fibionacci sequence term.
 *  Output: the 'num'th fibionacci number.
 *-----------------------------------------------------------------------------*/
ull fib_recur(ull num){
	if(num == 1)
		return 0;
	if(num == 2)
		return 1;
	return (fib_recur(num-1)+fib_recur(num-2));
}


/*-----------------------------------------------------------------------------
 *  Function: fib_recurd - driver for fib_recur function
 *  Input :
 *  	num - number of elements in array ar.
 *  	ar - array to store num consecutive fibionacci numbers.
 *  Output:
 *  	return void after input of num fibionacci numbers in array.	
 *-----------------------------------------------------------------------------*/
void fib_recurdr(ull num, ull ar[]){
	ull i;
	for(i=0;i<num;i++){
		ar[i]=fib_recur(i+1);
	}


}


/*-----------------------------------------------------------------------------
 *  Function: fib_iter - To implement Fibbionacci sequence using iteration.
 *  Inputs:
 *  	num- number of elements in array ar.
 *  	ar - array to store num consecutive fibbionacci numbers.
 *  	
 *  Output:
 *  	return void after input of num fibionacci numbers in array.	
 *-----------------------------------------------------------------------------*/
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


/*-----------------------------------------------------------------------------
 *  Function - main
 *  Inputs - n: number of fibionacci numbers.
 *  Other impotant variables:
 *  	ar1,ar2: stores fibionacci sequence as produced by fib_iter and fib_recur respectively.
 *  	t1,t2 : used to store runtime of fib_iter,fib_recur respectively.
 *-----------------------------------------------------------------------------*/
int main(void){
	ull n;
	scanf("%lld",&n);
	struct timeval t1, t2;
	
	ull *ar1 = (ull *)malloc(n*sizeof(ull));
	ull *ar2 = (ull *)malloc(n*sizeof(ull));
	ull i;
	gettimeofday(&t1,NULL);
	fib_iter( n, ar1);
	gettimeofday(&t2,NULL);
	double timetaken1 = (double)(t2.tv_usec-t1.tv_usec)+(double)(t2.tv_sec-t1.tv_sec)*1000000.0;

	gettimeofday(&t1,NULL);
	fib_recurdr(n, ar2);
	gettimeofday(&t2,NULL);
	double timetaken2 = (double)(t2.tv_usec-t1.tv_usec)+(double)(t2.tv_sec-t1.tv_sec)*1000000.0;

		
	for(i=0;i<n;i++)
		printf("%lld ",ar1[i]);
	printf("\n");
	for(i=0;i<n;i++)
		printf("%lld ",ar2[i]);

	printf("\n");	
	return 0;
}

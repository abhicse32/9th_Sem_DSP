/*

Author Name: Gudur Phani Karan Reddy (EE13B077)
Time: Thu Aug  18 23:07:25 IST 2016

Description:
This program takes an integer 'n' as input and outputs 'n' fibonacci numbers, computed via recursion and iteration. 
It also generates a csv file which holds the time taken by iteration and recursion respectively.

*/

#include <stdio.h>
#include <sys/time.h>


int fibo_iter(int n)
{
/*
	Returns the nth fibonacci number using iteration
*/
	int fibo[n], i;
	fibo[0]=1;
	fibo[1]=1;
	for(i=2; i<n; i++)
		fibo[i] = fibo[i-1] + fibo[i-2];
	
	return fibo[n-1];
}


int fibo_recur(int n)
{
/*
	Returns the nth fibonacci number using recursion
*/
	if(n==1 || n==2)
		return 1;
	else
		return fibo_recur(n-1) + fibo_recur(n-2);
}



int main()
{
	
	int n, i, x;

	scanf("%d", &n);
	
	for(i=1; i<=n; i++)
		printf("%d ", fibo_iter(i));

	printf("\n");

	for(i=1; i<=n; i++)
		printf("%d ", fibo_recur(i));

	printf("\n");


// time taken for each function till n=*INSERT VALUE*

n=40;

double times[n][2];


FILE *fp;

fp = fopen("output.csv", "w");


//clock_t start, stop;
double iter_time, recur_time;
struct timeval start, stop;

for(i=1; i<=n; i++)
{

//	start = clock();
	gettimeofday(&start, NULL);
		x = fibo_iter(i);
	gettimeofday(&stop, NULL);
//	stop = clock();

	iter_time = ((double)(stop.tv_usec - start.tv_usec)) / 1000000 + ((double)(stop.tv_sec - start.tv_sec));

//	start = clock();
	gettimeofday(&start, NULL);
		x = fibo_recur(i);
	gettimeofday(&stop, NULL);
//	stop = clock();

	recur_time = ((double)(stop.tv_usec - start.tv_usec)) / 1000000 + ((double)(stop.tv_sec - start.tv_sec));

	times[i-1][0] = iter_time;
	times[i-1][1] = recur_time;

	fprintf(fp, "%lf,%lf\n", iter_time, recur_time);

}

	fclose(fp);



	return 0;
}

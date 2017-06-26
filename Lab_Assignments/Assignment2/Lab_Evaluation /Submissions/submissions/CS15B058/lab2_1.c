//Program to print Fibonacci numbers using recursion and iteration and plot graphs of how much time is taken for implementation, Author: B Arjun CS15B058, Date:18/08/16
#include<stdio.h>
#include<time.h>
#include<sys/time.h>
/*Funtion for recursive implementation of fibonacci*/
int fibrec(int n)
{
	if(n==1||n==2)
		return 1;
	return fibrec(n-1)+fibrec(n-2);
}

/*For iterative implementation of fibonacci*/
int fibite(int n)
{	
	if(n==1)
		return 1;
	else if(n==2)
		return 1;
	else
	{
		int FibOfN1=1,FibOfN2=1,FibOfN=1;	
		int i;
		for(i=3;i<=n;i++) //We use 3 variables, FibOfN to store fib(n), FibOfN1 to store fib(n-1), FibOfN2 to store fib(n-2)
		{
			FibOfN2=FibOfN1;
			FibOfN1=FibOfN;
			FibOfN=FibOfN1+FibOfN2;	
		}
		return FibOfN;
	}
}

int main(void)
{
	struct timeval t1,t2;
	int f,i;
	/*int n;
	scanf("%d",&n);
	int i,f;
	for(i=1;i<=n;i++)
		{
			f=fibite(i);
			printf("%d ",f);//To print fibonacci numbers from iterative code
		}
	printf("\n");
	for(i=1;i<=n;i++)
		{
			f=fibrec(i);
			printf("%d ",f);//To print fibonacci numbers from recursive code
		}*/

	FILE *file;
	file=fopen("output.csv","w");
	double timetaken,timetaken1;
	for(i=1;i<=20;i++)
		{
			gettimeofday(&t1,NULL);
			f=fibite(i);
			gettimeofday(&t2,NULL);
			timetaken=(double)(t2.tv_usec-t1.tv_usec+(t2.tv_sec-t1.tv_sec)*1000000);//To get time in microseconds for iterative code
			fprintf(file,"%lf,",timetaken);
			gettimeofday(&t1,NULL);
			f=fibrec(i);
			gettimeofday(&t2,NULL);
			timetaken1=(double)(t2.tv_usec-t1.tv_usec+(t2.tv_sec-t1.tv_sec)*1000000);//To get time in microseconds for recursive code
			fprintf(file,"%lf\n",timetaken1);
		}
	fclose(file);
	
}

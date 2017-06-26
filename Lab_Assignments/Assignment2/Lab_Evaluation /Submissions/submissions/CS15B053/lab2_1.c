#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>


int iterativefib(int n)
{
	int a=1, b=1;
	
	int i;
	for(i=2; i<n; i++)
	{
		b=a+b;
		a=b-a;			
	}
	return b;
}



int recursivefib(int n)
{
	if(n<=2)
		return 1;
	else
		return recursivefib(n-1) +  recursivefib(n-2);	
}



void main()
{
	int n;
	int i, term;
	scanf("%d", &n);
	
	for(i=1; i<=n; i++)
	{
		term = iterativefib(i);	
		printf("%d ", term);
	}
		
	printf("\n");
	
	for(i=1; i<=n; i++)
	{
		term = recursivefib(i);	
		printf("%d ", term);
	}		
	
	FILE *output;
	output = fopen("output.csv", "w");	
	struct timeval t1, t2;
	double diff;
	int temp;
	
	for(i=1; i<=20; i++)
	{
		gettimeofday(&t1, NULL);
		temp = iterativefib(i);
		gettimeofday(&t2, NULL);
			
		diff=(double)(t2.tv_usec-t1.tv_usec + (t2.tv_sec-t1.tv_sec)*1000000);
		fprintf(output, "%lf", diff);			
		
		fprintf(output, ",");
	
		gettimeofday(&t1, NULL);
		recursivefib(i);
		gettimeofday(&t2, NULL);
			
		diff=(double)(t2.tv_usec-t1.tv_usec + (t2.tv_sec-t1.tv_sec)*1000000);		
		fprintf(output, "%lf\n", diff);		
	}
	
	fclose(output);		
}
	

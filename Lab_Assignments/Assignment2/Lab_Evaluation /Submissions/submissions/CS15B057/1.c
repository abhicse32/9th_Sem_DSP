/* Program to implement fibanocci sequence both recursively and iteratively and compare the time taken and plot a graph for first 20 values
Author: G.Kavitha
Roll No. CS15B057
Date: 18 August 2016 */
#include<stdio.h>
#include<sys/time.h>
const long long int N=1e5;

/*Function to recursively compute the fibanocci numbers
Takes in as arguments the number n and the array ans that holds the fibanocci numbers*/
void fib_rec(long long int n, long long int ans[N]){
	if(n==1) {ans[1]=1; return;}//For the case when n is 1, F1=1
	if(n==2) {ans[1]=1; ans[2]=1; return;}//For the case when n=2, F1=F2=1
	fib_rec(n-1,ans);//Calls the fib_rec function for n-1
	fib_rec(n-2,ans);//Calls the fib_rec function for n-2
	ans[n]=ans[n-1]+ans[n-2];//The ans[n] is the sum of ans[n-1] and ans[n-2]
}

/*Function to iteratively compute the fibanocci numbers
Takes in as arguments the number n and the array ans that holds the fibanocci numbers*/
void fib_ite(long long int n, long long int ans[N]){
	long long int i;
	long long int fib1,fib2;
	fib1=1; fib2=1;	
	if(n==1) {ans[n]=1; return;}//For the case when n is 1, F1=1
	if(n==2) {ans[1]=1; ans[2]=1; return;}//For the case when n is 2, F1=F2=1
	ans[1]=fib1; ans[2]=fib2;
	for(i=3;i<=n;i++){
		fib2=fib1+fib2;//fib2 now holds the new fibanocci number ans[i] generated
		fib1=fib2-fib1;//fib 1 holds the previous value of fib2
		ans[i]=fib2;
	}
}

//Main function
int main(){

	//File to create an output csv file holding the time taken for first 20 numbers
	FILE *fp;
	fp=fopen("output.csv","w");

	long long int n;//n holds the number upto which we need to compute the fibanocci numbers
	long long int ans_rec[N],ans_ite[N];//Holds the fibanocci numbers computed using the recursive and iterative methods	
	
	for(n=1;n<=20;n++){	//loops n from 1 to 20
//		scanf("%lld",&n);
	
		struct timeval tvalBefore, tvalAfter;

		//Time is calculated in microseconds

		gettimeofday(&tvalBefore, NULL);
		fib_ite(n,ans_ite);//Function call to the function that generates the fibanocci numbers iteratively and stores in array ans_ite
		gettimeofday (&tvalAfter, NULL);
	
		fprintf(fp,"%ld,", ((tvalAfter.tv_sec - tvalBefore.tv_sec)*1000000L +tvalAfter.tv_usec) - tvalBefore.tv_usec);//Write into the csv file the time taken for iteratively generating fibanocci numbers 
	
		gettimeofday(&tvalBefore, NULL);
		fib_rec(n,ans_rec);//Function call to the function that generates the fibanocci numbers recursively and stores in array ans_rec
		gettimeofday (&tvalAfter, NULL);

		fprintf(fp,"%ld\n",((tvalAfter.tv_sec - tvalBefore.tv_sec)*1000000L +tvalAfter.tv_usec) - tvalBefore.tv_usec);//Write into the csv file the time taken for recursively generating fibanocci numbers 
	
//		long long int i=0;	
		
		//Display the answer obtained using iterative method and recursive methods	
//		for(i=1;i<=n;i++){printf("%lld ", ans_ite[i]);} printf("\n");
//		for(i=1;i<=n;i++){printf("%lld ", ans_rec[i]);} printf("\n");

	}
	fclose(fp);
	return 0;
}

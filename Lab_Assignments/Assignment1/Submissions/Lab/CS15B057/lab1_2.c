/* Program to find maximum and minimum in an array
Author: G.Kavitha
Roll No. CS15B057
Date: 8 August 2016 */

# include<stdio.h>
# define SIZE 105
# define SIZ 51
int main(){
	int n;//n-Size of array
	int i;
	int a[SIZE];//Array
	int maxiset[SIZ];//Array holding elements which can be maximum
	int miniset[SIZ];//Array holding elements which can be minimum
	int nummax=0;//Holds size of maxiset array
	int nummin=0;//Holds size of miniset array
	int maxi,mini;//holds maximum and minimum	

	/*Read in size of array*/
	scanf("%d",&n);
	
	/*Read in array elements*/
	for(i=0;i<n;i++){
		scanf("%d",a+i);
	}

	/* Divide array elements into miniset and maxiset arrays*/
	for(i=0;i<(n-1);i=i+2){
		if(a[i]>a[i+1]){
			maxiset[nummax]=a[i];
			miniset[nummin]=a[i+1];
		}
		else{
			maxiset[nummax]=a[i+1];
			miniset[nummin]=a[i];
		}
		nummax++;
		nummin++;	
	}

	if(n%2==1){
		maxiset[nummax]=a[n-1];
		miniset[nummin]=a[n-1];
		nummax++;
		nummin++;
	}

	/* Finding maximum from maxiset array*/
	maxi=maxiset[0];
	for(i=0;i<nummax;i++){
		if(maxi<maxiset[i]) maxi=maxiset[i];
	}

	/* Finding minimum from miniset array*/
	mini=miniset[0];
	for(i=0;i<nummin;i++){
		if(mini>miniset[i]) mini=miniset[i];
	}

	/*Display the minimum and maximum*/
	printf("%d %d\n",mini,maxi);
	return 0;
} 

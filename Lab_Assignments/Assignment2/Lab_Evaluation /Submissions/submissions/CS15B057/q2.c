/* Program to implement permutations of a set of integers
Author: G.Kavitha
Roll No. CS15B057
Date: 18 August 2016 */
#include<stdio.h>
const int N=1e5;

/*Function to do a bubble sort on the array
Takes in arguments as the array (by reference) and the number of elements in the array*/
void bsort(int a[N],int n){
	int i,j;	
	for(i=0;i<n;i++){
		for(j=0;j<n-1-i;j++){
			if(a[j]>a[j+1]){//Swaps two adjacent elements if they are not in order
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}

/* Function to generate the factorial of n
Takes in as argument the integer n whose factorial is to be computed and returns the computed answer*/
long long fact(int n){
	if(n<=1) return 1;
	return(n*fact(n-1));//Recusively computing the factorial as f(n)=n*f(n-1)
}

/*Function to generate the lexicographically next permutation
Takes in as arguments the current permutation array and the number of elements in the array*/
void nextperm(int a[N], int n){
	int i;	
	int save1=-1,save2=-1;
	/*save1 holds the index where the first decrease in value is noted as we traverse from the end
	save2 holds the index whose value we have to swap with the value at save1*/
 
	for(i=n-1;i>0;i--){
		if(a[i]>a[i-1]) {save1=i-1; break;}//finds the value of index save1 where the decrease is observed(i.e. a[save1]<a[save1+1])
	}
	if(save1!=-1){
		for(i=n-1;i>save1;i--){
			if(a[save1]<a[i]) {save2=i;break;}//finds the value of save2. save2 is the index that has the smallest value greater than the value at save1
		}
	}
	if(save2!=-1){
		//Swaps the values at indices save1 and save2
		int temp;
		temp=a[save1];
		a[save1]=a[save2];
		a[save2]=temp;
	}

	//We need to reverse the elements in array a from indices save1+1 to (n-1)
	int t[N];//a temporary array to do the reversal
	
	int j=0;
	for(i=n-1;i>save1;i--){
		t[j]=a[i];//Storing the values of the array a from save1+1 to the end of array in opposite order
		j++;
	}
	j=0;
	for(i=save1+1;i<n;i++){
		a[i]=t[j];//Setting the values of array a[] from save1+1 to (n-1) using the array t[] 
		j++;
	}
} 

//Main function
int main(){
	int n;//Hold the number of integers in the array
	
	scanf("%d",&n);//Reads in n

	int i;
	int a[N];//Array holding the integers

	//Read in the array values
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	long long tot;//tot holds the total number of permutations which is n!
	tot=fact(n);//Setting tot as n!

	bsort(a,n);//Sorting the given array using bubble sort to get the lexicographically smallest permutation

	while(tot--){	
		for(i=0;i<n;i++) printf("%d",a[i]);//Display the current permutation
		printf(" ");
		nextperm(a,n);//Generate the lexicographically next permutation 
	}
	printf("\n");//Puts a new line
	return 0;	
}

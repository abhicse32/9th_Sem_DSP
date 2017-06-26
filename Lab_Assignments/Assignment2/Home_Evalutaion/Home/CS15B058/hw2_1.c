//Program to calculate determinant of an NxN matrix, Author: B Arjun, CS15B058, Date:19/08/16
#include<stdio.h>
#include<stdlib.h>
/*Function to find the minor matrix of an element in the first row*/
void MinorOfMatrixElement(int *A,int *B,int n,int colindex)
{
	int i,j;
	for(i=1;i<n;i++)  //We need the element from 2nd row to Nth row of matrix
	{
		for(j=0;j<colindex;j++)
		{
			*(B+(i-1)*(n-1)+j)=*(A+i*n+j); //Copy elements except those in column of the element passed
		}
		for(j=colindex;j<n-1;j++)
		{
			*(B+(i-1)*(n-1)+j)=*(A+i*n+j+1);
		}
	}

} 

/*Recursive function to find determinant*/
long det(int *a,int n)
{
	if(n==1)                  //Base case
		return *a;
	int j,coeff;
	long cofactordetsum;
	int *temp=(int*)malloc((n-1)*(n-1)*sizeof(int));    //temp, 2d matrix of size n-1, to store minor of the element
	for(j=0,cofactordetsum=0,coeff=1;j<n;j++)
	{
		MinorOfMatrixElement(a,temp,n,j);
		int p,q;
		cofactordetsum+=(long)coeff*(*(a+j))*det(temp,n-1);  //Sum of the cofactors will give determinant
		coeff=-coeff;    									//coeff is initially 1, then it should alternate sign
	}
	free(temp);					//To free the temp pointer
	return cofactordetsum;


}

int main(void)
{
	int N;
	scanf("%d",&N);
	int *A=(int*)malloc(N*N*sizeof(int));   //to store the N*N matrix
	int i,j;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			scanf("%d",A+i*N+j);
	long detA=det(A,N);	
	free(A);
	printf("%ld",detA);
	return 0;

}
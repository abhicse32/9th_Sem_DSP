/* Author: G.Kavitha
Roll Number: CS15B057
Date: 19-08-16 */

//Program to calculate determinant using recursion

#include <stdio.h>

/* Function to calculate the determinant of an matrix
Takes in as arguments the matrix a and the order of the matrix m
Return the determinant of that matrix*/
long long int det(int a[12][12],int m){
	if(m==1) //Only one element
		return a[0][0];
	if(m==2) //Base case when there is matrix of order 2
		 return (a[0][0]*a[1][1]-a[0][1]*a[1][0]);
	
	int r,i,j;
	int x=0,y=0,mul=1;

	long long int ans=0;
	
	//Recursively computing determinant of given matrix by computing determinant of smaller matrices of order m-1 and using the fact that determinant is the sum over the product a[0][r]*C[0][r] for r from 0 to (m-1) where C[0][r] is the cofactor of a[0][r] 
	//Looping over r from 0 to m-1
	for(r=0;r<m;r++){
		x=0; y=0;
		int t[12][12];//temporary array t 

		//loop to construct temporary array t to hold the matrix of order m-1 whose determinant we need
		for(i=1;i<m;i++){
			for(j=0;j<m;j++){
				if(j==r) continue;
				t[x][y]=a[i][j];
				y++;
			}
			x++;
			y=0;
		}

		//Using determinant of t to compute the determinant of a
		ans=ans+mul*det(t,m-1)*a[0][r];
		mul*=-1;
	}

	return ans;
}
int main(){
	int N; //Integer to hold the order of the matrix
	scanf("%d",&N);//Reading in N
	
	int i,j;
	int a[12][12];//Array to hold the elements of the matrix
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			scanf("%d",&a[i][j]);//Reading in the matrix elements
		}
	}

	long long int ans=det(a,N);//Computing answer
	
	printf("%lld\n",ans);//Display the answer

	return 0;
}

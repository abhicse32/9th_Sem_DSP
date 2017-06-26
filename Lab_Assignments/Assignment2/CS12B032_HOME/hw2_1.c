#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
int** getMatrix(int n){
	int** matrix= (int**)malloc(sizeof(int*)*n);
	int i;
	for(i=0;i<n;i++)
		matrix[i]=(int*)malloc(sizeof(int)*n);
	return matrix;
}

void copy(int **matrix, int **temp, int i, int n){
	int j,k;
	for(j=1;j<n;j++){
		for(k=0;k<n;k++)
			if(k<i)
				temp[j-1][k]=matrix[j][k];
			else if(k>i)
				temp[j-1][k-1]=matrix[j][k];
	}
}

long long determinant(int** matrix, int n){
	int i,j,k;
	if(n==1)
		return (long long)(**matrix);
	else if(n==2)
		return (long long)(matrix[0][0]*matrix[1][1]-matrix[1][0]*matrix[0][1]);
	int **temp= getMatrix(n-1);
	bool flag=true;
	long long det=0;
	for(i=0;i<n;i++){
		copy(matrix,temp,i,n);
		long long det_n_1=matrix[0][i]*determinant(temp,n-1);
		det+=(flag ? det_n_1 : -det_n_1);
		flag^=true;
	}
	return det;
}

int main(){
	int n,i,j,t;
	// scanf("%d",&t);
	// while(t--){
		scanf("%d",&n);
		int** matrix= getMatrix(n);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&matrix[i][j]);
		long long det=determinant(matrix,n);
		printf("%lld\n",det);
	// }
}
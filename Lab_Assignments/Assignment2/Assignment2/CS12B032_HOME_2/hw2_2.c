#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
int counter=0;

int** getMatrix(int n){
	int** matrix= (int**)malloc(sizeof(int*)*n);
	int i;
	for(i=0;i<n;i++){
		matrix[i]=(int*)malloc(sizeof(int)*n);
		memset(matrix[i],-1,sizeof(int)*n);
	}
	return matrix;
}

int** getCopy(int** matrix, int n){
	int** temp= getMatrix(n);
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			temp[i][j]= matrix[i][j];
	return temp;
}

void printMatrix(int** matrix, int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%d ",matrix[i][j]);
		printf("\n");
	}
}

bool isPlaced(int** matrix, int n){
	int i,j;
	bool flag;
	for(i=0;i<n;i++){
		flag=false;
		for(j=0;j<n;j++){
			if(matrix[i][j]==1){
				flag=true;
				break;
			}
		}
		if(!flag)
			return false;
	}
	return true;
}

void fillAttackingPositions(int** matrix, int row, int col, int n){
	int i,j,k;
	for(i=col+1;i<n;i++)
		matrix[row][i]=0;
	// for(i=col-1;i>=0;i--)
	// 	matrix[row][i]=0;
	for(i=row+1;i<n;i++)
		matrix[i][col]=0;
	for(i=row+1,j=col-1;i<n && j>=0; i++,j--)
		matrix[i][j]=0;
	for(i=row+1,j=col+1;i<n && j<n;i++,j++)
		matrix[i][j]=0;
}
void printCells(int**matrix, int n){
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(matrix[i][j]){
				printf("%d ",j);
				break;
			}
}
void free2(int**matrix, int n){
	int i;
	for(i=0;i<n;i++)
		free(matrix[i]);
	free(matrix);
}

int calcPositions(int** matrix,int row, int col,int n){
	if(row==n && isPlaced(matrix,n)){
		counter++;
		printCells(matrix,n);
		free2(matrix,n);
		printf("\n");
		return;
	}
	int i,j,k,l;
	for(i=col;i<n;i++){
		if(matrix[row][i] == -1){
			int **tempMatrix= getCopy(matrix, n);
			tempMatrix[row][i]=1;
			fillAttackingPositions(tempMatrix,row,i,n);
			calcPositions(tempMatrix,row+1,0,n);
			matrix[row][i]=0;
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	int** matrix= getMatrix(n);
	//printMatrix(matrix,n);																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																										
	counter=0;
	int pos= calcPositions(matrix,0,0,n);
	printf("%d\n",counter);
}
//Program to solve N-Queens problem, Author: B Arjun, CS15B058, Date:20/08/16
#include<stdio.h>
#include<stdlib.h>

/*Function to initialize chessboard positions to 0*/
void initialize0(int *a,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			*(a+i*n+j)=0;
	}
}

/*Function to initialize the index array to -1*/
void initializeindexarr(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		a[i]=-1;
}

/*Function to check if a queen can be placed in (QRow,QCol)*/
int queencheck(int *a,int n,int QRow,int QCol)
{
	int i,j;
	for(i=0;i<QRow;i++)
	{
		if(*(a+i*n+QCol)==1)
			return -1;
	}
	for(i=QRow,j=QCol;(i>=0)&&(j>=0);i--,j--)
	{
		if(*(a+i*n+j)==1)
			return -1;
	}
	for(i=QRow,j=QCol;(i>=0)&&(j<n);i--,j++)
	{
		if(*(a+i*n+j)==1)
			return -1;
	}
	return 1;
}

/*Recursive function to find the possible N-Queens configurations
placing queens row by row*/
int queenfinder(int *a,int n,int QRow,int qindexarray[])
{
	int QCol,i,j;
	static int countcase=0;		//Static variable to count no. of configurations
	if(QRow==n)					//Base case: QRow=n when all queens can be placed.
		return 1;
	for(QCol=0;QCol<n;QCol++)
	{
		if(queencheck(a,n,QRow,QCol)==1)
		{
			*(a+QRow*n+QCol)=1;
			qindexarray[QRow]=QCol;
			//Recursively calls the function to place queen in next row'
			int c=queenfinder(a,n,QRow+1,qindexarray);		
			countcase+=c;
			if(c==1)				//If a configuration is possible, c=1
			{
				for(i=0;i<n;i++)
				printf("%d ",qindexarray[i]);
				printf("\n");
			}
			*(a+QRow*n+QCol)=0;		//To make the queen position back to zero in case no config exists
		}
	}
	if(QRow==0&&QCol==n)			//QRow=0 and QCol=n once all possibile configs are checked
	return countcase;
	return 0;						//return 0 is executed when the config fails for a particular case.
}

int main(void)
{
	int N;
	scanf("%d",&N);
	int *A=(int*)malloc(N*N*sizeof(int));
	int *IndexArray=(int*)malloc(N*sizeof(int));	//Array to store column indices of the N Queens
	int countcase=0;
	initialize0(A,N);
	initializeindexarr(IndexArray,N);
	countcase=queenfinder(A,N,0,IndexArray);
	printf("%d",countcase);
	return 0;
}
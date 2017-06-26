/* CS15B059 KOMMURU ALKEHYA REDDY 21AUG2016
TO PLACE N QUEENS ON AN N x N GRID SUCH THAT NO 2 QUEENS CAN ATTACK EACH OTHER*/
#include<stdio.h>
#include<stdlib.h>
int count=0;//global variable which coutns the total possibilities
void queen(int row,int n);//defining the function prototypes
void print(int n);//prints all the possible configurations
int a[10][10];//defines the global array as the maximum size of the grid is 10
void main()
{
	int n;
	scanf("%d",&n);//input the size of the grid
	int i,j,row=0,col=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{			
			a[i][j]=0;//assigning all the values to 0 initially	
		}	
	}


	queen(0,n);// calling the function to place the queen
	printf("\n%d",count);

}

// to place queens using recursion by checking if there are no queens in the same row,column or diagonally
void queen(int row,int n)
{
	int i=0;
	if(row<n){
	for(i=0; i<n; i++)
		{
		if(check(row,i,n))	
		{
			a[row][i]=1;//if check returns 1 saying that there are no queens place a queen in that position
			queen(row+1,n);//calls the function again to place a queen in the next row
			a[row][i]=0;//after it comes out of the function we must place a 0 to remove the queen
		}
		}
	}
	else
	{
		print(n);//if the row index is n then we can print the grid
	}
}
	
//checks if a queen can be placed at that particular position
int check(int row, int col, int n)
{
	int k,checkcol;
	for(k=0; k<row; k++)
	{
		checkcol=getindex(k,n);//checks for location of queen in every row using a for loop if a queen has already been placed
		if(a[k][col] == 1)
			return 0;
		else if((row-k == col - checkcol) || (row - k == checkcol - col))//checks if it is not diagonal
			return 0;//if returns 0 if the queen has been placed , else returns 1	
		
	}
	return 1;
}	

//function checks if a queen has been already placed
int getindex(int row,int n)
{
	
	int i;
	for(i=0; i<n; i++)
	{
		if(a[row][i]==1)
			return(i);//returns the column at which the queen has been placed for a particular row	
	}
}


//to print the matrix
void print(int n)
{
	if(count!=0)
	printf("\n");	
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]==1)
			printf("%d ",j);
		}
		
	}
	count ++;
}

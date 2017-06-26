// Home Assignment 1 Question 2
// solving the "n queens on an n*n chessboard problem"
// Author : Milind Srivastava
// Date : 16 Aug 2016

#include <stdio.h>
#include <stdlib.h>

int* Stack = NULL; // Stack for holding column values of queens
int* col = NULL; // Array for denoting if particuar column is free (=1) or occupied (=0)
int* diagNE = NULL; // Array for denoting if particular North-East diagonal is free (=1) or occupied (=0)
int* diagNW = NULL; // Array for denoting if particular North-West diagonal is free (=1) or occupied (=0)

int topIndex = -1; // top index of the Stack
int flag = 0;
int count = 0; // total numbe of possiblities

void initializeStack(int); // initialize memory dynamically and assign initial values 
void push(int); // push to Stack
int pop(); // pop from Stack
void printStack(int); // print Stack contents

void explore(int i, int n); // recursive function to find all possible solutions

int main()
{
	int n;
	scanf ("%d",&n); // input "n"

	initializeStack(n);

	explore(-2,n); // initial function call so that queen possible positions start from 0 onward

	printf("%d",count);

	free (Stack);
	free (col);
	free (diagNE);
	free (diagNW);

	return 0;
}

void explore(int i, int n)
{
	int j;
	for (j = 0; j < n; j++)
	{
		if (j < i-1 && col[j] == 1 && diagNE[j+topIndex+1] == 1 && diagNW[n-j+topIndex] == 1) // if position is free and atleast 2 columns away from previous queen
		{
			push(j); // push "j" on the stack

			// corresponding columns and diagonals are now occupied

			col[j] = 0;
			diagNE [j+topIndex] = 0;
			diagNW [n-j+topIndex-1] = 0;
			
			explore(j,n); // recursive calls

			// corresponding columns and diagonals are now free
			
			col[j] = 1;
			diagNE [j+topIndex+1] = 1;
			diagNW [n-j+topIndex] = 1;
			
			if (topIndex == n-1) // if we have found n-1 compatible positions of queens
			{
				printStack(n);
				continue;
			}
		}
		else if (j > i+1 && col[j] == 1 && diagNE[j+topIndex+1] == 1 && diagNW[n-j+topIndex] == 1) // if position is free and atleast 2 columns away from previous queen
		{
			push(j); // push "j" on the stack

			// corresponding columns and diagonals are now occupied

			col[j] = 0;
			diagNE [j+topIndex] = 0;
			diagNW [n-j+topIndex-1] = 0;
			
			explore(j,n); // recursive calls
			
			// corresponding columns and diagonals are now free

			col[j] = 1;
			diagNE [j+topIndex+1] = 1;
			diagNW [n-j+topIndex] = 1;
			
			if (topIndex == n-1) // if we have found n-1 compatible positions of queens
			{
				printStack(n);
				continue;
			}
		}
		else if (topIndex == n-1) // if we have found n-1 compatible positions of queens
		{
			printStack(n);
			return;
		}
	}
	if (j == n && topIndex != n-1) // if we couldn't find any position satisfying the above conditions
	{
		flag = 1; // couldn't find any possiblities, so discard this

		printStack(n);
	}
}

void initializeStack(int n)
{
	// dynamic allocation of memory

	Stack = (int*) malloc (n*sizeof(int));
	col = (int*) malloc (n*sizeof(int));
	diagNE = (int*) malloc ((2*n - 1)*sizeof(int));
	diagNW = (int*) malloc ((2*n - 1)*sizeof(int));

	int i;

	// initialization of column and diagonal arrays

	for(i = 0; i < n; i++)
	{
		col[i] = 1;
	}

	for (i = 0; i < 2*n-1; i++)
	{
		diagNE[i] = 1;
		diagNW[i] = 1;
	}
}

void push (int x)
{
	topIndex++;
	Stack[topIndex] = x;
}

int pop()
{
	int temp = Stack[topIndex];
	topIndex--;
	return temp;
}

void printStack(int n)
{
	int i;
	if (flag != 1) // complete solution found
	{
		for (i=0;i<=topIndex;i++)
		{
			printf("%d ", Stack[i]);
		}
		printf("\n");
		count++;
	}

	int temp = pop();

	flag = 0; // reset flag
}
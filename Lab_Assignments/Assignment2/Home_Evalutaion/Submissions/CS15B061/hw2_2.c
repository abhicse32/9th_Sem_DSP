/*
 * =====================================================================================
 *
 *       Filename:  2.c
 *
 *    Description:  To place N queens in N*N board and find total no of possible soln
 *
 *        Created:  08/20/16 19:48:32
 *
 *         Author: Harshavardhan.P.K.
 *   	   Rollno:  CS15B061
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int ui;
void solvenextcol(short **,ui, ui,ui*);
short issafe(short **,ui,ui,ui);
void printsol(short**,ui,ui*);


/*-----------------------------------------------------------------------------
 *  Function: issafe - checks if the current config. of board satisfies that all
 *  queens are not attacking any other
 *  Input: board - 2D array storing positions of board.
 *  	   order - the dimension of board.
 *  	   row - row of the most recently added queen
 *  	   col - col of the most recently added queen
 *  Output: 1 if safe, 0 if not safe	   
 *-----------------------------------------------------------------------------*/
short issafe(short ** board, ui order, ui row, ui col){
	int i;
	//Checks if the same row has another queen
	for(i=0;i<col;i++){
		if(board[i][row])
			return 0;
	}
	//checks if the diagonals have queen
	for(i=1;;i++){
		if(((int)row-i)>=0){
			if((int)col-i>=0){
				if(board[col-i][row-i])
					return 0;
			}
			else
				break;
		}
		else
			break;

	}

	for(i=1;;i++){
		if(row+i<order){
			if((int)col-i>=0){
				if(board[col-i][row+i])
					return 0;
			}
			else
				break;
		}
		else
			break;
	}
	return 1;
}

/*-----------------------------------------------------------------------------
 *  Function : solvenextcol - solves next column of board after the board is safe 
 *  for config. in previous columns
 *  Input : board - 2D array stores position of queens.
 *  	    order - Dimension of board
 *  	    colno - the column to be solved
 *  	    nosol - pointer to nosol in main for incrementing if a soln is found
 *  Output : It returns nothing. After checking safety of a config. by placing
 *  in one of the rows of nocol, it calls itself to solve the next row.	    
 *-----------------------------------------------------------------------------*/
void solvenextcol(short ** board, ui order, ui colno,ui* nosol){
	int i;
	//i stores the row in which the queen is next placed and tested.
	for(i=0;i<order;i++){
		board[colno][i]=1;
		//Removes the previous queenand place it at next row
		if(i>0)
			board[colno][i-1]=0;
		if(colno==0){
			solvenextcol(board,order,1,nosol);
			continue;
		}
		//Check if board is safe on placing new queen then proceed to next column
		if(colno>0 && colno<order-1){
			if(issafe(board,order,i,colno)){
				solvenextcol(board,order,colno+1,nosol);continue;}
			else continue;
		}
		//if it is the last column and the board is safe, we have a solution.
		if(colno==order-1)
			if(issafe(board,order,i,colno))
				printsol(board,order,nosol);


	}
	//Remove queens after checking all possibilities in the column
	board[colno][i-1] = 0;
}


/*-----------------------------------------------------------------------------
 *  Function : printsol - prints the postion of the queens in board after a solution
 *  is found and also increments the solution counter.
 *  Input : board- 2D array to store postions of queens.
 *  	    order - Dimensions of board
 *  	    nosol - pointer to nosol in main()
 *  Output: It retuns nothing. It prints position of queen in each column and
 *  increments the nosol.
 *-----------------------------------------------------------------------------*/

void printsol(short ** board, ui order,ui*nosol){
	int i,j;
	for(i=0;i<order;i++){
		for(j=0;j<order;j++)
			if(board[i][j])
				printf("%d ",j);
	}
	printf("\n");
	(*nosol)++;
}


/*-----------------------------------------------------------------------------
 *  Function : main 
 *  Inputs: order - the dimension N of chessboard
 *
 *  Other importent variables:
 *  	int **board : Pointer to array of pointers each of which are array of
 *  	order elements. It stores the queens presence (1) or absence(0) on board.
 *  	nosol : Stores the no of solutions found.
 *
 *  Output : It calls the first solvenextcol() for column 0. and also prints the 
 *  no of solutions stored in variable nosol.	
 *-----------------------------------------------------------------------------*/
int main(void){
	ui order;
	scanf("%u",&order);
	short **board=(short**)malloc(order*sizeof(short*));
	ui i;
	for(i=0;i<order;i++)
		board[i]=(short*)malloc(order*sizeof(short));
	ui j;
	for(i=0;i<order;i++)
		for(j=0;j<order;j++)
			board[i][j]=0;
	ui nosol=0;
	solvenextcol(board,order,0,&nosol);
	printf("%u\n",nosol);
	for(i=0;i<order;i++)
		free(board[i]);
	free(board);
}

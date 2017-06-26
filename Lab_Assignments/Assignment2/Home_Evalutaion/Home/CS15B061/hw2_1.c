/*
 * =====================================================================================
 *
 *       Filename:  1.c
 *
 *    Description:  To calculate Determinant of square Matrix
 *
 *        Created:  08/15/16 18:58:28
 *
 *         Author: Harshavardhan.P.K.
 *   	   Roll no: CS15B061	
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
typedef long long int lli;

lli det(int **, int);
int ** cofactor(int **,int **,int, int, int);

/*-----------------------------------------------------------------------------
 *  Function - cofactor - Forms cofactor matrix if ar[row][col] in ans[][]
 *  Input : ar - stores the original matrix
 *  	    ans - to store the cofactor matrix
 *  	    or - order of ar
 *  	    row - row the element for cofactor
 *  	    col - column of element for cofactor
 *  Output - the pointer to ans matrix after filling it.
 *-----------------------------------------------------------------------------*/

int ** cofactor(int **ar,int **ans, int or, int row, int col){
	/*
	 *  tr : row index of ans to fil
	 *  tc: column index of ans to fill
	 *  r: row index for ar
	 *  c: column index for ar
	 */
	int tr=0, tc=0, r=0, c=0;
	for(;r<or;r++){
		if(r==row)
			continue;
		
		for(c=0;c<or;c++){
			
			if(c!=col){
				ans[tr][tc]=ar[r][c];
				tc++;
			}
			
		}//Going to next row
		tc=0;
		tr++;

	}
	return ans;

}

/*-----------------------------------------------------------------------------
 *  Function: det - returns determinant of matrix in ar
 *  Input : ar - stores the matrix whose determinant is to be calculated
 *  	    order - order of ar
 *  Other important variables:
 *  	cof - stores the cofactor matrix
 *  	sig - sign during multiplication
 *  Output: the value of determinant of matrix	
 *-----------------------------------------------------------------------------*/
lli det(int **ar, int order){
	if(order==1)
		return ar[0][0];
	lli ans=0;
	int **cof=(int **)malloc((order-1)*sizeof(int *));

	int i;
	for (i=0;i<order-1;i++)
		cof[i]=(int *)malloc((order-1)*sizeof(int));

	short sig=1;

	for (i=0;i<order;i++){
		//compute cofactor matrix of ar[0][i]
		cofactor(ar,cof,order,0,i);
		//adding the next term in determinant
		ans+= sig*ar[0][i]*det(cof,order-1);
		sig=-sig;
	}
	
	//Freeing allocated memory
	for(i=0;i<order-1;i++)
		free(cof[i]);
	free(cof);
	return ans;
}


/*-----------------------------------------------------------------------------
 *  Function - main
 *  Inputs: order - the order of matrix
 *  	    ar - the array to store all order*order elements
 *  Outputs: call det(ar,order) and prints the result,i.e., the value of
 *  determinant.	    
 *-----------------------------------------------------------------------------*/
int main (void){
	int order, **ar;
	scanf("%d",&order);
	ar = (int **)malloc(order * sizeof(int *));
	 int i,j;

	for(i=0;i<order;i++)
	       ar[i] = (int *)malloc(order * sizeof(int));
	for(i=0;i<order;i++)
		for(j=0;j<order;j++)
			scanf("%d",&(ar[i][j]));

	printf("%lld\n",det(ar,order));	
	//Freeing allocated Memory
	free(ar);
}

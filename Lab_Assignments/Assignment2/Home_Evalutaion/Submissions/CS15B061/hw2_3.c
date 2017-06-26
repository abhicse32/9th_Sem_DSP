/*
 * =====================================================================================
 *
 *       Filename:  3.c
 *
 *    Description:  Solve Tower of Hanoi
 *
 *        Created:  08/17/16 20:37:03
 *
 *         Author:  Harshavardhan.P.K.
 *   	  Roll No: CS15B061
 *
 * =====================================================================================
 */

#include <stdio.h>

void TOH(int *ar,int num,int from, int via, int to, int *m);



/*-----------------------------------------------------------------------------
 *  Function TOH - to solve tower of Hanoi
 *  Input: ar - stores no. of disks in each peg
 *  	   num - no of disks to move
 *  	   from - the peg from which to move
 *  	   via - the auxillary peg used for movement
 *  	   to - the peg to move the disks
 *  	   m - pointer to moves variable in main() to store no. of moves
 *  Output - the function retuns void and calls itself accodingly for smaller tasks
 *  and prints the move in case of single disk	   
 *-----------------------------------------------------------------------------*/
void TOH(int *ar,int num,int from, int via, int to, int *m){
	//Base case
	if (num==1){
		ar[from]--; ar[to]++;
		printf("%c -> %c %d %d %d\n",(char)((int)'A'+from), (char)((int)'A'+to),ar[0],ar[1],ar[2]);
		//Increment no of moves
		(*m)++;
		return;
	}
	//num - 1 pegs taken to via
	TOH(ar,num-1,from,to,via,m);
	//1 peg taken to 'to'
	TOH(ar,1,from,via,to,m);
	//num - 1 taken to 'to'
	TOH(ar,num-1,via,from,to,m);
}


/*-----------------------------------------------------------------------------
 *  Function - main
 *  Input: n- the number of disks
 *  Output - It calls TOH function and prints total no. of moves
 *-----------------------------------------------------------------------------*/
int main(void){
	int n,moves=0;
	scanf("%d",&n);
	int ar[3] = {n,0,0};
	TOH(ar,n,0,1,2,&moves);
	printf("%d\n",moves);
	return 0;
}

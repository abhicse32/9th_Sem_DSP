/* Author: G.Kavitha
Roll Number: CS15B057
Date: 19-08-16 */

//N-Queens problem

#include <stdio.h>

/* Function to solve the problem and print possible cases
Takes in as arguments the current status of the board(array queen), 
the column number to which we need to add the next queen,
the total number of queens,
and the variable cnt(passed by reference) to hold the number of possible answers*/
void solve(int queen[15][15], int c, int n,int* cnt){
	int i,j,p;
	if(c==n){//No more queens left to add
		//Print the solution
		for(p=0;p<n;p++){
			for(j=0;j<n;j++){
				if(queen[p][j]==1) {printf("%d ",j); break;}
			}
		}
		printf("\n");
		(*cnt)++;//Increment count of number of solutions
		return;
	}
	
	for(i=0;i<n;i++){
		int ok=1;//Variable ok

		//ok is 1 if queen can be placed in position (i,c), 0 otherwise
		//Checking if there is another queen in the row i
		for(p=0;p<n;p++){
			if(p==c) continue;
			if(queen[i][p]==1) ok=0;//Cannot place queen in (i,c)
		}

		//Checking the diagonal elements
		for(p=0;p<n;p++){
			if(p+c-i>=0&&p+c-i<n){
				if(queen[p][p+c-i]==1) ok=0;//Cannot place queen in (i,c)
			}
		}

		//Checking the other diagonal
		for(p=0;p<n;p++){
			if(i+c-p>=0&&i+c-p<n){
				if(queen[p][i+c-p]==1) ok=0;//Cannot place queen in (i,c)
			}
		}
		if(!ok) continue;//Continue to check the next row to see if queen can be placed there

		queen[i][c]=1;//Place queen here at (i,c)
		solve(queen,c+1,n,cnt);	//solve recursively for the problem of placing the next queen at column c+1
		queen[i][c]=0;//Remove this queen to backtrack and find other possible solutions
	}
}

//Main function
int main(){
	int N;//Number of queens
	int queen[15][15];//Array holding current configuration (1 in positions where queen is present, 0 in  other positions)
	scanf("%d",&N);//Read in N
	
	int i,j;
	int cnt=0;//Holds number of possible configurations
	
	for(i=0;i<N;i++) for(j=0;j<N;j++) queen[i][j]=0;//No queen anywhere initially
	
	solve(queen, 0, N, &cnt);//Call function to solve

	printf("%d\n", cnt);//Display count of number of solutions

	return 0;
}

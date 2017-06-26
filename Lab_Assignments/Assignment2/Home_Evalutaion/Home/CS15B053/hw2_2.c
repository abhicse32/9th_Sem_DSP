#include<stdio.h>
#include<math.h>

int board[12];
int n;
int numsols;


int check(int row, int col)
{
    int i;
    for(i=0; i<row; i++)
    {
        if((abs(board[i]-col) == abs(i-row)) || (board[i] == col))
            return 0;
    }
    return 1;
}


void print_solution()
{
    int i, k;
    numsols++;
    
    for (i = 0; i < n; i++)
        printf("%d ", board[i]);
    printf("\n");
}


void putqueens(int row)
{
    int col;
    for(col=0; col<n; col++)
    {
        if(check(row, col))
        {
            board[row] = col;
            
            if(row == n-1)
                print_solution();
            else
                putqueens(row+1);
        }
    }
}


int main()
{    
    scanf("%d", &n);  
    putqueens(0);
    printf("%d", numsols);
}

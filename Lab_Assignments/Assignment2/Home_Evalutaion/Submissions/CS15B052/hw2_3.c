// Home Assignment 1 Question 3
// Printing steps for solving Tower of Hanoi problem for n disks
// Author : Milind Srivastava
// Date : 16 Aug 2016

#include <stdio.h>

int num[3]; // array to denote number of disks in each peg

int moves = 0; // number of moves

void TOH (int, char, char, char); // recursive function to print desired output

int main()
{
	int n;
	scanf ("%d", &n); //inputting "n"

	num[0] = n;
	num[1] = 0;
	num[2] = 0;

	TOH (n,'A','C','B');

	printf("%d",moves);

	return 0;
}

void TOH (int n, char src, char dst, char via)
{
	if (n > 1) // recursive implementation of Towers of Hanoi
	{
		TOH (n-1, src, via, dst);
		TOH (1, src, dst, via);
		TOH (n-1, via, dst, src);
		return;
	}
	else // base case of recursive implementation
	{

		// updating number of pegs in source and destination pegs

		num[src-'A'] -= 1;
		num[dst-'A'] += 1;
		
		printf ("%c -> %c %d %d %d\n", src, dst, num[0], num[1], num[2]); // printing source peg, destination peg and number of disks in each peg
		
		moves++;
		
		return;
	}
}
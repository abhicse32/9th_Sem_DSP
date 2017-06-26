/* CS15B059 KOMMURU ALEKHYA REDDY 21AUG2016
TOWER OF HANOI-PRINTS THE NUMBER OF MOVES AND THE PEGS BETWEEN WHICH THE DISCS MUST BE SHIFTED TO TRANSFER N DISCS FROM A TO C*/
#include<stdio.h>
void towerofhanoi(int n, char x, char y, char z);//defining the function prototype

int count=0;//global variable which counts the number of times the discs have been moved
int a[3];// array which stores the number of discs on each peg
	
void main()
{
	int n;
	printf("Enter the number of discs");
	scanf("%d",&n);// accepts the number of discs as input
	a[0]=n;
	a[1]=0;
	a[2]=0; 
	towerofhanoi(n, 'A', 'B', 'C');//recursively calls the function
	printf("%d\n",count);//prints the number of moves

}

//moving n rings from a to c using b as support
void towerofhanoi(int n, char x, char y, char z)
{

	if(n>0)
	{	
		towerofhanoi(n-1,x,z,y);//move n-1 rings from a to b using c as support
		a[x - 'A'] -= 1;
		a[z - 'A'] += 1;
		printf("%c -> %c %d %d %d\n", x, z, a[0], a[1], a[2]);// transfer one ring from a to c
		count++;//increment the number of moves by 1
		towerofhanoi(n-1, y, x, z);// transfer all the n-1 rings from b to c using a as the support
			
	}

}


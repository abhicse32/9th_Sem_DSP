//Program to solve the Tower Of Hanoi problem, Author: B Arjun, CS15B058, Date:19/08/16
#include<stdio.h>
#include<stdlib.h>

/*Function to move n disks from peg 'src' to 'dest' through 'via' */
//Function returns the no. of steps to move the disks
int ToHsolve(char src,char via,char dest,int n,int DisksOnPegs[3])
{
	if(n==1)
	{
		DisksOnPegs[src-'A']--; //src-'A' gives the position of the peg(A-0,B-1,C-2)
		DisksOnPegs[dest-'A']++; //a disk is shifted from src to dest
		printf("%c->%c %d %d %d\n",src,dest,DisksOnPegs[0],DisksOnPegs[1],DisksOnPegs[2]);
		return 1; 
	}
	int c1,c2,c3;  
	c1=ToHsolve(src,dest,via,n-1,DisksOnPegs);		//c1 is no. of steps to shift n-1 disks from src to the via peg.
	c2=ToHsolve(src,via,dest,1,DisksOnPegs);		//c2 is no. of steps to shift 1 disk from src to dest peg.
	c3=ToHsolve(via,src,dest,n-1,DisksOnPegs);		//c3 is no. of steps to shift n-1 disks from via to dest.
	return c1+c2+c3;

}

int main(void)
{
	int DisksOnPegs[3],N,NoOfSteps=0;
	scanf("%d",&N);
	DisksOnPegs[0]=N;
	DisksOnPegs[1]=0;
	DisksOnPegs[2]=0;
	NoOfSteps=ToHsolve('A','B','C',N,DisksOnPegs);
	printf("%d",NoOfSteps);  //To print the no. of steps involved in solving ToH
	return 0;
}
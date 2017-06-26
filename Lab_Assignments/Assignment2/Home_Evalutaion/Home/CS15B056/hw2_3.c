//TOWER OF HANOI
//This code prints the steps and the discs left in each peg after the step

#include <stdio.h>
void hanoi(int n,char a,char c,char b,int d['D']);
int main ()
{
	int n,d['D'];                       //d array stores the discs in each peg
	scanf("%d",&n);
	d['A']=n;
	 d['B']=0;
	 d['C']=0;
	d[0]=0;
	hanoi(n,'A','C','B',d);
	printf("%d\n",d[0]);                //d[0] is the number of steps
	return 0;
	
}


void hanoi(int n,char a,char c,char b,int d['D'])      //this function is called recursively
{
	 
	 
	if(n-1>0)
	hanoi(n-1,a,b,c,d);                  
	
	
	d[a]--;
	d[c]++;                                    
	printf("%c->%c %d %d %d\n",a,c,d['A'],d['B'],d['C']);         //used for printing steps and number of discs
	d[0]++;
	
	if(n-1>0)
	hanoi(n-1,b,c,a,d);
}
	

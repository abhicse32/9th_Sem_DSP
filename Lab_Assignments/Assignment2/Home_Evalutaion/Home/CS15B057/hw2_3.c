/* Author: G.Kavitha
Roll Number: CS15B057
Date: 19-08-16 */

//Tower of Hanoi

#include <stdio.h>

/* Funtion to solve the problem recursively
Takes in as arguments the src peg,dest peg, via peg, 
number of disks in pegs A,B,C as disks[0],disks[1],disks[2] respectively, 
number of disks to be transferred as num, 
and variable cnt (passed by reference) to count number of steps to be done*/

void toi(char src, char dest, char via, long long disks[3], long long num, long long* cnt){
	if(num==1) {//Only one disk to be transferred. It can be done directly
		disks[src-'A']--;//Update the number of disks in src peg
		disks[dest-'A']++;//Update number of disks in dest peg
		printf("%c -> %c %lld %lld %lld\n",src,dest,disks[0],disks[1],disks[2]);//Print the step to be followed as src -> dest and number of disks in each peg 
		(*cnt)++;//increment the count of steps
		return;
	} 
	//Move num-1 disks from src to via
	toi(src,via,dest,disks,num-1,cnt);

	//Move 1 disk from src to dest	
	toi(src,dest,via,disks,1,cnt);

	//Move num-1 disks from via to dest 
	toi(via,dest,src,disks,num-1,cnt);
}

//Main function
int main(){
	long long int n;//Number of disks in peg A
	scanf("%lld",&n);//Reads in n
	
	long long int cnt=0;//Number of steps
	long long disks[3];//Number of disks in pegs A,B,C
	
	disks[0]=n; disks[1]=disks[2]=0;//Setting values for disks

	toi('A','C','B',disks,n,&cnt);//Solving for moving n disks from A to C via B
	
	printf("%lld\n",cnt);//Display the number of steps
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
int counter;
typedef struct Pegs{
	int a_num;
	int b_num;
	int c_num;
}Pegs;

void assign2(char* str, int *num, Pegs* peg){
	if(!strcmp(str,"A"))
		peg->a_num= *num;
	else if(!strcmp(str,"B"))
		peg->b_num= *num;
	else peg->c_num= *num;
} 

Pegs assign(char* src, char* mid, char* dest, int* s, int *m, int* d){
	Pegs peg;
	assign2(src,s,&peg);
	assign2(mid,m,&peg);
	assign2(dest,d,&peg);
	return peg;
}

void printMove(char* source, char* mid, char* dest,int num, int *s, int *m, int *d){
	if(num<=0)
		return;
	if(num==1){
		(*s)--;
		(*d)++;
		counter++;
		printf("%s -> %s ",source,dest);
		Pegs peg= assign(source, mid, dest, s,m,d);
		printf("%d %d %d\n",peg.a_num, peg.b_num,peg.c_num);
		return;
	}
	printMove(source,dest,mid,num-1,s,d,m);
	(*d)++;
	(*s)--;
	printf("%s -> %s ",source,dest);
	Pegs peg= assign(source,mid,dest,s,m,d);
	printf("%d %d %d\n",peg.a_num, peg.b_num,peg.c_num);
	counter++;
	printMove(mid,source,dest,num-1,m,s,d);
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	char* src="A";
	char* dest="C";
	char* mid="B";
	int m=0,d=0,s=n;
	counter=0;
	printMove(src,mid,dest,n,&s,&m,&d);
	printf("%d\n",counter);
}
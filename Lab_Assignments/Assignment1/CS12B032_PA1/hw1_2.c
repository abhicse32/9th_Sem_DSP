#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* intToHex(int n){
	char* str=(char*)malloc(11);
	str[0]='0';
	str[1]='x';
	int idx=9,temp;
	while(n){
		temp= (n&15);
		switch(temp){
			case 0: str[idx]='0'; break; 
			case 1: str[idx]='1'; break;
			case 2:	str[idx]='2'; break;
			case 3: str[idx]='3'; break;
			case 4: str[idx]='4'; break;
			case 5: str[idx]='5'; break;
			case 6: str[idx]='6'; break;
			case 7: str[idx]='7'; break;
			case 8: str[idx]='8'; break;
			case 9: str[idx]='9'; break;
			case 10: str[idx]='a'; break;
			case 11: str[idx]='b'; break;
			case 12: str[idx]='c'; break;
			case 13: str[idx]='d'; break;
			case 14: str[idx]='e'; break;
			case 15: str[idx]='f'; break;
			default: break;
		}
		n>>=4;
		idx--;
	}
	while(idx>1)
		str[idx--]='0';
	return str;
}

int main(){
	int n,i;
	scanf("%d",&n);
	char* hex= intToHex(n);
	printf("%s\n",hex);
}
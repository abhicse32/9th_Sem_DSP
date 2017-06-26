#include<stdio.h>

int main(){
	
	char hex[10];
	int i = 9,n;
	
	scanf("%li",&n);

hex[0] = '0';
hex[1] = 'X';
	
	for(;i>1;i--){
	
		switch(n%16){
			case 0 : {
				hex[i] = '0';
				break;}
			case 1 : {
				hex[i] = '1';
				break;}			
			case 2 : {
				hex[i] = '2';
				break;}
			case 3 : {
				hex[i] = '3';
				break;}
			case 4 : {
				hex[i] = '4';
				break;}	
			case 5 : {
				hex[i] = '5';
				break;}	
			case 6 : {
				hex[i] = '6';
				break;}
			case 7 : {
				hex[i] = '7';
				break;}
			case 8 : {
				hex[i] = '8';
				break;}
			case 9 : {
				hex[i] = '9';
				break;}
			case 10 : {
				hex[i] = 'A';
				break;}
			case 11 : {
				hex[i] = 'B';
				break;}
			case 12 : {
				hex[i] = 'C';
				break;}
			case 13 : {
				hex[i] = 'D';
				break;}								
			case 14 : {
				hex[i] = 'E';
				break;}	
			case 15 : {
				hex[i] = 'F';
				break;}
		}
		n = n/16;
	}
	
	printf("%s",hex);
}

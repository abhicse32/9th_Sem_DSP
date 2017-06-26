#include <stdio.h>
#include "stack.h"
#include "stack.c"
#include <string.h>


int main(){
	char* read_input(); //reads the input from STDIN
	int check_num(char*s, int size, int idx); //checks if character from idx till next space is encountered is a number
	char* return_char(char *s, int size, int idx); //returns the number at idx to next space
	int precedence(char ch); //returns precedence value of an operation
	int solve(char *s, int size) //reads the postfix string s and returns the solution
	

	char s[1000];
	gets(s);
	
	int solution=solve(s,strlen(s));
	printf("%d",solution);
}






char* read_input() //reads the input from STDIN
{
	char s[1000];
	gets(s);
	return s;
}






int check_num(char *s, int size, int idx){
	int k=idx;
	if(a[k]==-1){
		if(a[k+1]==' ')
			return 0
		else 
			return 1
	}
	switch(a[k]){
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9': return 1;
		default: return 0;

	}
}







char* return_char(char *s, int size, int *idx){
	char s2[10];
	int k=0;
	while((s[idx]!=' ')&&(idx!=size)){
		s2[k++]=s[idx++];
	}
	if(s[idx]==' ')
		idx++;
	return s2;
}




int precedence(char ch){
	switch(ch){
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 2;
	}
}



int convert_to_num(char s[], int size){
	int i;
	int sum=0;
	for(i=0;i<size;i++){
		int sum;
		switch(s[i]){
			case '0': sum=sum*10+0; break;
			case '1': sum=sum*10+1; break;
			case '2': sum=sum*10+2; break;
			case '3': sum=sum*10+3; break;
			case '4': sum=sum*10+4; break;
			case '5': sum=sum*10+5; break;
			case '6': sum=sum*10+6; break;
			case '7': sum=sum*10+7; break;
			case '8': sum=sum*10+8; break;
			case '9': sum=sum*10+9; break;

		}
	}
	return sum;
}



int solve(char s[], int size){
	int i=0;
	int num1,num2;
	char tmp[10];
	stack *nums;
	while(i<size){
		tmp=return_char(s,size,i);    //i updates here
		if(check_num(tmp,strlen(tmp),0)){
			stack_push(nums,convert_to_num(tmp));
		}
		else{
			num1=stack_pop(nums);
			num2=stack_pop(nums);
			switch(tmp[0]){

				case '+': stack_push(nums, num1+num2); break;
				case '-': stack_push(nums, num2-num1); break;
				case '*': stack_push(nums, num1*num2); break;
				case '/': stack_push(nums, num2/num1); break;

			}
		}


	}

	return stack_pop(nums);
}
#include <stdio.h>
#include "stack.h"
//#include "stack.c"
#include <string.h>
//#include <math.h>
//#include "List.c"
#include "List.h"


int main(int* argc, char* argv[]){
	char* read_input(); //reads the input from STDIN
	int check_num(char*s, int size, int idx); //checks if character from idx till next space is encountered is a number
	int return_char(char *s, int size, int idx, char *s2); //returns the number at idx to next space
	int precedence(char ch); //returns precedence value of an operation
	int solve(char *s, int size); //reads the postfix string s and returns the solution
	void tester();
	//tester();
	
	char s[100];
	while(fgets(s,100,stdin)!=NULL){
	
		int solution;
		int len=strlen(s);

		solution=solve(s,len);
		printf("%d\n",solution);
	}
	
}


void tester(){
	printf("%d \n",convert_to_num("10",2));
	printf("%d \n",check_num("-10",3,0));
	printf("%d \n",convert_to_num("-1",2));
	printf("%d \n",check_num("-",1,0));
	//printf("\n%s",return_char("283",3,))
}




char* read_input() //reads the input from STDIN
{
	char s[1000];
	gets(s);
	return s;
}






int check_num(char *a, int size, int idx){
	int k=idx;
	if(a[k]=='-'){
		if(a[k+1]==' '||a[k+1]=='\0')
			return 0;
		else 
			return 1;
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







int return_char(char *s, int size, int idx, char *s2){
	int k=0;
	while((s[idx]!=' ')&&(idx!=size)){
		s2[k++]=s[(idx)++];
	}
	if(s[idx]==' ')
		(idx)++;
	s2[k]='\0';
	return idx;
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
	if(s[0]!='-'){
	int sum=0;
	for(i=0;i<size;i++){
		
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
	else{
	int sum=0;
	for(i=1;i<size;i++){
		
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
	return (-1)*sum;
	}
}



int solve(char s[], int size){
	int i=0;
//	int num1,num2;
	stack *nums;
	nums=stack_new();
	//int *ptr;
	while(i<size){
//		stack_print(nums);
//		printf("\n");
		//*ptr=i;
		char tmp[10];
	//	tmp[0]='1';
	//	tmp[1]='\0';
//		printf("K i%d..\n",i);
		int j=i;
		i=return_char(s,size,i,tmp); 
		   //i updates here
	//	i+=strlen(tmp)+1;

//		printf("R i%d..tmp%s..\n",i,tmp);
		if(check_num(tmp,strlen(tmp),0)){
//			printf("cp1\n");
			int nu=convert_to_num(tmp,i-j-1);
//			printf("%d(%d)()\n",nu,i-j-1);
			stack_push(nums,nu);
		}
		else{
//			printf("cp2\n");
//			stack_print(nums);

			int num1=stack_pop(nums);
			//stack_push(nums,num1);
			//stack_print(nums);
			int num2=stack_pop(nums);

//			printf("\n%d%c%d.. ",num2,tmp[0],num1);
			switch(tmp[0]){

				case '+': stack_push(nums, num1+num2); break;
				case '-': stack_push(nums, num2-num1); break;
				case '*': stack_push(nums, num1*num2); break;
				case '/': stack_push(nums, num2/num1); break;
				case '%': stack_push(nums, num2==0? num2 : num2%num1); break;
				case '&': stack_push(nums, num2&num1); break;
				case '|': stack_push(nums, num2|num1); break;
				case '^': stack_push(nums, num2^num1); break;


			}
		}


	}
//	printf("\n");
//	printf("\n");

//	stack_print(nums);
//	printf("\n");
	int sol=stack_pop(nums);
//	printf("%d\n", sol);
	return sol;
}

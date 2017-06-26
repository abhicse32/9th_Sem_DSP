// postfix evaluation

#include <stdio.h>
#include "stack.h"
#include <string.h>
#include "List.h"



int isnum(char *arr, int size, int idx)   //checks for negative numbers
{
	if(arr[idx] == '-')
	{
		if(arr[idx+1] == ' '|| arr[idx+1] == '\0')
			return 0;
		else 
			return 1;
	}
	
	if(arr[idx] > 47 && arr[idx] < 58)
		return 1;
	else return 0;
}




int jumptonext(char *s, int size, int idx, char *temp)   // gives the next index and stores var in temp
{	
	int k=0;
	while((s[idx] != ' ') && (idx != size)){
		temp[k++] = s[(idx)++];
	}
	if(s[idx]==' ')
		(idx)++;
	temp[k] = '\0';
	return idx;
}


int convert_to_num(char s[], int size)
{
	int i;
	if(s[0]!='-')
	{
		int sum=0;
		for(i=0;i<size;i++)
		{
			int val = s[i] - 48;
			sum=sum*10+ val;
		}
		return sum;
	}
	else
	{
		int sum=0;
		for(i=1;i<size;i++)
		{
			int val = s[i] - 48;
			sum=sum*10+ val;
		}
		return (-1)*sum;
	}
}

int master(char s[], int size)
{
	//printf("gotin");
	int i=0;
	stack *operandstack;
	operandstack=stack_new();
	while(i<size)
	{
		//stack_print(operandstack);
		//printf("\n");

		char tmp[10];
		int j=i;
		//i= jumptonext(s,size,i,tmp); 

		int k=0;
		while((s[i] != ' ') && (i != size))
		{
			tmp[k++] = s[(i)++];
		}

		if(s[i]==' ')
			(i)++;

		tmp[k] = '\0';

		if(isnum(tmp,strlen(tmp),0))
		{
			int nu=convert_to_num(tmp,i-j-1);
			stack_push(operandstack,nu);
		}
		else
		{
			int num1=stack_pop(operandstack);
			int num2=stack_pop(operandstack);

			switch(tmp[0])
			{
				case '+': stack_push(operandstack, num1+num2); break;
				case '-': stack_push(operandstack, num2-num1); break;
				case '*': stack_push(operandstack, num1*num2); break;
				case '/': stack_push(operandstack, num2/num1); break;
				case '%': stack_push(operandstack, num2==0? num2 : num2%num1); break;
				case '&': stack_push(operandstack, num2&num1); break;
				case '|': stack_push(operandstack, num2|num1); break;
				case '^': stack_push(operandstack, num2^num1); break;
			}
		}


	}

	int last = stack_pop(operandstack);
	return last;
}



int main(int argc, char* argv[])
{	
	char* read_input();
	char s[100];
	while(fgets(s, 100, stdin)!=NULL)
	{
		int len = strlen(s);
		printf("%d\n", master(s,len-1));
	}
}







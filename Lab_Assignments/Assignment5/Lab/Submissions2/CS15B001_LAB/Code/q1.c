/*
This program checks if the given bracket sequence is valid
It also uses an array implementation of stack

Ameet S Deshpande
CS15B001
*/

#include<stdio.h>

int main()
{

int test;	//Holds the number of test cases
char a[2000],stack[2000]; 	//Using array for stack implementation
int top=-1;
char pl='(',pr=')',cl='{',cr='}',sl='[',sr=']';		//The variables store the brackets


scanf("%d",&test);	//Input the number of test cases

int i,j;	//Loop variables

for(i=0;i<test;++i)
{
scanf("%s",a);	//Input the string

top=-1;

for(j=0;a[j]!='\0';++j)
{

	if((a[j]==pl)||(a[j]==sl)||(a[j]==cl))		//If left bracket is encountered, add it to the stack
	{
		top=top+1;
		stack[top]=a[j];
	}

	else
	{
		if(top==-1)	//If stack is already empty then break
		{
			break;
		}

else if(((a[j]==pr)&&(stack[top]==pl))||((a[j]==cr)&&(stack[top]==cl))||((a[j]==sr)&&(stack[top]==sl)))
		{
			top=top-1;
		}
		else
		{
			break;
		}

}

}	//Inner for loop ends


if((top==-1)&&(a[j]=='\0'))
{
	printf("1\n");
}

else
{
	printf("0\n");
}


}	//Outer for loop ends


return 0;

}	//Program ends

















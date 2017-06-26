#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
const int size=1000;
#define BUFF_SIZE 1000
typedef struct stacka_a{
	char *arr;
	int top;
}stacka;
stacka* stacka_new()
{  stacka* st = (stacka*)malloc(sizeof(stacka));
   st->top=-1;
   char* arr= (char*)malloc(size*sizeof(char));
   if(arr==NULL)
   return NULL;
   st->arr=arr;
   return st;
}

void stacka_push(stacka* st,char num)
{  
    
   st->top=st->top+1;
   st->arr[st->top]=num;
}

char stacka_pop(stacka* st)
{  st->top=st->top-1;
    return st->arr[st->top+1];
}

bool stacka_is_empty(stacka* st)
{ if(st->top==-1)
   return true;
  return false;
}

int if_symbol(char x)
{  if( x=='+' || x=='-' || x=='*' || x=='/' || x=='%' || x=='|' || x=='&' || x=='^' || x=='(' || x==')')
  return 1;
  return 0;
}

void stacka_print(stacka* st)
{ int i,flag=0;
  for(i=0; i<=(st->top);i++)
  { 
    if(st->arr[i]=='$')
   	{
   		if(flag==1)
        continue;
        flag=1;
        printf(" ");
    }
    else
    { flag=0;
    	if(i==st->top)
    	{printf("%c ",st->arr[i]);
    	continue;}	
    	if(if_symbol(st->arr[i+1]))
  	{
  		printf("%c ",st->arr[i]);
  		continue;
  	}
      printf("%c",st->arr[i]);
    }
  }
  printf("\n");

}



int priorty(char x)
{  if(x==')')
    return 11;
   if(x=='(')
    return 12;
   if(x=='^')
    return 6;
   if(x=='/')
    return 3;
   if(x=='*')
    return 3;
   if(x=='+')
    return 4;
   if(x=='-')
    return 4;
   if(x=='%')
    return 3;
   if(x=='&')
    return 5;
   if(x=='|')
    return 7;
return -1;

}
void in_conv_post(char* a)
{
char buff='$',catch;
int i,j=-1;
stacka* st3=stacka_new();
stacka* st2=stacka_new();
while(buff!='\0')
{   j++;
    buff=a[j];
   if(buff=='\0')
     break;

	if(buff==' ')
      { stacka_push(st3,'$');
        continue;
      }
	if(if_symbol(buff))
	{  
	    if(priorty(buff)==12 || stacka_is_empty(st2))
	    	{   stacka_push(st2,buff);
	    		continue;
	    	}

        catch=stacka_pop(st2);

        if(priorty(buff)==11)
        {	 do
	         {  stacka_push(st3,catch);
	         	if(stacka_is_empty(st2))
	    	    	break;
                catch=stacka_pop(st2);
	         }while(catch!='(');
	    	continue;
        }

		if(priorty(buff)<priorty(catch))
		{
			stacka_push(st2,catch);
			stacka_push(st2,buff);
			continue;
		}
 
	    do
	    {   stacka_push(st3,catch);
	    	if(stacka_is_empty(st2))
	    		{break;

	    		}
            catch=stacka_pop(st2);
            if(catch=='(')
            	{stacka_push(st2,catch);
            	break;}
            if(priorty(buff)<priorty(catch))
            	{stacka_push(st2,catch);
            		break;
                }
	    }while(priorty(buff)>=priorty(catch));
		stacka_push(st2,buff);
	}
	else
	{   if(buff=='\n')
         continue;
		stacka_push(st3,buff);
	}
	//stacka_print(st3);
	//stacka_print(st2);
}
stacka_push(st3,'$');
while(!stacka_is_empty(st2))
{
   stacka_push(st3,stacka_pop(st2));
}

stacka_print(st3);
}
int main(int argc, char* argv[])
{
    char *in;
    in = (char *)malloc(BUFF_SIZE * sizeof(char));
    while(fgets(in,BUFF_SIZE,stdin)!=NULL)
    { in_conv_post(in);
    }
    return 0;
}

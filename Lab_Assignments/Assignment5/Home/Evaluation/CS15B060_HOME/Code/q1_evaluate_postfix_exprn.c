#include<stdio.h>  //program for evaluating the postfix expression
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct Stack_a{          //basic array of stack oprns copied from stack_a.c   
	int *arr;
	int top;
}stack;

stack* stack_new()
{
  stack *s=(stack*)malloc(sizeof(stack));
  s->arr=(int*)malloc(sizeof(int)*1000);
  s->top=-1;
  return s;
  
  }
  
  void stack_push(stack*s, int a)
  {
     
     s->top++; 
      s->arr[s->top]=a;
      
      }
      
      
    int stack_pop(stack*s)
    {
       if(!stack_is_empty(s))
     { return(s->arr[s->top--]); 
      
      } 
       
       return -1;
       
       }
       
       
       int stack_is_empty(stack*s)
       {return(s->top==-1);}
       
      
       
       
       int calc(int a,int b,char c)      //function that calculates values based on operators
       {if(c=='+')
        return a+b;
         else if(c=='-')
          return a-b;
          else if(c=='*')
          return a*b;
          else
          return a/b;
          }
          
          int conv(int *a,int k)     //function for converting string of single digit into numbers
          {int i,sum=0;
            for(i=0;i<k;i++)
            sum+=a[i]*pow(10,i);
            return sum;}
void main()
{int i1,i2,i3,d,j,k,a[100],num,i;
 char c[100];
  int n;
  stack *s=stack_new();
  
  gets(c);                  //string accepted with white space
  n=strlen(c);
  
  for(d=0;d<n;d++)           //if there is a number,convert it to integer and then call conv(),store it in stack
  { k=0;
    if(isdigit(c[d]))
    { for(j=d;j<n &&c[j]!=' ';j++)
        { a[k]=c[j]-48;
           k++;
           }
           if(k!=0)
           {num=conv(a,k);d+=k-1;}
           stack_push(s,num);
      
      }
       else if(c[d]=='+'||c[d]=='-'||c[d]=='*'||c[d]=='/') //if it is operator pop out 2 elem,evaluate value,push into stack
      {  i1=stack_pop(s);
        i2=stack_pop(s);
        i3=calc(i2,i1,c[d]);
        stack_push(s,i3);
        }
        }
        
        i=stack_pop(s);   //finally pop out last elem and print it
        printf("%d",i);
        }
  
 

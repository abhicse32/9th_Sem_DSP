#include<stdio.h>  //program for evaluating the postfix expression
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct Stack1_a{          //basic array of Stack1 oprns copied from Stack1_a.c   
	long *arr;
	int top;
}Stack1;
 long powe(long a,long b)
 { if(b>=0)
   {int sum=1;
    while(b>=1)
    {b--;
     sum*=a;
     }
     return sum;}
     else
     { return 0;}
     
     
     }



Stack1* Stack1_new()
{
  Stack1 *s=(Stack1*)malloc(sizeof(Stack1));
  s->arr=(long*)malloc(sizeof(long)*1000);
  s->top=-1;
  return s;
  
  }
  
  void Stack1_push(Stack1*s, long a)
  {
     
     s->top++; 
      s->arr[s->top]=a;
      
      }
      
      
    long Stack1_pop(Stack1*s)
    {
       if(!Stack1_is_empty(s))
     { return(s->arr[s->top--]); 
      
      } 
       
       return -1;
       
       }
       
       
       int Stack1_is_empty(Stack1*s)
       {return(s->top==-1);}
       
      
       
       
       long calc(long a,long b,long c)      //function that calculates values based on operators
       {if(c=='+')
        return a+b;
         else if(c=='-')
          return a-b;
          else if(c=='*')
          return a*b;
          else if(c=='%')
          return a%b;
          else if(c=='^')
          return powe(a,b);
          else if(c=='/')
          return (a/b);
          else if(c=='|')
          return a||b;
          else if(c=='&')
          return a&&b;
          else
          return a/b;
          }
          
          long conv(long *a,long k)     //function for converting string of single digit into numbers
          {long i;long sum=0;
            for(i=k-1;i>=0;i--)
            sum+=a[i]*powe(10,k-i-1);
            return sum;}
void main()
{ int count=10;
  while(count>=1)
  { count--;
  long a[100];long num,i1,i2,i3;long i,j,k,d;
 char c[100];
  long n;
  Stack1 *s=Stack1_new();
  
  gets(c);                  //string accepted with white space
  n=strlen(c);
  
  for(d=0;d<n;d++)           //if there is a number,convert it to integer and then call conv(),store it in Stack1
  { k=0;
    if(isdigit(c[d]))
    { for(j=d;j<n &&c[j]!=' ';j++)
        { a[k]=c[j]-48;
           k++;
           }
           if(k!=0)
           {num=conv(a,k);d+=k-1;
            // printf("num=%d",num);
           } 
           Stack1_push(s,num);
      
      }
       else if((c[d]=='+'||c[d]=='-'||c[d]=='*'||c[d]=='/'||c[d]=='%'||c[d]=='&'||c[d]=='|'||c[d]=='^') &&(c[d+1]==' '||c[d+1]=='\0'))//alue,push into Stack1
      {  i1=Stack1_pop(s);
        i2=Stack1_pop(s);
        i3=calc(i2,i1,c[d]);
        Stack1_push(s,i3);
        }
        else if(c[d]=='-')
        {//printf("hh");
        
        if(isdigit(c[d+1]))
    { for(j=d+1;j<n &&c[j]!=' ';j++)
        { a[k]=c[j]-48;
          // printf("a[k]=%lld",a[k]);
           k++;
           }
           int hh;
          
           if(k!=0)
           {num=conv(a,k);d+=k;
            // printf("num=%lld",num);
           } 
           Stack1_push(s,-1*num);
      
      }
        
        
        }
        }
        
        i=Stack1_pop(s);   //finally pop out last elem and print it
        printf("%lld\n",i);
        }
        }
  
 

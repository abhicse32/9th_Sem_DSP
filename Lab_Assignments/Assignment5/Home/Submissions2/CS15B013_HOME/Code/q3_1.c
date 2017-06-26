#include<stdio.h>
#include"stack.h"
#include<string.h>

int main()
{

 char arr[1000],a;
 int loop=0;
 for(;loop<10;loop++)
 {
   stack * stk=stack_new();
 stack * oper=stack_new();
 
 fgets(arr,1000,stdin);
 int i,prev,waste;
 int size=strlen(arr);
 
 for(i=0;i<size;)
 {a=arr[i];
  
     
  switch(arr[i])
  {
   
   
   case '(':stack_push(oper,arr[i]);
          i=i+2;
          break;
   case ')':prev=stack_pop(oper);
          while(prev!='(')
          {
           stack_push(stk,prev);stack_push(stk,' ');
           prev=stack_pop(oper);
          } 
          i=i+2;
          break;      
  
   case '+': if(stack_is_empty(oper))
           {
            stack_push(oper,arr[i]);
            
           }
           else
           {
            prev=stack_pop(oper);
            while(prev=='*' || prev=='/' || prev=='%' || prev=='+' || prev=='-' )
            {
             stack_push(stk,prev);stack_push(stk,' ');
             if(!stack_is_empty(oper))
             prev=stack_pop(oper);
             else
             break;
            }
            if(prev=='*' || prev=='/' || prev=='%' || prev=='+' || prev=='-' )
             waste=0;
            else
             stack_push(oper,prev);
             
            stack_push(oper,arr[i]);  
           }
           
           i=i+2; 
          break;
          
    case '-': if(stack_is_empty(oper))
           {
            stack_push(oper,arr[i]);
            
           }
           else
           {
            prev=stack_pop(oper);
            while(prev=='*' || prev=='/' || prev=='%' || prev=='+' || prev=='-' )
            {
             stack_push(stk,prev);stack_push(stk,' ');
             if(!stack_is_empty(oper))
             prev=stack_pop(oper);
             else
             break;
            }
            if(prev=='*' || prev=='/' || prev=='%' || prev=='+' || prev=='-' )
             waste=0;
            else
             {stack_push(oper,prev);}
             
            stack_push(oper,arr[i]);  
           }
           
           i=i+2; 
          break;
          
   case '*': if(stack_is_empty(oper))
           {
            stack_push(oper,arr[i]);
            
           }
           else
           {
            prev=stack_pop(oper);
            while(prev=='*' || prev=='/' || prev=='%' )
            {
             stack_push(stk,prev);stack_push(stk,' ');
             if(!stack_is_empty(oper))
             prev=stack_pop(oper);
             else
             break;
            }
            if(prev=='*' || prev=='/' || prev=='%' )
             waste=0;
            else
             stack_push(oper,prev);
             
            stack_push(oper,arr[i]);  
           }
           
           i=i+2; 
          break;  
          
    case '/': if(stack_is_empty(oper))
           {
            stack_push(oper,arr[i]);
            
           }
           else
           {
            prev=stack_pop(oper);
            while(prev=='*' || prev=='/' || prev=='%' )
            {
             stack_push(stk,prev);stack_push(stk,' ');
             if(!stack_is_empty(oper))
             prev=stack_pop(oper);
             else
             break;
            }
            if(prev=='*' || prev=='/' || prev=='%' )
             waste=0;
            else
             stack_push(oper,prev);
             
            stack_push(oper,arr[i]);  
           }
           
           i=i+2; 
          break;                     
   
   
   case '%': if(stack_is_empty(oper))
           {
            stack_push(oper,arr[i]);
            
           }
           else
           {
            prev=stack_pop(oper);
            while(prev=='*' || prev=='/' || prev=='%' )
            {
             stack_push(stk,prev);stack_push(stk,' ');
             if(!stack_is_empty(oper))
             prev=stack_pop(oper);
             else
             break;
            }
            if(prev=='*' || prev=='/' || prev=='%' )
             waste=0;
            else
             stack_push(oper,prev);
             
            stack_push(oper,arr[i]);  
           }
           
           i=i+2; 
          break;     
   
    case '&': if(stack_is_empty(oper))
           {
            stack_push(oper,arr[i]);
            
           }
           else
           {
            prev=stack_pop(oper);
            while(prev=='*' || prev=='/' || prev=='%' || prev=='+' || prev=='-' || prev=='&' )
            {
             stack_push(stk,prev);stack_push(stk,' ');
             if(!stack_is_empty(oper))
             prev=stack_pop(oper);
             else
             break;
            }
            if(prev=='*' || prev=='/' || prev=='%' || prev=='+' || prev=='-' || prev=='&' )
             waste=0;
            else
             stack_push(oper,prev);
             
            stack_push(oper,arr[i]);  
           }
           
           i=i+2; 
          break;    
   
     case '^': if(stack_is_empty(oper))
           {
            stack_push(oper,arr[i]);
            
           }
           else
           {
            prev=stack_pop(oper);
            while(prev=='*' || prev=='/' || prev=='%' || prev=='+' || prev=='-' || prev=='&' ||prev=='^')
            {
             stack_push(stk,prev);stack_push(stk,' ');
             if(!stack_is_empty(oper))
             prev=stack_pop(oper);
             else
             break;
            }
            if(prev=='*' || prev=='/' || prev=='%' || prev=='+' || prev=='-' || prev=='&' || prev=='^')
             waste=0;
            else
             stack_push(oper,prev);
            stack_push(oper,arr[i]);  
           }
           
           i=i+2; 
          break; 
          
   
     case '|': if(stack_is_empty(oper))
           {
            stack_push(oper,arr[i]);
            
           }
           else
           {
            prev=stack_pop(oper);
            while(prev=='*' || prev=='/' || prev=='%' || prev=='+' || prev=='-' || prev=='&' ||prev=='^' || prev=='|')
            {
             stack_push(stk,prev);stack_push(stk,' ');
             if(!stack_is_empty(oper))
             prev=stack_pop(oper);
             else
             break;
            }
            if(prev=='*' || prev=='/' || prev=='%' || prev=='+' || prev=='-' || prev=='&' || prev=='^' || prev=='|')
             waste=0;
            else
             stack_push(oper,prev);
             
            stack_push(oper,arr[i]);  
           }
           
           i=i+2; 
          break; 
          
                 
   
    default:stack_push(stk,arr[i]);
            i++;
            break;
   
           
  }
 }          char dont=stack_pop(stk);
            stack_push(stk,' ');
            while(!stack_is_empty(oper))
               {stack_push(stk,stack_pop(oper));
                stack_push(stk,' ');
               }
        
 
 
  stack * new=stack_new();
  while(!stack_is_empty(stk))
    stack_push(new,stack_pop(stk));
    
  while(!stack_is_empty(new))
    {printf("%c",stack_pop(new));} 
    
  printf("\n");  
}  
}
















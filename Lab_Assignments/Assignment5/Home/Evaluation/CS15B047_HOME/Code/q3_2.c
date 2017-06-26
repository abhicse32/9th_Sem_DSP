#include<stdio.h>
#include"stack.h"
#include<string.h>
#include<math.h>

//Evaluate operations using given operator
int evaluate(stack *S , char oper)
{
        int num2 = stack_pop(S) ;
        int num1 = stack_pop(S) ;
        
        if(oper == '+')
        {
                return num1 + num2 ;
        }
        else if(oper == '-')
        {
                return num1 - num2 ;
        }
        else if(oper == '*')
        {
                return num1 * num2 ;
        }
        else if(oper == '/')
        {
                return num1 / num2 ;
        }
        else if(oper == '^')
        {
                return num1 ^ num2 ;
        }                           
        else if(oper == '%')
        {
                return num1 % num2 ;
        }
        else if(oper == '|')
        {
                return num1 | num2 ;
        }
        else if(oper == '&')
        {
                return num1 & num2 ;
        }                     
}


int main()
{
        char str[1000] ;
        //Create and initialize stack
        stack *S ;
        S = stack_new() ;
        //Read till end of file
        while(fgets(str,1000,stdin)!=NULL)      
        {       
                //Append null char
                str[strlen(str)-1] = '\0' ;
                //Divide str into tokens delimited by space  --> tokens are either operators or operands
                char *token = strtok(str," ") ;        
                
                while(token !=  NULL)
                {
                        //If token is an integer -> push on stack                                                                                               
                        if(((int)token[0] >= '0' && (int)token[0] <='9') || (token[0]=='-' && strlen(token) >=2 ))
                        {
                                stack_push(S,atoi(token)) ;                
                        }
                        //Else Pop 2 ele as operands & push evaluated result using operator on stack
                        else
                        {
                                stack_push(S,evaluate(S,token[0])) ;        
                        }                                                                     
                        token = strtok(NULL, " ");
                }
                //Print answer 
                stack_print(S) ;
                //Empty stack
                while(stack_is_empty(S) == false)
                {
                        int x = stack_pop(S) ;         
                }  
                printf("\n");             
        }
}

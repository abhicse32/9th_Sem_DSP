#include<stdio.h>
#include"stack.h"
#include<string.h>

//Returns priority of given operator
int priority(char a)
{
        if((char)a == '|') 
                return 1;
        if((char)a == '^')
                return 2;
        if((char)a == '&')
                return 3;        
        if((char)a == '+' || (char)a == '-')
                return 4;
        if((char)a == '*' || (char)a == '/' || (char)a == '%')
                return 5;       
}

int main()
{
        char str[1001] ;
        //Create and initialize stack 
        stack *S ;
        S = stack_new() ;
        //Take i/p till end of file
        while(fgets(str,1000,stdin) != NULL)
        {             
                //Append null character
                str[strlen(str)-1] = '\0' ;
                //Divide the string into tokens delimited by space   
                char *token = strtok(str," ") ;        
                while(token != NULL)        
                {        
                        //Check for numbers ,small and capital letters                        
                        if( (token[0] >= 65 && token[0] <= 90) || (token[0] >= 97 && token[0] <= 122) || (token[0] >= (int)'0' && token[0] <= (int)'9') )
                        {
                                printf("%s ",token);                                                
                        }
                        //if empty --> push operator or ( 
                        else if(stack_is_empty(S)==true)
                        {       
                                stack_push(S,(int)token[0]);        
                        }
                        
                        //Push (
                        else if(token[0] == '(')
                        {
                                stack_push(S,(int)token[0]) ;
                        }
                        //Pop ele till ( when ) is encountered
                        else if(token[0] == ')')
                        {
                                if(stack_is_empty(S) == false)
                                {
                                        while(S->top->head->data != '(')
                                        {
                                                printf("%c ",(char)stack_pop(S));
                                        }                                                
                                        char t = stack_pop(S);
                                }
                        }
                        //Check priority -
                        //->If incoming ele has higher priority -->push
                        //Else pop till encountering ele with smaller priority or (   
                        else if(stack_is_empty(S) == false)
                        {
                                if(priority(token[0]) > priority((char)S->top->head->data))
                                        stack_push(S,(int)token[0]) ;
                                else
                                {
                                        while(stack_is_empty(S) == false && S->top->head->data != (int)'(' && priority(S->top->head->data) >= priority(token[0]) )
                                        {
                                                printf("%c ",(char)stack_pop(S));                                       
                                        }
                                        stack_push(S,(int)token[0]);                                                               
                                }               
                        }                                                                                                       
                        token = strtok(NULL," ") ;                        
                }                
                //Print stack
                while(stack_is_empty(S) ==  false)
                {
                        printf("%c ",(char)stack_pop(S));                        
                }
                printf("\n");
                //Empty stack                
                while(stack_is_empty(S) ==  false)
                {
                        stack_pop(S) ;                        
                }
        }                                               
}

/* KOMMURU ALEKHYA REDDY 
        CS15B059
        30AUG2016
 INFIX TO POSTFIX CONVERSION
 */ 
 #include<stdio.h>
#include"stack.h"
#include<string.h>
#define size 1000
int count =0;
void addstack(stack * temp,char elm);
void popstack(stack * temp);//defining the prototypes of functions
void main()
{
        count =0;
        char input[size];
        int len=0;
        while(fgets(input,size,stdin))  //the loop continues till we have an input
        {
        len=strlen(input);      //using the function to get length 
        int x=0;
        stack* temp=stack_new();
        stack_push(temp,-1);    //pushing a sentinel first
        
        while(x<(len-1))
        {
                 
                if(input[x]==' ')
                x++;//increments if it encounters a space
                else
                {       
                
                        if(input[x]=='(' ||input[x]==')' ||input[x]=='+' ||input[x]=='^' ||input[x]=='*' ||input[x]=='/'||input[x]=='&' ||input[x]=='|'||input[x]=='%'  ) 
                                {
                                addstack(temp,input[x]);        //if you encounter any operator other than minus
                                x++;
                               
                                }
                        else if(input[x]=='-'&& input[x+1]==' ')  
                                {      
                                addstack(temp,input[x]);        //if you encounter a negative sign followed by a space, its just an operator
                                x++;
                                }
                        else if(input[x]=='-')        
                        {
                                while(input[x]!=' ')    //inputing negative inputs
                                {
                                        printf("%c",input[x]);     
                                        x++;        
                                }

                        }     
                        else if(input[x]>63 && input[x+1]==' ' )  
                        {
                        printf("%c ",input[x]);//if its a variable it followed by space prints it
                        x++;
                        }
                        else if(input[x]>63 && (int)input[x+1]==0 )  
                        {
                        printf("%c ",input[x]);//if its the last variable it prints it
                        x++;
                        }
                        else    //implies that its a multi character variable
                        {
                        printf("%c",input[x]);
                        x++;
                                while(input[x]!=' '&& input[x+1]!='\0')
                                { 
                                printf("%c",input[x]);
                                x++;
                                }
                                printf(" ");
                       }
                                            
                }     
                    
        }
      
      
       popstack(temp);//pops all the remaining operators from the stack
       printf("\n");
      }
}

//function which checks the precedence and pushes the operator
void addstack(stack * temp,char elm)
{
        int x=0;
        if(elm=='(')
        {
                stack_push(temp,elm);
                count++;
        }
        else if(elm=='*'|| elm=='/' || elm =='%')//if it is an operator of lesser precedence
        {       
                if(temp->top->head->data == -1)
                {
                        stack_push(temp,elm);
                        count++;
                }
                else
                {
                while(temp->top->head->data != -1)
                {
                if(temp->top->head->data == '('||temp->top->head->data == '+'||temp->top->head->data == '-'||temp->top->head->data == '&'||temp->top->head->data == '|'||temp->top->head->data == '^')//if it is of same precedence then just push it
                {
                        break;
                }
                else if( temp->top->head->data == '*'|| temp->top->head->data == '/'|| temp->top->head->data == '%')//pop all the operators of higher or equal precedence till you encounter an operator of same precedence
                {
                        x=stack_pop(temp);//pop it and print
                        count--;
                        printf("%c ",x);
                }
                }
                stack_push(temp,elm);    //finally push the element    
                count++;
                }
        }   
        else if(elm==')')
        {
        while(x!='(') 
        
        {
                x=stack_pop(temp);
                count--;
                if(x!='(')
                printf("%c ",x);//print all of them except the brace
        } 
        } 
        
        
        else if(elm=='+'|| elm=='-')
        {       
                if(temp->top->head->data == -1)
                {
                        stack_push(temp,elm);
                        count++;
                }
                else
                {
                while(temp->top->head->data != -1)
                {
                if( temp->top->head->data == '('|| temp->top->head->data == '&'|| temp->top->head->data == '^'|| temp->top->head->data == '|')//if it is of lesser precedence then just push
                {
                        break;
                }
                else if( temp->top->head->data == '+'||temp->top->head->data == '*'|| temp->top->head->data == '/'|| temp->top->head->data == '%'|| temp->top->head->data == '-')//pop all the operators of higher precedence till you encounter an operator of lesser precedence
                {
                        x=stack_pop(temp);//pop it and print
                        count--;
                        printf("%c ",x);
                }
                }
                stack_push(temp,elm);    //finally push the element    
                count++;
                }
        }    
        
        else if(elm=='&' )
        {
                if(temp->top->head->data == -1)
                {
                        stack_push(temp,elm);
                        count++;
                }
                else
                {
                while(temp->top->head->data != -1)
                {
                if(temp->top->head->data == '|' ||temp->top->head->data == '^' ||temp->top->head->data == '(')//if it is of lesser precedence then just push it
                {
                        break;
                }
                else if( temp->top->head->data == '&'||temp->top->head->data == '+'|| temp->top->head->data == '-' ||temp->top->head->data == '*' ||temp->top->head->data == '/'|| temp->top->head->data == '%')//pop all the operators of higher precedence till you encounter an operator of lesser precedence
                {
                        x=stack_pop(temp);//pop it and print
                        count--;
                        printf("%c ",x);
                }
                }
                stack_push(temp,elm);    //finally push the element    
                count++;
                }
        }    
        
        else if(elm=='^')
        {
                while(temp->top->head->data != -1)
                {
                if(temp->top->head->data == '|' ||  temp->top->head->data == '(')//if it is of lesser precedence then just push it
                {
                        break;
                }
                else if(temp->top->head->data == '&'|| temp->top->head->data == '^'|| temp->top->head->data == '+' ||temp->top->head->data == '-' ||temp->top->head->data == '*' ||temp->top->head->data == '/'|| temp->top->head->data == '%')//pop all the operators of higher precedence till you encounter an operator of lesser precedence
                {
                        x=stack_pop(temp);//pop it and print
                        count--;
                        printf("%c ",x);
                }
                }
                stack_push(temp,elm);    //finally push the element    
                count++;
        }      
        else if(elm=='|')
        {
                if(temp->top->head->data==-1)
                {
                        stack_push(temp,elm);
                        count++;
                }
                else
                {
                while(temp->top->head->data != -1)
                {
                if(temp->top->head->data == '(')//if it is of lesser precedence then just push it
                {
                        break;
                }
                else if(temp->top->head->data == '+' || temp->top->head->data == '-'|| temp->top->head->data == '*'|| temp->top->head->data == '/'|| temp->top->head->data == '|' ||temp->top->head->data == '&' ||temp->top->head->data == '^'|| temp->top->head->data == '%'||temp->top->head->data == '|')//pop all the operators of higher precedence till you encounter an operator of lesser precedence
                {
                        x=stack_pop(temp);//pop it and print
                        count--;
                        printf("%c ",x);
                }
                }
                stack_push(temp,elm);    //finally push the element    
                count++;
                
        }  
        }    
        
        
}



//to pop and print all the remaining operators
void popstack(stack * temp)
{
        int x;
        while(count>0)//initially appended a sentinal character -1 as ascii can never be negative
        {
                x=stack_pop(temp);
                count--;
                printf("%c ",x);//prints the value of the popped element
        }

}

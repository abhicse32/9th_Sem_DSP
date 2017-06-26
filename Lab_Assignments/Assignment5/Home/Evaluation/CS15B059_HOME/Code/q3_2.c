/* KOMMURU ALEKHYA REDDY 
        CS15B059
        30AUG2016
        EVALUATION OF POSTFIX EXPRESSION 
*/ 
#include<stdio.h>
#include"stack.h"
#define size 1000
#include<string.h>
void addstack(stack * temp, int elm);//function prototype 
void main()
{
        char input[size];
        //gets the input from the keyboard
        
        int x=0,y,t;
        int no;
        int result;
        int neg;
        int len;
        while(fgets(input,size,stdin))  //continue to get the input till nothing is entered
        {
        len=strlen(input);
        stack* temp=stack_new();        //get the length
        x=0;
        while(x<(len-1))        //appends an extra /n after the word
        {
                if((int)input[x]==' ')
                x++;//if the character is a space just increment it 
                else if(input[x]=='-' && input[x+1]!=' ')       //if its a negative number
                {
                        neg=0;
                        x++;
                        while(input[x]!=' ')
                        {
                        neg=neg*10+(input[x]-48);
                        x++;
                        }
                        no=neg*-1;
                        stack_push(temp,no);    //input the number itself
                        
                }
                else if(input[x]>47 && input[x]< 58)
                {
                        no=input[x]-48;
                        x++;
                        while(input[x]>47 && input[x]<58)
                        {
                                no=no*10+(input[x]-48);//if the integer is more than one character long
                                x++;
                        }
                        stack_push(temp,no);//input the the new no
                }               
                else{
                         if(input[x]=='+'){
                        t=stack_pop(temp);
                        y=stack_pop(temp);
                        stack_push(temp,t+y);// for addition
                        }
                else if(input[x]=='-'){
                        t=stack_pop(temp);
                        y=stack_pop(temp);
                        stack_push(temp,y-t); //for subtraction
                        } 
                else if(input[x]=='*'){
                        t=stack_pop(temp);
                        y=stack_pop(temp);
                        stack_push(temp,y*t);//for multiplication
                        }      
                else if(input[x]=='/'){
                        t=stack_pop(temp);
                        y=stack_pop(temp);
                        stack_push(temp,y/t);//for division
                        } 
                  else if(input[x]=='%'){
                        t=stack_pop(temp);
                        y=stack_pop(temp);
                        stack_push(temp,y%t);//for division
                        }         
                 else if(input[x]=='&'){
                        t=stack_pop(temp);
                        y=stack_pop(temp);
                        stack_push(temp,y&t);//for division
                        }  
                else if(input[x]=='|'){
                        t=stack_pop(temp);
                        y=stack_pop(temp);
                        stack_push(temp,y|t);//for division
                        }  
                 else if(input[x]=='^'){
                        t=stack_pop(temp);
                        y=stack_pop(temp);
                        stack_push(temp,y^t);//for division
                        }                            
                else;   
                x++;   
                } 
                
        }
        result=stack_pop(temp);
        printf("%d\n",result);//prints the value of the integer  
        
        }
}


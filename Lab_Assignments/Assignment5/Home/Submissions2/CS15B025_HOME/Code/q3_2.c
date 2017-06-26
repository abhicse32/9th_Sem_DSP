/*
  TO EVALUATE A POSTFIX EXPRESSION
*/
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "List.h"
#include <string.h>
#define BUFF_SIZE 1000
int main(int* argc, char* argv[])
{
    char *in;
    in = (char *)malloc(BUFF_SIZE * sizeof(char));
    while(fgets(in,BUFF_SIZE,stdin)!=NULL)            //TAKING IN INPUT
    {
        int i = 0;
        stack *S = stack_new();                       //CREATNG A STACK
        while(in[i] != '\0')
        {
            if((in[i] != ' ') && (in[i] != '\n'))
            {
                if((in[i] == '-') && ((in[i+1] >= '0') && (in[i+1] <= '9')))   //PUSHING OPERANDS INTO STACK
                {
                    int op = in[++i]-48;
                    while(in[++i] != ' ')
                        op = (op*10)+(in[i]-48);
                    stack_push(S,(-op));
                }
                else if((in[i] >= '0') && (in[i] <= '9'))
                {
                    int op;
                    stack_push(S,(in[i]-48));
                    while(in[++i] != ' ')
                    {
                        op = stack_pop(S);
                        stack_push(S,((10 * op) + (in[i] - 48)));
                    }
                 }
                else                                  //POPPING THE OPERANDS AND OPERATING WITH THE OPERATOR
                {
                    int op1 = stack_pop(S);
                    int op2 = stack_pop(S);
                    switch(in[i])
                    {
                        case '+':{stack_push(S,(op2 + op1));break;}
                        case '-':{stack_push(S,(op2 - op1));break;}
                        case '*':{stack_push(S,(op2 * op1));break;}
                        case '/':{stack_push(S,(op2 / op1));break;}
                        case '%':{stack_push(S,(op2 % op1));break;}
                        case '&':{stack_push(S,(op2 & op1));break;}
                        case '|':{stack_push(S,(op2 | op1));break;}
                        case '^':{stack_push(S,(op2 ^ op1));break;}
                    }
                    i++;
                }
            }
            else                                      //IF INPUT CHAR IS SPACE, THEN IGNORE
                i++;
        }
        printf("%d\n",stack_pop(S));                  //PRINTING THE OUTPUT
    }
}

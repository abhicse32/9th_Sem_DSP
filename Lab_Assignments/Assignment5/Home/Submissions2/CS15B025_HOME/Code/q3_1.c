/*
  TO COONVERT AN INFIX EXPRESSION 
  TO A POSTIX EXPRESSION
*/
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "List.h"
#include <string.h>
#define BUFF_SIZE 1000

int precedence(char op)                                //TO RETURN THE PRECEDENCE OF AN OPERATOR
{
    if(op == '|')
        return 0;
    if(op == '^')
        return 1;
    if(op == '&')
        return 2;
    if((op == '+') || (op == '-'))
        return 3;
    if((op == '*') || (op == '/') || (op == '%'))
        return 4;
    return -1;
}

int main(int* argc, char* argv[])
{
    char *in;
    in = (char *)malloc(BUFF_SIZE * sizeof(char));
    while(fgets(in,BUFF_SIZE,stdin)!=NULL)            //TAKING INPUT
    {
        stack *s;
        s = stack_new();                              //CREATING A NEW STACK
        int i = 0;
        while(in[i] != '\0')
        {
            if((in[i] != ' ') && (in[i] != '\n'))
            {
                if(((in[i] >= '0') && (in[i] <= '9')) || ((in[i] >= 'a') && (in[i] <= 'z')) ||  ((in[i] >= 'A') && (in[i] <= 'Z')))           //IF INPUT CHAR IS OPERAND
                {
                    printf("%c",in[i]);
                    while(in[++i] != ' ')             //TO TAKE IN OPERAND WITH MULTIPLE CHARACTERS
                    {
                        if(in[i] == '\n')
                        {
                            break;
                        }
                        printf("%c",in[i]);
                    }
                    printf(" ");
                }
                else if(in[i] == '(')                 //PUSHING '('
                {
                    stack_push(s,in[i]);
                    i++;
                }
                else if(in[i] == ')')                 //POPPING TILL WE ENCOUNTER ')'
                {
                    while((!stack_is_empty(s)) && ((((s->top)->head)->data) != '('))
                        printf("%c ",stack_pop(s));
                    stack_pop(s);
                    i++;
                }
                else                                  //PUSHING AND POPPING OPERATORS BASED ON PRECEDENCE
                {
                    if(((s->top)->head) == NULL)
                        stack_push(s,in[i]);
                    else
                    {
                        Node *temp;
                        temp = (((s->top)->head));
                        while((!stack_is_empty(s)) && (precedence(in[i]) <= precedence(temp->data)))
                        {
                            char x = stack_pop(s);
                            if(x != '(')
                                printf("%c ",x);
                            temp = temp->next;
                        }
                        stack_push(s,in[i]);
                    }
                    i++;
                }
            }
            else                                      //IF INPUT CHAR IS ' '
            {
                i++;
            }
        }
        while(!stack_is_empty(s))                     //EMPTYING THE STACK
            printf("%c ",stack_pop(s));
        printf("\n");
    }
}

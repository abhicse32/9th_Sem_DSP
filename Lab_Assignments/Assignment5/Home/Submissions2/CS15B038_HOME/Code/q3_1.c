#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack_a{
	char **arr;
	int top;
}stack;

void infix_to_postfix(stack* B, stack* A);
void F1(stack* B);
void F2(stack* B);
void F3(stack* B);
void F4(stack* B);
void F5(stack* B);

stack* stack_new()
{
     stack* A;
     A = malloc(sizeof(stack));
     A->arr = malloc(sizeof(char*)*1000);
     A->top = -1;
     return A;
}

int stack_size(stack* A)
{
     return (A->top + 1);
}

void stack_push(stack* A, char* a)
{
     A->top = A->top + 1;
     A->arr[A->top] = a;
}

char* stack_pop(stack* A)
{
     char *x = A->arr[A->top];
     A->top = A->top - 1;
     return x;
}

int stack_is_empty(stack* A)
{
     if(A->top == -1) return 1;
     else return 0;
}

int stack_is_full(stack* A)
{
     if(A->top == 999) return 1;
     else return 0;
}

void stack_print(stack* A)
{
     int i;
     for(i = A->top; i >= 0; i--)
     {
          printf("%s ", A->arr[i]);
     }
     printf("\n");
}

int main()
{
     int i, j;
     char temp;
     char* q;

     for(j=0; j<10; j++)
     {
          stack* A = stack_new();
          char x[10]; char a;
          int flag = 0;
     
          while(1)
          {
               a = getchar();
               if(a == '\n') break;
               x[0] = a;                    
          
               for(i=1;;i++)
               {
                    temp = getchar();
                    if(temp == ' ') break;
                    if(temp == '\n'){flag = 1; break;}
                    x[i] = temp;
               }
                    
               x[i] = '\0';

               if(x[0] != ')') stack_push(A , x);
               
               else 
               {
                    stack* B = stack_new();
                    
                    while(1)
                    {
                         char* z = stack_pop(A);
                         if(z[0] == '(') 
                         {
                              F1(B);
                              F2(B);
                              F3(B);
                              F4(B);
                              F5(B);
          
                              q = stack_pop(B);
                              stack_push(A, q);
                              break; 
                         }
               
                         stack_push(B, z);
                    }
                         
               }
     
               if(flag==1) break;
          }

          stack* B = stack_new();
           
           while(1)
           {
               char* z = stack_pop(A);
               if(stack_is_empty(A) == 1) 
               {
                    F1(B);
                    F2(B);
                    F3(B);
                    F4(B);
                    F5(B);
     
                    q = stack_pop(B);
                    stack_push(A, q);
                    break; 
               }                              
               stack_push(B, z);
           }
           
           printf("%s", stack_pop(A)); fflush(stdout);
           
     }
}

void infix_to_postfix(stack* B, stack* A)
{
     char* z;
       
     F1(B);
     F2(B);
     F3(B);
     F4(B);
     F5(B);
     
     z = stack_pop(B);
     stack_push(A, z);
}

void F1(stack* B)
{
     if(stack_size(B)==1) return;
     
     char *z = stack_pop(B);
     char *q = z;
     char *y = stack_pop(B);
     if( y[0] == '*' || y[0] == '/' || y[0] == '%') 
     {
          char *w = stack_pop(B);
          strcat(z, " ");
          strcat(z, w);
          strcat(z, " ");
          strcat(z, y);
          stack_push(B, z);
          F1(B);
     }
     else
     {
          stack_push(B, y);
          F1(B);
          stack_push(B, q);  
     }
}

void F2(stack* B)
{
     if(stack_size(B)==1) return;
     
     char *z = stack_pop(B);
     char *q = z;
     char *y = stack_pop(B);
     if( y[0] == '+' || y[0] == '-') 
     {
          char *w = stack_pop(B);
          strcat(z, " ");
          strcat(z, w);
          strcat(z, " ");
          strcat(z, y);
          stack_push(B, z);
          F2(B);
     }
     else
     {
          stack_push(B, y);
          F2(B);
          stack_push(B, q);  
     }
}

void F3(stack* B)
{
     if(stack_size(B)==1) return;
     
     char *z = stack_pop(B);
     char *q = z;
     char *y = stack_pop(B);
     if( y[0] == '&') 
     {
          char *w = stack_pop(B);
          strcat(z, " ");
          strcat(z, w);
          strcat(z, " ");
          strcat(z, y);          
          stack_push(B, z);
          F3(B);
     }
     else
     {
          stack_push(B, y);
          F3(B);
          stack_push(B, q);  
     }
}

void F4(stack* B)
{
     if(stack_size(B)==1) return;
     
     char *z = stack_pop(B);
     char *q = z;
     char *y = stack_pop(B);
     if( y[0] == '^') 
     {
          char *w = stack_pop(B);
          strcat(z, " ");
          strcat(z, w);
          strcat(z, " ");
          strcat(z, y);          
          stack_push(B, z);
          F4(B);
     }
     else
     {
          stack_push(B, y);
          F4(B);
          stack_push(B, q);  
     }
     
     
}

void F5(stack* B)
{
     if(stack_size(B)==1) return;
     
     char *z = stack_pop(B);
     char *q = z;
     char *y = stack_pop(B);
     if( y[0] == '|') 
     {
          char *w = stack_pop(B);
          strcat(z, " ");
          strcat(z, w);
          strcat(z, " ");
          strcat(z, y);          
          stack_push(B, z);
          F5(B);
     }
     else
     {
          stack_push(B, y);
          F5(B);
          stack_push(B, q);  
     }
}



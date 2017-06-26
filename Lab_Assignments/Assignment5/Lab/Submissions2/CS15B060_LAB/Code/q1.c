#include<stdio.h>
#include<string.h>                                    //program to check no of legal parenthesis
#include<stdlib.h>

typedef struct stack{ char a[1005];                     //stack ADT using arrays
                       int top;}stk;
                       
                       void push(stk *s,char c)            //push element into stack
                       { if(s->top!=99)
                          { s->top++;
                            s->a[s->top]=c;
                            }
                            }
                            
                            char pop(stk *s)              //pop elements out of stack
                            {  char b;
                            
                              if(s->top!=-1)
                              {b=s->a[s->top];
                                s->top--;
                                 return b;
                                 }
                                 
                                 
                                 }
                                 
                                 char func(char j)          //returns opposite closing brackets for the foll paranthesis
                                 { if(j=='(')
                                   return ')';
                                   else  if(j=='[')
                                   return ']';
                                   else if(j=='{')
                                    return '}';
                                    }
                                 
                                 
                     
                              int check(char *b,int l)            // function to check if the given paranthesis stat is legal or not 
                              {int k,j,i=0;                       //if odd no of paranthesis->illegal
                                 char ch;
                                   stk *s= (stk*)malloc(sizeof(stk));
                                    s->top=-1;
                                   while(i<l)
                                   { if( b[i]!=')' && b[i]!='}' && b[i]!=']')
                                      {push(s,b[i]);}
                                      
                                      else                               //else run loop till end and check if first popped elem is opp to given elem or empty and } or ||
                                      { if(s->top==-1)
                                          return 0;
                                          
                                          else if(b[i]!=func(pop(s)))
                                             {
                                               
                                             
                                              
                                             return 0;}
                                             
                                             }
                                             i++;
                                             }
                                             
                                              return 1;
                                              }           
                                            
                                            
                                        
                                  
                              
                              
                              
                                 
                                 
                                 
                           void main()
                           { int n,l,m=0;
                             
                             
                              char c[100];
                              scanf("%d",&n);
                              while(n>0)                          // running loop for n values
                              { 
                                scanf("%s",c);     
                                l=strlen(c);
                                
                                 printf("%d\n",check(c,l));
                                 
                                 n--;
                                 }
                                
                                 
                                 }

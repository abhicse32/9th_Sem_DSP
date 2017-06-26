#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct stack{ char a[100];                //stack ADT
                       int top;}stk;
                       
                       void push(stk *s,char c)   //pushing element into stack
                       { if(s->top!=99)
                          { s->top++;
                            s->a[s->top]=c;
                            }
                            }
                            
                            char pop(stk *s)    //popping elements out of stack
                            {  char b;
                            
                              if(s->top!=-1)
                              {b=s->a[s->top];
                                s->top--;
                                 return b;
                                 }
                                 
                                 
                                 }
                                 
                                 char func(char j) 
                                 { if(j=='(')
                                   return ')';
                                   
                                    }
                                    
                                    
                                     int check(char *b,int l)          //this fn returns no of reversals(minimum)
                              {int k,j,i=0;                             //using fact that if {,push it
                                int ct=0;                                             //else if } and EMPTY stk,revert,increment reverse,pop it
                                 char ch;
                                   stk *s= (stk*)malloc(sizeof(stk));
                                    s->top=-1;                            
                                   if(l%2)
                                    return -1;
                                   
                                  /* while(i<l)
                                   { if( b[i]!=')' && b[i]!='}' && b[i]!=']')
                                      {push(s,b[i]);
                                       //printf("a");
                                       // for(j=0;j<=s->top;j++)
                                               // printf("%c",b[j]);
                                               }
                                      else 
                                      { if(s->top==-1)
                                          return -1;
                                          
                                          else if(b[i]!=func(pop(s)))
                                             { // printf("%c",pop(s));
                                                ct++;
                                               
                                             //printf("d"); 
                                             }
                                             //else
                                             //pop(s);
                                             }
                                             i++;
                                             }*/
                                             
                                             /*printf("e");
                                             if(s->top==-1)
                                              return 1;
                                              else return 0;*/
                                              int rev=0;
                                             while(i<l)
                                      { if( b[i]=='{' )
                                         {push(s,b[i]);}
                                           //printf("%d",s->top);
                                         else if( b[i]=='}' && s->top!=-1)
                                          pop(s);
                                          else if(b[i]=='}')
                                          {push(s,'{');rev++;}
                                          i++;
                                          }
                                          // printf("%d",s->top);
                                          if(s->top%2==0 && s->top!=-1)
                                           return -1;
                                           else 
                                           return  (rev+ (s->top+1)/2);          //s->top+1 is tot no of elements in stack
                                           //return(s->top/2+1);
                                              
                                              }
                                              
                                              
                                              
                                              
                                              
                                              
                                              
                                                         
                                            
                                            
                                        
                                  
                              
                              
                              
                                 
                                 
                                 
                           void main()                  //main() function
                           { int n,l,m=0;
                             
                             
                              char c[100];
                              scanf("%d",&n);
                              while(n>0)
                              { 
                                scanf("%s",c);     
                                l=strlen(c);
                                //printf("%d",l);
                                //if(check(c,l))
                                 printf("%d\n",check(c,l));
                                 //m++;
                                 n--;
                                 }
                                // printf("%d",m);
                                 
                                 }

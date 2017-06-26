#include<stdio.h>    //program for converting infix to postfix exprn
#include<stdlib.h>
#include<string.h>

typedef struct stk{ char a[1000];      //basic array - stack oprns copied from stack_a.c
                     int top;
                      }stk;
                      
        stk* create_stk()
        {stk *s=(stk*)malloc(sizeof(stk));
          s->top=-1;
          return s;}
          
          void push(stk *s,char a)
          {  if(!fullstk(s))
             {s->top++;
               s->a[s->top]=a;
                s->a[(s->top)+1]='\0';
                }
                
                }
                
                
                int emptystk(stk *s)
                {return (s->top==-1);}
                
                int fullstk(stk*s)
                { return(s->top==1000);}
                
             char pop(stk *s)
             {  char a;
             
               if(!emptystk(s))
                {a=s->a[s->top];
                  s->a[s->top]='\0';
                   s->top--;
                   return a;
                   }                      
                  return '\0';
                  
                  }
                  
                  int isp(char a)    //function for determining in-stack priority of an operator
                  { if(a==')')
                     return 0;
                     else if(a=='^')
                     return -4;
                     else if(a=='*'||a=='/' ||a=='%')
                     return 2;
                     else if(a=='+' ||a== '-')
                     return 1;
                     else if(a=='&' || a=='|')
                     return -2;
                     else if(a=='(')
                     return -5;
                     else return -1;
                     }
                    
                    
                     int icp(char a)  //function for determining in-coming priority of an operator
                  { if(a==')')
                     return 4;
                     else if(a=='^')
                     return 99;
                     else if(a=='*'||a=='/' ||a=='%')
                     return 2;
                     else if(a=='+' ||a== '-')
                     return 1;
                     else if(a=='&' || a=='|')
                     return -2;
                     else if(a=='(')
                     return 100;
                     else return -1;
                     }


                     

void main()
{  int ii=0;
   
   
   while(ii<10)
   { ii++;
   
   
    int n,i;
    char b[1000],c[1000];
  
     stk *s=create_stk();
     char a;
     
      
       gets(c);int k=0;          //accepting string with white space
       for(i=0;i<strlen(c);i++)
       {if(c[i]!=' ')           //removing all white-space characters and putting it into new string
         {b[k]=c[i];
           k++;
           }
      // printf("hhhh");
           }
       
       
       n=k;
         
          b[n]=')';
       push(s,'(');
       for(i=0;i<=n;i++)
       { // printf("h");
          if(isalnum(b[i]))     //if the character is alphabet,just print it
          {
             if(!isalnum(b[i+1]))
             {printf("%c ",b[i]); }
             else
              printf("%c",b[i]);
              }
              
       
       
           if(!isalnum(b[i]))
           { 
             a=pop(s);                                       //else if it is'(' just push it
              
              
                   if(isp(a)<icp(b[i]) && b[i]!=')')      //else check if (isp) >=(icp) ,if yes pop else push
                    {push(s,a); 
                    push(s,b[i]);}
                                                                  
                    else if(b[i]==')')
                    { 
                      //a=pop(s);
                      while(a!='(' &&s->top!=-1)
                      { if(a!='('&&a!=')')
                       { //printf(" ");
                       printf("%c ",a); }
                     //  printf("hhhh");//error
                        a=pop(s);}
                        }
                    
                    
                    else
                    { //if(a!='('&&a!=')')
                     //{//printf(" ");
                     //printf("%c",a);}
                     // a=pop(s);
                      while(a!='('&& isp(a)>=icp(b[i]) &&s->top!=-1  )
                      { if(a!='('&&a!=')')
                       {// printf(" ");
                       printf("%c ",a);}
                      // printf("hhhh");
                        a=pop(s);}
                       push(s,a);
                        push(s,b[i]);
                        }
                        
                        }
                        
                        
                      
                    }
                    
                    printf("\n");
                  } 
          
       }
     

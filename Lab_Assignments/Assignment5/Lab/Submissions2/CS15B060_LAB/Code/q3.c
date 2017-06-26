#include<stdio.h>
#include<stdlib.h>
typedef struct stack{ int a[100];                            //STACK ADT
                       int top;}stk;
  typedef struct max{ int a,b;}max;                       
                       void push(stk *s,int c)
                       { if(s->top!=99)
                          { s->top++;
                            s->a[s->top]=c;
                            }
                            }
                            
                            int pop(stk *s)
                            {  int b;
                            
                              if(s->top!=-1)
                              {b=s->a[s->top];
                                s->top--;
                                 return b;
                                 }
                                 
                                 
                                 }
                                 
                            void maxnext()                          //fn to compute next max element
                            { int t,n,i,j,arr[100],cur;
                            //max indd[100];
                              stk *tr=(stk*)malloc(sizeof(stk));
                              stk *ind=(stk*)malloc(sizeof(stk));
                              stk *val=(stk*)malloc(sizeof(stk));
                                 tr->top=-1;                       //3 stacks used tr,ind,val
                                 ind->top=-1;
                                 val->top=-1;
                                scanf("%d",&n);
                             //   for(i=0;i<n;i++)
                              //  {scanf("%d",&arr[i]);
                               //   indd[i].a=arr[i];}
                                   j=0;
                                   for(i=0;i<n;i++)
                                   scanf("%d",&arr[i]);
                                  //for(i=0;i<n;i++)
                                 //   indd[i].b=-1;
                                 int count;
                                  while(j<n)                         //now read value,if stack is empty,print it
                                  { if(tr->top==-1)                    
                                      push(tr,j);
                                      else
                                      { t=pop(tr);count=1;                //else if top element> incoming elem push it
                                      
                                        if(arr[j]<=arr[t])
                                        { push(tr,t);
                                          push(tr,j);
                                          }
                                          
                                          else                            //else pop elements as long as topelem<incoming elm
                                          {  
                                             while(arr[t]<arr[j] && (tr->top!=-1) )
                                             { push(ind,t);
                                              count=0;
                                               //push(val,arr[t]);
                                                push(val,arr[j]);
                                               t=pop(tr);
                                               //printf("h");
                                               }
                                               if(tr->top==-1 && arr[t]<arr[j])
                                               {push(tr,j);
                                                 push(ind,t);
                                                  push(val,arr[j]);
                                                  }
                                               else
                                               {push(tr,t);
                                                 push(tr,j);
                                               }
                                               
                                               }
                                               }
                                               j++;
                                               }
                                               
                                               while(tr->top!=-1)                //put it back to array
                                               {t=pop(tr);
                                                 push(ind,t);
                                                 //push(val,arr[t]);
                                                  push(val,-1);
                                                 }
                                                 
                                                 int r,s;
                                                 
                                                 while(val->top!=-1)
                                                 { r=pop(ind);
                                                   s=pop(val);
                                                    arr[r]=s;
                                                    }
                                                    for(i=0;i<n;i++)       //printing new array
                                                    printf("%d ",arr[i]);
                                             
                                             
                                        }
                                        
                                        
                                        
                                        void main()
                                        {int n,i;
                                          scanf("%d",&n);
                                           for(i=0;i<n;i++)
                                           {  maxnext();
                                              printf("\n");}
                                           
                                           }
                                        
                                        
                                        
                                        
                                             
                                             
                                             
                                          
                                        

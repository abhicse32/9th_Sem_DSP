#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
#include "List.h"


int main()
{ int test,i,n,a[10000],b[10000],x1,y1,flag,t1;
  scanf("%d",&test);
  while(test>0)
  { scanf("%d",&n);
    stack *i1,*i2,*val;
     i1= stack_new();
     i2= stack_new();
     val= stack_new();
    for(i=0;i<n;i++)
    { scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    { if( stack_is_empty(i1)==1 )
       stack_push(i1,i);
     else
     {flag=1;
      t1=stack_pop(i1);

      if(a[i]>a[t1])
      { while(a[i]>a[t1])
       {
        stack_push(i2,t1);
        stack_push(val,a[i]);
        if(stack_is_empty(i1)==1 )
         { stack_push(i1,i);
           flag=0;
           break;
         }
        t1=stack_pop(i1);
       }
       if(flag==1)
       {
       stack_push(i1,t1);
       stack_push(i1,i);
       }  
    }
     else
      { stack_push(i1,t1);
        stack_push(i1,i);
      }
    }
    }
for(i=0;i<n;i++)
 b[i]=a[i];

 while(stack_is_empty(i1)!=1 || stack_is_empty(i2)!=1)
  {  if(stack_is_empty(i1)!=1)
    {   x1=stack_pop(i1);
        b[x1]==-1;
    }
     if(stack_is_empty(i2)!=1)
    {   x1=stack_pop(i2);
        y1=stack_pop(val);
        b[x1]=y1;
    }
  }
for(i=0;i<n;i++)
{
 if(b[i]==a[i])
  printf("-1 ");
 else
 printf("%d ",b[i]);
}

printf("\n");
test--;
  }  

 return 0;
}

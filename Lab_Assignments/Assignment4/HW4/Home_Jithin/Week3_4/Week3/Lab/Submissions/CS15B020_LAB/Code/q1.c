#include<stdio.h>
#include<stdlib.h>
int k,ctr1=0,ctr2=0,ctr3=0;

int bsrch(int* a, int str, int last)
  { int mid;

    mid=(str+last)/2;

    if(last<str)
     { ctr1++;
       return (-1);
     }

    if(k>a[mid])
     { str=mid+1;
       (ctr1)++;
     }
    else if(k<a[mid])
     { last=mid-1;
       ctr1=ctr1+2;    
     }
    else
     { ctr1=ctr1+2;
       return mid;
     }

    return bsrch(a,str,last);

   }


int bsrch12(int* a, int str, int last)
  { int mid;

    mid=(str*2+last)/3;

    if(last<str)
     { ctr2+=1;
       return (-1);
     }

    if(k>a[mid])
     { str=mid+1;
       ctr2+=2;
     }
    else if(k<a[mid])
     { last=mid-1;
       ctr2+=2;
     }
    else
     { ctr2+=2;
       return mid;
     }

    return bsrch12(a,str,last);

   }

int trisrch(int* a, int str, int last)
  {  int mid1,mid2;

     mid1= (2*str+last)/3;
     mid2= (str+2*last)/3;
     
     if(str>=last)   
      { if(k==a[last])
          { ctr3+=2;
            return last;
          }
        ctr3+=2;
        return -1;
      } 

     if(k>a[mid2])
      { str=mid2+1;
        ctr3+=3;
      }
     else if(k>a[mid1])
      { str=mid1+1;
        last=mid2;
        ctr3+=4;    
      }
     else
      { last=mid1;
        ctr3+=4;
      }

    return trisrch(a,str,last);
  }
int main()
 { int n,i;

   scanf("%d",&n);

   int* a=(int*)malloc(n*sizeof(int));


   for(i=0;i<n;i++)
    scanf("%d",&a[i]);

   scanf("%d",&k);

   printf("%d ",bsrch(a,0,n-1));
   printf("%d ",bsrch12(a,0,n-1));
   printf("%d\n",trisrch(a,0,n-1));

   printf("%d %d %d\n",ctr1,ctr2,ctr3);
   return 0;
 }
   

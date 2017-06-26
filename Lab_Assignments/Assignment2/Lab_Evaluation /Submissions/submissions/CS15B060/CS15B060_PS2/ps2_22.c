#include<stdio.h>

void swap(int *a,int *b)   //swapping 2 values using pointers
{int t;
 t=*a;
  *a=*b;
  *b=t;
}
 
void bub(int* a,int n,int start)    //function for bubble sort
{int i,j;
  for(i=start;i<=n;i++){
        for(j=i-1;j>=start;j--){
                if(a[j]>a[j+1])
                         swap(&a[j],&a[j+1]);
        }
   }
 }

 void print(int* a,int n)                //seperate function for printing output
 { int i;
   for(i=0;i<n;i++)
   printf("%d",a[i]);
  }

int fact(int n)                           //function for calculating factorial
{if(n==0 || n==1 )
 return 1;

 else
 return n*fact(n-1);
}


  void per(int *a,int n)               //function generating permutation
  {
    int i,j,k,l;
    j=fact(n);
    print(a,n);
    for(i=1;i<j;i++)
    { k=n-1;
       while(k>0){
          if(a[k]>a[k-1])
            break;
          k--;
       }
       bub(a,n-1,k);
       for(l=k;l<n;l++){
            if(a[l]>a[k-1]){
                  swap(&a[k-1],&a[l]);
                  break;
            }
       }
       printf(" ");
       print(a,n);
   }
   printf("\n");
}
          

void main(){                                       //main function
        int n,a[20],i;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        bub(a,n-1,1);
        
        per(a,n);
}




 

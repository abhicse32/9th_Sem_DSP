#include<stdio.h>
#include<math.h>
int IsPrime();

void main()
{
  int n,m,i,min;
  scanf("%d %d",&n,&m);
  if(m<n){
    min=m;
    }
  else{
    min=n;
    }
  for(i=2;i<=min/2;i++){
    if(n%i==0 && m%i==0){
       if(IsPrime(i)==1){
          printf("%d\t",i);
          }
       }
    }
  if(n%m==0 || m%n==0){
    printf("%d",min);
    }
}

int IsPrime(int x){
   int i;
   for(i=2;i<x/2;i++){
       if ( x % i == 0)
       return(0);
     }
   return(1); 
}
  
  



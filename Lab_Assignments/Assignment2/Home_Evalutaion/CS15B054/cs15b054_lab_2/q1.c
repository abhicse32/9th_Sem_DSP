#include<stdio.h>
#include<sys/time.h>
void FibIteration(int n);
int FibRecursive(int n);

void FibIteration(int n)
{
   int i;
   int F1=1,F2=1,temp;
   if(n==1){
      printf("%d",F1);
     }
   else if(n==2){
      printf("%d %d",F1,F2);
     }

   else{
      printf("%d ",F1);
      for(i=0;i<n-1;i++)
        {
          temp=F1+F2;
          F1=F2;
          F2=temp;
          printf("%d ",F1);
        }
     }
}

int FibRecursive(int n)
{ 
  int k;
  if(n==1) return 1;
  else if(n==2) return 1;
  else{
     return FibRecursive(n-1)+FibRecursive(n-2);
     
   }
}
void main()
{
  int n,m,i;
  struct timeval t1,t2;
  scanf("%d",&n);

  gettimeofday(&t1,NULL); 
  FibIteration(n); 
  gettimeofday(&t2,NULL); 
  double timetaken = (double)(t2.tv_usec - t1.tv_usec);

  gettimeofday(&t1,NULL); 
  for(i=1;i<n+1;i++)
     {
       m=FibRecursive(i);
       printf("%d ",m);
     }
  gettimeofday(&t2,NULL);
  timetaken = (double)(t2.tv_usec - t1.tv_usec); 
  
}
    
  

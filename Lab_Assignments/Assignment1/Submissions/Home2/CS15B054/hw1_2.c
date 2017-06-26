#include<stdio.h>
void main()
{
  int n,i=0;
  int A[7];
  scanf("%d",&n);
  for(i=0;i<8;i++){
     A[i]=0;
     }
  for(i=0;i<8;i++){
     A[7-i]=n%16;
     n=n/16;
     }
  printf("0x%x",A[0]);
  for(i=1;i<8;i++){
     printf("%x",A[i]);
     }
}
  

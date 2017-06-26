#include<stdio.h>
#include<string.h>
int  main()
{ 
  char a[100],b[100];
  int l1,l2,i,j,flag=0;
  scanf("%s %s",a,b);
  l1=strlen(a);
  l2=strlen(b);
  if(l1!=l2){
    printf("0");
    }
  else{
     for(i=0;i<l1;i++)
       {
        for(j=0;j<l2;j++){
           if (a[i]==a[j]){
              a[j]=1;
              flag=1;
              }
           }
         if(flag==0){
           printf("0");
           break;
           }
         flag = 0;
       }
      }   
  if (i==l1){
       printf("1");
     }
}

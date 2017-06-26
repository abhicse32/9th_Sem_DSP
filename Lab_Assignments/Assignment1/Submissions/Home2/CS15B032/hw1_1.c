
/* project completed 
	by R.D.Nishal Singh, CS15B032 on 13.8.16
*/

#include<stdio.h>
int main(){
int a[100000],n,i,j=0,n1,n2;
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
 
  n1=a[0];
  for(i=1;i<n;i++){
      if(n1<a[i]){
           n1=a[i];
           j = i;
      }
  }
if(!j)
	n2=a[n-j-1];
else
	n2=a[0];
	
for(i=1;i<n;i++){
if(n2 <a[i] && j != i)
n2 =a[i];
  }
  
  printf("%d %d\n",n1,n2);
  return 0;
}

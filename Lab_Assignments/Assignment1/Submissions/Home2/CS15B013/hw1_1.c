//CS15B013 MAX AND NEXTMAX

#include <stdio.h>

int main()
{
  int num,max,nextmax,i1;int array[100000];
  scanf("%d",&num);

  for(i1=0;i1<num;i1++)
  	 { scanf("%d",&array[i1]);}

  if(array[0]>=array[1])
  	 {max=array[0];nextmax=array[1];}
  else
  	 {max=array[1];nextmax=array[0];}

  for(i1=2;i1<num;i1++)
  	 {
       if(array[i1]>max)
       	 {
       	   nextmax=max;
       	   max=array[i1];
       	 }
       else
       	 {
       	   if(array[i1]>nextmax)
              nextmax=array[i1];

       	 }
  	 }


  printf("%d %d",max,nextmax);



return 0;

}

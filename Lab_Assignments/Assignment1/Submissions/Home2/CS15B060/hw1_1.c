#include<stdio.h>


void main()
{ int n,*a,i,*b;
  scanf("%d",&n);
   a=(int*)malloc(n*sizeof(int));     
   for(i=0;i<n;i++)
     scanf("%d",&a[i]);
   b=(int*)malloc((2*n-1)*sizeof(int)); //dynamically allocated arrays a and b

 for(i=n;i<=(2*n-1);i++)         //copying elements onto new array b
  b[i]=a[i-n];
 
  for(i=2*n-1;i>1;i-=2)          //simple algorithm to find max...b[1] will be max
   if(b[i]>b[i-1])
    b[i/2]=b[i];
    else
    b[i/2]=b[i-1];


   int ct=0;
  int max=b[1];
   for(i=2;i<2*n-1;i+=2)
   { if(b[i]==max)
     a[ct++]=b[i+1];
    else if(b[i+1]==max)          //storing the elements lost to max from tournament Data structures       
      a[ct++]=b[i];
    }

  
   int max1=a[0];
   for(i=1;i<ct;i++)
  
  if(a[i]>max1)
    max1=a[i];              //finding next max at worst case takes O(log n) steps



   printf("%d %d",max,max1);  //printing max and next max
}
     


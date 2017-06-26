#include<stdio.h>
int main()
{ int n,arr[100],k,j,temp;
  scanf("%d",&n);   //to take the number of inputs value 1<=n<=100
  for(j=0;j<n;j++)  //loop to take inputs
   scanf("%d",&arr[j]);
  k=1;
  do                            
   { for(j=0;k+j<n;)                   //this loop will compare pairs starting from 1st element k distance apartand push the maximum value to the right of each pair
      { if(arr[j]<arr[j+k])
	 { temp=arr[j];
	   arr[j]=arr[j+k];
	   arr[j+k]=temp;
	 }
	j=j+2*k;
      }
     k=2*k;
     for(j=0;k+j+1<n;)              //this loop will compare pairs starting from 2nd element 2*k distance apart and push the minimum value to the right of each pair
      { if(arr[j+1]>arr[j+k+1])
	 { temp=arr[j+1];
	   arr[j+1]=arr[j+k+1];
	   arr[j+k+1]=temp;
	 }
	 j=j+k;
      }
   }while(k<n);
  printf("%d %d",arr[1],arr[0]);  //arr[1] is minimum value arr[0] is maxmimum value
 return 0;
}

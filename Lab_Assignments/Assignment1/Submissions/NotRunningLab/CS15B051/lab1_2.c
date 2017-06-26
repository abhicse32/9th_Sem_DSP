#include<stdio.h>
#include<stdlib.h>

struct value 
{
  int min;
  int max;
};
typedef struct value Value;
  Value get_value(int *a, int l, int r) 
   {
    Value result,left,right;      
    int mid;
    
    result.max = a[l];
    result.min = a[l];
   
    if(r == l)
        return result;
    mid = (l + r)/2; // splitting array into two equal sub arrays
    left = get_value(a, l, mid);
    right = get_value(a, mid+1, r); 
    // Finding the maximum in the array
     
    if (left.min < right.min)
     {  
     result.min = left.min;
     }
    else
     {
       result.min = right.min;
     } 
    // Finding the minimum in the array
    if (left.max > right.max)
       {
         result.max = left.max;
       }
    else
      { 
      result.max = right.max;
      }
     return result; 
    }


int main()
{
  int a[100];
  int n,i;
  Value r;
  scanf("%d",&n); //size of array
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  } // Inserting elements in the array
    r = get_value(a,0,n-1);
     
    printf("%d\n", r.max);
    printf("%d\n", r.min);
     
    return 0;
  
}

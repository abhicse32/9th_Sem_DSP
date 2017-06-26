/*AIM OF PROGRAM: To find the minimum and maximum alement of an array, given the size of the array and its elements.

DATE: 8 AUG 2016
AUTHOR: GIRIDHAR S*/


#include<stdio.h>

int main(){
  int input_array[100];   //array to store input elements

  int n;                  //size of input array
 
  scanf("%d",&n);

  int i;
  for(i=0;i<n;i++){
    scanf("%d",&input_array[i]);
  }
                      //reads the input array

  
  if(n==0){
     return 1;
  }

  int max=input_array[0];
  int min=input_array[0];
  
  if(n==1){
    printf("%d %d",min,max);
    return 1;
  }


  for(i=1;i<n;i+=2){

    /*CONCEPT: Out of any two adjacent elements, the larger has a chance of being the maximum, but not the minimum
Similarly, the smaller of the two can only be the minimum, never the maximum. 
So adjacent elements are compared, and then correspondingly one or the other is compared with min or max.*/

    if(input_array[i]>input_array[i-1]) {      

      if(max<input_array[i])
	max=input_array[i];
      if(min>input_array[i-1])
	min=input_array[i-1];

    }

    else {      

      if(max<input_array[i-1])
	max=input_array[i-1];
      if(min>input_array[i])
	min=input_array[i];

    }
    

  }

  /*In case the array has odd elements, the entire array is not broken into pairs. So the last element is tested 
seperately.*/
  if(n%2==1){
    if (max<input_array[n-1])
      max=input_array[n-1];
    else if (min>input_array[n-1])
      min=input_array[n-1];
  }
  
  
  printf("%d %d",min,max);



}

    
  
  

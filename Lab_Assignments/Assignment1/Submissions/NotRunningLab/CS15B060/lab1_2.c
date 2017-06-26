#include<stdio.h>
  void main()                         //main function
{   int *arr,*arr1,*arr2,n,i;         //arr-dynamically allocated original array
    int count1,count2;                //arr1-array for storing elements that have won 1st round
    count1=count2=0;                      //arr2-array for storing elements that have lost 1st round(tournament data structures)
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));         //dynamic allocation of arrays using malloc
    arr1=(int*)malloc((n/2 +1)*sizeof(int));
    arr2=(int*)malloc((n/2+1)*sizeof(int));
     for(i=0;i<n;i++)                        //accepting elements of array
{      scanf("%d",arr+i);
}
         if(n%2==0)                          //if number is even task becomes easier
{         for(i=0;i<n-1;i+=2)
  {         if(arr[i]>arr[i+1])                //loop that finds which element wins and loses in round 1
    {         arr1[count1++]=arr[i];
              arr2[count2++]=arr[i+1];          
     }
             else
     {       arr1[count1++]=arr[i+1];
             arr2[count2++]=arr[i]; 
     }
}
}


        else                                   // if num is odd then take last element as both winner and loser
 {      for(i=0;i<n-2;i+=2)
  {        if(arr[i]>arr[i+1])                  //loop that finds which element wins and loses in round 1
    {         arr1[count1++]=arr[i];
              arr2[count2++]=arr[i+1]; 
     }
           else
     {      arr1[count1++]=arr[i+1];
            arr2[count2++]=arr[i]; 
     }
  }
        arr1[count1++]=arr[n-1];                //putting last element in case of odd n to be both winner and loser
        arr2[count2++]=arr[n-1];

}
   int max=arr1[0];                            //finding max of winners
  for(i=1;i<count1;i++)
  { if(arr1[i]>max)
     max=arr1[i];
   }
   int min=arr2[0];                            //finding min of losers
  for(i=1;i<count2;i++)
   { if(arr2[i]<min)
     min=arr2[i];
}


 printf("%d %d\n",min,max);
}

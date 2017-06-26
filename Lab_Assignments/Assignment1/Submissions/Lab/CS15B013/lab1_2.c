  ////CS15B013  D.MALLIKARJUNA 8-8-16  max and min finding


#include<stdio.h>

int main()
{ int count,i,i1,i2,min,max;
  scanf("%d",&count);

  int array[100];

  for(i=0;i<count;i++)
     {
      scanf("%d",&array[i]);              //intialisation

     }
      
     if(count==1)
        {printf("%d %d",array[0],array[0]);return 0;}

       if(array[0]>=array[1])
         {max=array[0];min=array[1];}
       else
          {max=array[1];min=array[0];}
                

      if(count%2==0) 
       {for(i1=2;i1<count;i1=i1+2)
          {
           if(array[i1]<=array[i1+1])   //comparing consecutive values
             {
               if(array[i1]<min)
                 min=array[i1];
               if(array[i1+1]>max)
                 max=array[i1+1];
              }
            else
             {
               if(array[i1+1]<min)
                 min=array[i1+1];
               if(array[i1]>max)
                 max=array[i1];
              }
           }
        
        }
      else
         {for(i1=2;i1<count-1;i1=i1+2)
          {
           if(array[i1]<=array[i1+1])
             {
               if(array[i1]<min)
                 min=array[i1];
               if(array[i1+1]>max)
                 max=array[i1+1];
              }
            else
             {
               if(array[i1+1]<min)
                 min=array[i1+1];
               if(array[i1]>max)
                 max=array[i1];
              }
           }
          
          if(max<array[count-1])
             max=array[count-1];
          if(min>array[count-1])
             min=array[count-1];
        }


 printf("%d %d\n",min,max);           //printing values

return 0;
}

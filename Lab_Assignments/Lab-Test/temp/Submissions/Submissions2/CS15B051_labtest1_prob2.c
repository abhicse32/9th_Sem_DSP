#include <stdio.h>
#include<stdlib.h>

#define MAX_SIZE 32

char store[MAX_SIZE];
int tos1, tos2;

void printStack ( )
{
   int i;

   for (i=0; i<MAX_SIZE; ++i) printf("%c",store[i]);
   printf("\n");
}

// COMPLETE THE FOLLOWING (initStack, pushStack and popStack) FUNCTIONS
void initStack ( int option )
{
   int i;

   if (option == 0) { 
     tos1=-1;
     tos2=0;
      // for odd-even strategy
      // Write C-code Here
   }
   else {
      tos1=-1;
     tos2=MAX_SIZE; 
      // for colliding strategy
      // Write C-code Here
   }
   for (i=0; i<MAX_SIZE; ++i) store[i] = '_';
}

void pushStack ( int which , char what , int option )
{
   if (option == 0) { 
    if(which==1)
    { 
       if(tos1==MAX_SIZE-2)
         {
            printf("Error: Overflow in Stack 1."); return;
         }
      
       if(tos1==-1) 
       {
         store[0]=what;
         tos1=tos1+2;
 return;
       }   
       store[tos1+1]=what;
       tos1=tos1+2;
    /*   else
       {
          int i=0;
          while(i<MAX_SIZE)
          {
            if(store[i]==NULL)
            {
               store[i]=what;
               return;
            }
             i=i+2;
          } */
        
       }
      }
     if(which==2)
     { 
        if(tos2==MAX_SIZE-1)
         {
            printf("Error: Overflow in Stack 2."); return;
         }
       if(tos2==0) 
       {
         store[1]=what;
         tos2=tos2+2;
return;
       }   
       store[tos2+1]=what;
      tos2=tos2+2;
       /*if(store[1]==NULL) 
       {
         store[1]=what;
       }   
       else
       {
          int i=1;
          while(i<MAX_SIZE)
          {
            if(store[i]==NULL)
            {
               store[i]=what;
               return;
            }
             i=i+2;
          }*/
         
      
       }
   //for odd-even strategy
      // Write C-code Here
   else { 
  
     if(which==1)
     {
       if(tos1>=MAX_SIZE/2)
        {
             printf("Error: Overflow in Stack 1."); return;
        }
        if(tos1==-1) 
       {
         store[0]=what;
         tos1++;
         return;
       } 
       store[tos1+1]=what;
       tos1++ ; 
       /*else
       {
          int i=0;
          while(i<MAX_SIZE/2)
          {
            if(store[i]==NULL)
            {
               store[i]=what;
               return;
            }
             i++;
          }
      
     }*/
        
}
     if(which==2)
      {
         if( tos2<MAX_SIZE/2)
         {
             printf("Error: Overflow in Stack 2."); return;
         }
         if(tos2==MAX_SIZE)
           {
             store[MAX_SIZE-1]=what;
             tos2--;
             return;
           }
         store[tos2-1]=what;
         tos2--;
         
        /*else
       {
          int i=MAX_SIZE-1;
          while(i>=MAX_SIZE/2)
          {
            if(store[i]==NULL)
            {
               store[i]=what;
               return;
            }
             i--;
          }
       
     }*/
    
    // for colliding strategy
      // Write C-code Here
   }
}
}
void popStack ( int which , int option )
{
   if (option == 0) {
    if(which==1)
    { 
       if(tos1==-1) 
       {
         printf("Underflow in Stack 1"); return;
       } 
       else
       store[tos1]==0;
         tos1--;
      /* else
       {
          int i=0;
          while(i<MAX_SIZE)
          {
            if(store[i]==NULL)
            {
               store[i-2]==NULL;     return;
            }
             i=i+2;
          }
      
       }*/
     if(which==2)
     { 
       if(tos2==0) 
       {
         printf("Underflow in Stack 2"); return;
       }
         store[tos2]==0;
         tos2--; 
      /* else
       {
          int i=1;
          while(i<MAX_SIZE)
          {
            if(store[i]==NULL)
            {
                store[i-2]==NULL; 
               return;
            }
             i=i+2;
          }
      
       }*/
    } //for odd-even strategy
      // Write C-code Here
   }
   else { 
      if(which==1)
    { 
       if(tos1==-1) 
       {
         printf("Underflow in Stack 1"); return;
       }  
        store[tos1]==0;
         tos1--;
        
       /*else
       {
          int i=0;
          while(i<MAX_SIZE/2)
          {
            if(store[i]==NULL)
            {
               store[i-1]==NULL;     return;
            }
             i++;
          }
      
       }*/
     if(which==2)
     { 
       if(tos2==MAX_SIZE/2-1) 
       {
         printf("Underflow in Stack 2"); return;
       }  
       store[tos2]=0;
       tos2++; 
       /*else
       {
          int i=MAX_SIZE-1;
          while(i>=MAX_SIZE/2)
          {
            if(store[i]==NULL)
            {
                store[i+1]==NULL; 
               return;
            }
             i--;
          }
      
       }*/
    } // for colliding strategy
      // Write C-code Here
   }
}
}
}
int main ()
{
   int i, option, which, action;
   char what;

   srand((unsigned int)time(NULL));

   printf("Enter strategy -- 0 (odd-even) or 1 (colliding) : ");
   scanf("%d",&option);
   initStack(option);

   i = 0;
   while (1) {
      ++i;
      printf("Iteration %3d : ", i); fflush(stdout);

      /* Initially make push. Then make push twice as likely as pop. */
      if (i <= 8) action = 1; else action = rand() % 3;

      /* Make Stack 1 twice more active than Stack 2 */
      which = (rand() % 3) ? 1 : 2;

      if (action) { /* Push */
         what = ((which == 1) ? 'a' : 'A') + (rand() % 26);
         printf("Push %c in stack %d. New stack : ",what,which); fflush(stdout);
         pushStack(which,what,option);
      } else {      /* Pop */
         printf("Pop    in stack %d. New stack : ",which); fflush(stdout);
         popStack(which,option);
      }
      printStack();
   }
   return(0);
}

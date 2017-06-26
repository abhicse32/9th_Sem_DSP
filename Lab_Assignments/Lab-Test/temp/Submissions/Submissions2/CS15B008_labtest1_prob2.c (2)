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

   if (option == 0) { // for odd-even strategy
      // Write C-code Here
	int store[MAX_SIZE];
	
	
   }
   else { // for colliding strategy
      // Write C-code Here
	int store[MAX_SIZE];
   }
   for (i=0; i<MAX_SIZE; ++i) store[i] = '_';
}

void pushStack ( int which , char what , int option )
{
   int s3 = 0;
   int s4 = MAX_SIZE - 1;
   if (option == 0) { //for odd-even strategy
      // Write C-code Here
      static int s1 = 0;
      static int s2 = 1;
	if(which == 1)
	 {
          if(s1 > 31)
           {
            printf("Error: Overflow in Stack 1.\n");
            exit(0);
           }
          else
          {
          store[s1] = what;
          s1 = s1 + 2;
          }
	 }
        if(which ==2)
	{
         if(s1 > 32)
           {
            printf("Error: Overflow in Stack 2.\n");
            exit(0);
           }
          else
          {
	 store[s2] = what;
	 s2 = s2 + 2;
          }
	}
	
   }
   
   else { // for colliding strategy
      // Write C-code Here
       	
          if(which == 1)
	   {
            while(store[s3] != '_' && s3 != s4)
            {
             s3 = s3+1;
            }
            if(s3 == s4)
             {
              printf("Error: Overflow in Stack 1.\n");
              exit(0);
             } 
            store[s3] = what;
            
           }
          if(which == 2)
           {
            while(store[s4] != '_' && s3 != s4)
            {
             s4 = s4 - 1;
            }
            if(s3 == s4)
             {
              printf("Error: Overflow in Stack 2.\n");
              exit(0);
             } 
            store[s4] = what;
            
           }
             
   }
}

void popStack ( int which , int option )
{
   if (option == 0) { //for odd-even strategy
      // Write C-code Here
      if(which == 1)
      {
       static int s5 = 0;
       while(store[s5] != '_' && s5 <=MAX_SIZE -1)
       {
        s5 = s5 + 2;
       }
       if(s5 == 0)
        {
         printf("Error: Underflow in Stack 1.\n");
         exit(0); 
        }
       store[s5 - 2] = '_';
      }
     if(which == 2)
      {
       static int s6 = 1;
       while(store[s6] != '_' && s6 <=MAX_SIZE)
       {
        s6 = s6 + 2;
       }
       if(s6 == 1)
        {
         printf("Error: Underflow in Stack 1.");
         exit(0); 
        }
       store[s6 - 2] = '_';
      }
    }
   else { // for colliding strategy
      // Write C-code Here
      static int s7 = 0;
      static int s8 = MAX_SIZE;
      if(which == 1)
      {
       
       while(store[s7] != '_' && s7 < MAX_SIZE && s7 <s8)
       {
        s7 = s7 +1;
       }
       if(s7 == 0 || s7 >MAX_SIZE)
        {
         printf("Error: Underflow in Stack1.\n");
         exit(0);
        }
       store[s7 -1] = '_';
      }
     if(which == 2)
      {
      int s8 = MAX_SIZE-1;
       while(store[s8] != '_' && s7 != s8 )
       {
        s8 = s8 - 1;
       }
       if(s8 == MAX_SIZE-1)
        {
         printf("Error: Underflow in Stack1.\n");
         exit(0);
        }
       store[s8 + 1] = '_';
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

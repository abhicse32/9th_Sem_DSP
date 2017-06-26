#include <stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 50

char store[MAX_SIZE];
int tos1, tos2;
int s1 = 0;
int s2 = 1;
int s3 = 0;
int s4 = MAX_SIZE - 1;

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
      //static int s1 = 0;
      //  static int s2 = 1;
	
	
   }
   else { // for colliding strategy
      // Write C-code Here
	int store[MAX_SIZE];
	//int s3 = 0;
        //int s4 = MAX_SIZE - 1;
	
   }
   for (i=0; i<MAX_SIZE; ++i) store[i] = '_';
}

void pushStack ( int which , char what , int option )
{
  // int s3 = 0;
  // int s4 = MAX_SIZE - 1;
   if (option == 0) { //for odd-even strategy
      // Write C-code Here
     // static int s1 = 0;
     // static int s2 = 1;
	if(which == 1)
	 {
          if(s1 > (MAX_SIZE-1))
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
         if(s2> (MAX_SIZE-1)) //changed 32 to 31
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
           /* while(store[s3] != '_' && s3 != s4)
            {
             s3 = s3+1;
            } */
            if(s3 > s4)     //changed == to >
             {
              printf("Error: Overflow in Stack 1.\n");
              exit(0);
             }
             else{ 
            store[s3] = what;
 	    s3 = s3 + 1;
            }
           }
          if(which == 2)
           {
           /* while(store[s4] != '_' && s3 != s4)
            {
             s4 = s4 - 1;
            } */
            if(s3 > s4)          //changed == to >
             {
              printf("Error: Overflow in Stack 2.\n");
              exit(0);
             }
            else
            { 
              store[s4] = what;
	      s4 = s4 -1;
            }
           }
             
   }
}

void popStack ( int which , int option )
{
   if (option == 0) { //for odd-even strategy
      // Write C-code Here
      if(which == 1)
      {
 /*      static int s5 = 0;
       while(store[s5] != '_' && s5 <=MAX_SIZE -1)
       {
        s5 = s5 + 2;
       } */
       if(s1 == 0)
        {
         printf("Error: Underflow in Stack 1.\n");
         exit(0); 
        }
       store[s1 - 2] = '_';
       s1 = s1 - 2;
      }
     if(which == 2)
      {
  /*     static int s6 = 1;
       while(store[s6] != '_' && s6 <=MAX_SIZE)
       {
        s6 = s6 + 2;
       }  */
       if(s2 == 1)
        {
         printf("Error: Underflow in Stack 2.");
         exit(0); 
        }
       store[s2 - 2] = '_';
       s2 = s2-2;
      }
   } 
   else { // for colliding strategy
      // Write C-code Here
    //   static int s7 = 0;
    //  static int s8 = MAX_SIZE;
      if(which == 1)
   {
         
    /*   while(store[s7] != '_' && s7 < MAX_SIZE && s7 <s8)
       {
        s7 = s7 +1;
       } */
       if(s3 == 0 || s4 < 0)
        {
         printf("Error: Underflow in Stack 1.\n");
         exit(0);
        }
       store[s3 -1] = '_';
	s3 = s3 -1;
      }
     if(which == 2)
      {
  /*    int s8 = MAX_SIZE-1;
       while(store[s8] != '_' && s7 != s8 )
       {
        s8 = s8 - 1;
       } */
       if(s4 == MAX_SIZE-1)
        {
         printf("Error: Underflow in Stack 2.\n");
         exit(0);
        }
       store[s4 + 1] = '_';
       s4 = s4+1;
      }
      
      }
}

int main (){
     int i, option, which, action;
     char what;

     srand((unsigned int)time(NULL));

     printf("Enter strategy -- 0 (odd-even) or 1 (colliding) : ");
     scanf("%d",&option);
     printf("%d\n",option);
     initStack(option);

     i = 0;
     int times,letter;
     scanf("%d",&times);
     while (i<times) {
        ++i;
        printf("Iteration %3d : ", i); fflush(stdout);

        /* Initially make push. Then make push twice as likely as pop. */
        // if (i <= 8) action = 1;
        // else action = rand() % 3;
        scanf("%d",&action);

        /* Make Stack 1 twice more active than Stack 2 */
        // which = (rand() % 3) ? 1 : 2;
        scanf("%d",&which);
        scanf("%d",&letter);
        if (action) { /* Push */
           what = ((which == 1) ? 'a' : 'A') + letter;
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
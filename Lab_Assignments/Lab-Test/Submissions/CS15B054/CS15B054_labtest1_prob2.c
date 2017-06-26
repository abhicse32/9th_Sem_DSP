#include <stdio.h>
#include<stdlib.h>

#define MAX_SIZE 50

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
      int A[MAX_SIZE];
      
   }
   else { // for colliding strategy
      // Write C-code Here
      
   }
   for (i=0; i<MAX_SIZE; ++i) store[i] = '_';
}

void pushStack ( int which , char what , int option )
{
   if (option == 0) { //for odd-even strategy
      // Write C-code Here
      int A1[]=(int*)malloc(sizeof(int));
      int A2[]=(int*)malloc(sizeof(int));
      int i =0;
      while(A1[i] != '_' && i<32)
      {
         i =i+2;
      }
      if(i == 32)
      {
         printf("Overflow-Error");
         exit(0);
      }
      else
      {
           A1[i]==what;
      }
      i = 1;
      while(A2[i] != '_' && i<32)
      {
         i =i+2)
      }
      if(i<32)
      {
          A2[i] = which;
      }
      else
      {
          printf("Overflow-Error");
          exit(0);
      }
      for(i =0;i<32;i++)
      {
         store[i] =A2[i]);
      }
   }
   else { // for colliding strategy
      // Write C-code Here
      int i =0;
      if(which = 1)
      {
          while(A1[i] != '_' && i<32)
          {
              i++;
          }
          if (A1[i] == '_')
          {
             A1[i] = what;
          }
      }
      else
      {
          i =31
          while(A2[i] != '_' && i>0)
          {
              i--;
          }
          if (A2[i] == '_')
          {
             A2[i] = what;
          }
      }
      for(i= 0;i<32;i++)
      {
        if (which = 1) store[i] = A1[i];
        else  store[i]= A2[i];
      }
   }
}

void popStack ( int which , int option )
{
   if (option == 0) { //for odd-even strategy
      // Write C-code Here
      int j=0
      if(which == 1)
      {
          while(A1[j+2] != '_',j<32)
          {
             j= j+2;
          }
          if(j<32)
          {
             A1[j] == '_';
          } 
      }
      j = 1;
      else
      {
          while(A1[j+2] != '_',j<32)
          {
             j = j+2;
          }
          if(j<32)
          {
              A1[j] == '_';
          }
      }
   }
   else { // for colliding strategy
      // Write C-code Here
      j = 0;
      if(which == 2)
      {
          while(A2[j+2] != '_',j<32)
          {
             j= j+2;
          }
          if(j<32)
          {
             A2[j] == '_';
          } 
      }
      j = 1;
      else
      {
          while(A2[j+2] != '_',j<32)
          {
             j = j+2;
          }
          if(j<32)
          {
              A2[j] == '_';
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

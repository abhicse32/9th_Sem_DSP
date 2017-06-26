#include <stdio.h>
#include<stdlib.h>

#define MAX_SIZE 32

char store[MAX_SIZE];
int tos1, tos2;

void initStack ( int option )
{
   int i;

   if (option == 0) { tos1 = -2; tos2 = -1; }
   else { tos1 = -1; tos2 = MAX_SIZE; }
   for (i=0; i<MAX_SIZE; ++i) store[i] = '_';
}

void printStack ( )
{
   int i;

   for (i=0; i<MAX_SIZE; ++i) printf("%c",store[i]);
   printf("\n");
}

void pushStack ( int which , char what , int option )
{
   if (option == 0) {
      if (which == 1) {
         tos1 += 2;
         if (tos1 >= MAX_SIZE) {
            fprintf(stderr,"Error: Overflow in Stack 1.\n");
            exit(1);
         } else store[tos1] = what;
      } else if (which == 2) {
         tos2 += 2;
         if (tos2 >= MAX_SIZE) {
            fprintf(stderr,"Error: Overflow in Stack 2.\n");
            exit(1);
         } else store[tos2] = what;
      } else {
         fprintf(stderr,"Error: Undefined stack identifier.\n");
         exit(1);
      }
   } else {
      if (which == 1) {
         ++tos1;
         if (tos1 >= tos2) {
            fprintf(stderr,"Error: Overflow in stack.\n");
            exit(1);
         } else store[tos1] = what;
      } else if (which == 2) {
         --tos2;
         if (tos1 >= tos2) {
            fprintf(stderr,"Error: Overflow in stack.\n");
            exit(1);
         } else store[tos2] = what;
      } else {
         fprintf(stderr,"Error: Undefined stack identifier.\n");
         exit(1);
      }
   }
}

void popStack ( int which , int option )
{
   if (option == 0) {
      if (which == 1) {
         if (tos1 < 0) {
            fprintf(stderr,"Error: Underflow in Stack 1.\n");
            exit(1);
         } else {
            store[tos1] = '_';
            tos1 -= 2;
         }
      } else if (which == 2) {
         if (tos2 < 0) {
            fprintf(stderr,"Error: Underflow in Stack 2.\n");
            exit(1);
         } else {
            store[tos2] = '_';
            tos2 -= 2;
         }
      } else {
         fprintf(stderr,"Error: Undefined stack identifier.\n");
         exit(1);
      }
   } else {
      if (which == 1) {
         if (tos1 < 0) {
            fprintf(stderr,"Error: Underflow in Stack 1.\n");
            exit(1);
         } else {
            store[tos1] = '_';
            --tos1;
         }
      } else if (which == 2) {
         if (tos2 >= MAX_SIZE) {
            fprintf(stderr,"Error: Underflow in Stack 2.\n");
            exit(1);
         } else {
            store[tos2] = '_';
            ++tos2;
         }
      } else {
         fprintf(stderr,"Error: Undefined stack identifier.\n");
         exit(1);
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
   int times,letter;
   scanf("%d",&times);
   while (i<times) {
      ++i;
      printf("Iteration %3d : ", i); fflush(stdout);

      /* Initially make push. Then make push twice as likely as pop. */
      // if (i <= 8) action = 1;
      // else action = rand() % 3;
      printf("%d",&action);

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

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
      tos1 = -2;
      tos2 = -1;
   }
   else { // for colliding strategy
      // Write C-code Here
      tos1 = -1;
      tos2  = MAX_SIZE;
   }
   for (i=0; i<MAX_SIZE; ++i) store[i] = '_';
}

void pushStack ( int which , char what , int option )
{
   if (option == 0) { //for odd-even strategy
      // Write C-code Here
      if(which == 1){
        if(tos1 != MAX_SIZE -2){
            tos1 = tos1 + 2;
            store[tos1] = what;
        }
        else {
            printf("Error: Overflow in Stack 1.\n");
            exit(0);
        }
      }
      else {
         if(tos2 != MAX_SIZE - 1){
            tos2 = tos2 + 2;
            store[tos2] = what;
        }
        else {
            printf("Error: Overflow in Stack 2.\n");
            exit(0);
        }     
      }
   }
   else { // for colliding strategy
      // Write C-code Here
      if(which == 1){
        if(tos1 != tos2 - 1){
            tos1 = tos1 + 1;
            store[tos1] = what;
        }
        else {
            printf("Error: Overflow in stack.\n");
            exit(0);
        }
      }
      else {
         if(tos2 != tos1 + 1){
            tos2 = tos2 - 1;
            store[tos2] = what;
        }
        else {
            printf("Error: Overflow in stack.\n");
            exit(0);
        }     
      }
   }
}

void popStack ( int which , int option )
{
   if (option == 0) { //for odd-even strategy
      // Write C-code Here
      if(which == 1){
        if(tos1 != -2){
            store[tos1] = '_';
            tos1 = tos1 - 2;
        }
        else {
            printf("Error: Underflow in Stack 1.\n");
            exit(0);
        }
      }
      else {
         if(tos2 != -1){
            store[tos2] = '_';
            tos2 = tos2 - 2;
        }
        else {
            printf("Error: Underflow in Stack 2.\n");
            exit(0);
        }     
      }
   }
   else { // for colliding strategy
      // Write C-code Here
      if(which == 1){
        if(tos1 != -1){
            store[tos1] = '_';
            tos1 = tos1 - 1;
        }
        else {
            printf("Error: Underflow in Stack 1.\n");
            exit(0);
        }
      }
      else {
         if(tos2 != MAX_SIZE){
            store[tos2] = '_';
            tos2 = tos2 + 1;
        }
        else {
            printf("Error: Underflow in Stack 2.\n");
            exit(0);
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

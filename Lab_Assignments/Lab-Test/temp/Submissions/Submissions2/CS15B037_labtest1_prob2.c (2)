/*
*On 19th September 2016
*Written by Teratipally Srikar,CS15B037
*This program manipulates 2 stacks
*in a same array in 2 diff ways
*/

#include <stdio.h>  /*Including the required header files*/
#include<stdlib.h>

#define MAX_SIZE 32

char store[MAX_SIZE];   /*Array for storing the stacks*/
int tos1, tos2;         /*Indexes for locating the top element of stack1,stack2*/

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

   if (option == 0) {                   /*For odd-even strategy*/
                        tos1 = -2;      /*This is for locating in even elements of array*/
                        tos2 = -1;      /*This is for locating in odd elements of array*/
                    }
   else {                               /*For colloding startegy*/
            tos1 = -1;                  /*Since the pointer should out of the array in the beginning*/
            tos2 = MAX_SIZE;            /*This is right pointer and starts from the out of array*/
        }
   for (i=0; i<MAX_SIZE; ++i) store[i] = '_';
}

void pushStack ( int which , char what , int option )   /*This function pushes an element into given stack*/
{
   if (option == 0) { 
                        if(which==1)    {
                                            if(tos1==(MAX_SIZE-2))  {   /*Maximum possible even indix is MAX_SIZE-2 so it is an error*/
                                                                        printf("Error: Overflow in Stack 1.\n");
                                                                        exit(0);
                                                                    }
                                            tos1 = tos1+2;          /*For adding into first, we can simply add +2 and then store it*/
                                            store[tos1] = what;
                                        }

                        else    {
                                    if(tos2==(MAX_SIZE-1))  {       /*Maximum possible even indix is MAX_SIZE-1 so it is an error*/
                                                               printf("Error: Overflow in Stack 2.\n");
                                                               exit(0);
                                                            }
                                    tos2 = tos2+2;
                                    store[tos2] = what;         /*For adding into second, we can simply add +2 and then store it*/
                                }
                    }

   else { 

            if(tos2-tos1==1) {              /*Since while adding if both the pointers are just beside then it is filled*/
                                printf("Error: Overflow in stack.\n");
                                exit(0);
                             }
            if(which==1)    {               /*For adding into first, we can simply add +1 and then store it*/
                                tos1 = tos1+1;
                                store[tos1] = what;
                            }

            else    {                       /*For adding into second, we can simply add -1 and then store it*/
                        tos2 = tos2-1;
                        store[tos2] = what;
                    }
        }
}

void popStack ( int which , int option )    /*This function removes an element in the given stack*/
{
   if (option == 0) { 
                        if(which==1) {
                                        if(tos1==(-2))  {                           /*Since if there are no elements in the stack1, tos1 will be -2*/
                                                            printf("Underflow in Stack 1.\n");
                                                            exit(0);
                                                        }

                                        else    {                                   
                                                    store[tos1] = '_';
                                                    tos1 = tos1-2;  /*For poping into 1st, we can simply add -2*/
                                                }
                                    }

                        else    {
                                    if(tos2==(-1))  {       /*Since if there are no elements in the stack2, tos2 will be -1*/
                                                        printf("Underflow in Stack 2.\n");
                                                        exit(0);
                                                    }

                                    else {
                                            store[tos2] = '_';
                                            tos2 = tos2 - 2;    /*For poping into 2nd, we can simply add -2*/
                                         }
                                }
                    }

   else {
            if(which==1)    {
                                if(tos1==(-1))  {   /*Since if there are no elements in the stack1, tos1 will be -1*/
                                                    printf("Underflow in Stack 1.\n");
                                                    exit(0);
                                                }
                                else {
                                        store[tos1] = '_';
                                        tos1 = tos1-1;      /*For poping into 1st, we can simply add -1*/
                                     }
                            }

            else    {
                        if(tos2==(MAX_SIZE))    {   /*Since if there are no elements in the stack2, tos1 will be MAX_SCORE*/
                                                    printf("Underflow in Stack 2.\n");
                                                    exit(0);
                                                }
                        else    {
                                    store[tos2] = '_';
                                    tos2 = tos2+1;  /*For poping into 2nd, we can simply add +1*/
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

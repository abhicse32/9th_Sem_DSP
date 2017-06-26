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
   	tos1=-2;	//first index
   	tos2=-1;	//second index
         }
   else { // for colliding strategy
   	tos1=-1;	//first index
   	tos2=MAX_SIZE ; //last index
         }
   for (i=0; i<MAX_SIZE; ++i) store[i] = '_';
}

//to push an element
void pushStack ( int which , char what , int option )
{
   if (option == 0) { //for odd-even strategy
      
        if(which==1)	//first stack
        {
        	tos1=tos1+2;	//increment the pointer by 2 
        	if(tos1<32)	//checks the index of the first pointer
        	{
       		store[tos1]=what;	//inputs the character	
        	}
        	else
        	{
        		printf("Error: Overflow in stack 1\n");
        		exit(0);
        	}
        }
        
        else if(which==2)	//second stack
        {
        	tos2=tos2+2;	//increment the pointer by 2  
        	if(tos2<32)	//checks the index of the second pointer
        	{
       		store[tos2]=what;	//inputs the character	
		    	
        	}
        	else
        	{
        		printf("Error: Overflow in stack 2\n");
        		exit(0);
        	}
        }
        
      
   }
   else { // for colliding strategy
      
      
      if(which==1)	//first stack
        {
        
        	tos1++;	//increments the pointer by 1 
        	if(tos1<tos2)	//checks if index of first pointer is before the second
        	{
       		store[tos1]=what;	//inputs the character	
		   	
        	}
        	else
        	{
        		printf("Error: Overflow in stack 1\n");
        		exit(0);
        	}
        }
        
        else if(which==2)	//second stack
        {
        	tos2--;	//decrements the second pointer    
        	if(tos1<tos2)	//checks if the index of the second pointer is one more than the first
        	{
       		store[tos2]=what;	//inputs the character	
			
        	}
        	else
        	{
        		printf("Error: Overflow in stack 2\n");
        		exit(0);
        	}
        }
   }
}

//to pop an element
void popStack ( int which , int option )
{
   if (option == 0) { //for odd-even strategy
   
       if(which==1)	//first stack
        {
        	if(tos1>=0)	//checks the index of the first pointer
        	{	
        	store[tos1]='_';	
		tos1=tos1-2;	 	//decrement the pointer    	
        	}
        	else
        	{
        		printf("Error: Underflow in stack 1\n");
        		exit(0);
        	}
        }
        
        else if(which==2)	//second stack
        {
        	if(tos2>=0)	//checks the index of the second pointer
        	{
        	store[tos2]='_';
       		tos2=tos2-2;   	//decrements the pointer
        	}
        	else
        	{
        		printf("Error: Underflow in stack 2\n");
        		exit(0);
        	}
        }
   }
   else { // for colliding strategy
      if(which==1)	//first stack
        {
        	if(tos1>=0)	//checks the index of the first pointer
        	{	
        	store[tos1]='_';
		tos1--;	 	//decrement the pointer    	
        	}
        	else
        	{
        		printf("Error: Underflow in stack 1\n");
        		exit(0);
        	}
        }
        
        else if(which==2)	//second stack
        {
        	if(tos2 <MAX_SIZE)	//checks the index of the second pointer
        	{
        	store[tos2]='_';
       		tos2++;   	//increments the pointer
        	}
        	else
        	{
        		printf("Error: Underflow in stack 2\n");
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

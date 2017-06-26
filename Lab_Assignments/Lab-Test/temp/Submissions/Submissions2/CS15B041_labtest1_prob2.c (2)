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
if (option == 0) 
	{
	int i;	
	tos1=0;
	tos2=1;	
	

}
else
	{
		tos1=0;
		tos2=31;
	
		
   
		
   }
   for (i=0; i<MAX_SIZE; ++i) store[i] = '_';
}

void pushStack ( int which , char what , int option )
{
 if (option == 0) 
	{
		if(which== 1)
		{
			if(tos1==0)
			{
				store[0]=what;
				tos1=tos1+2;
			}
			else if(tos1==30)
			{
				printf("Overflow in Stack 1.");
				return ;
			}
			else 
			{
				store[tos1]= what;
				tos1=tos1+2;
			}
		}

		else
		{
			if(tos2==1)
			{
				store[1]=what;
				tos2=tos2+2;
			}
			else if(tos2==31)
			{
				printf("Overflow in Stack 2.");
				return ;
			}
			else
			{
				store[tos2]=what;
				tos2=tos2+2;

			}
		}
	}



  else
 {

	if(which== 1)
	{
		if(tos1+1 <tos2 && tos1 <31 )
		{
		store[tos1+1]=what;
		tos1++;
			
		}
		 if(tos1 == tos2)
		{
		printf("Overflow in Stack 1.");
		return;
		}
	}
	if(which == 2)
	{
		if(tos2>tos1 && tos2>0)
		{
		store[tos2-1]=what;
		tos2--;
		}
		if(tos1==tos2)
		{
		printf("Overflow in Stack 2.");
		return;
		}
	}
}
}	



























 
///////////////////////////////////////////////////////
void popStack ( int which , int option )
{
 if (option == 0) 
	{

		if(which == 1)
		{
			if(tos1 < 0 )
			{
				printf("Underflow in Stack 1.");
				return;
			}
			else
			{
				
				store[tos1]='_';
				tos1=tos1-2;
			}
		}
		else
		{
			if(tos2	<1)
			{
				printf("Underflow in Stack 2.");
				return;
			}
			else
			{
				
				store[tos2]='_';
				tos2=tos2-2;
			}
		}
	}


  else 
{
	
	if(which == 1)
	{
		if(tos1 == 0)
		{
			printf("Underflow in Stack 1.");
			return;
		}
		else
		{
			char x;
			store[tos1]='_';
			tos1--;
		}
	}
	else
	{
		if(tos2==31)
		{
			
			printf("Underflow in Stack 2.");
			return;
		}
		else
		{
			char x;
			store[tos2]='_';
			tos2--;
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

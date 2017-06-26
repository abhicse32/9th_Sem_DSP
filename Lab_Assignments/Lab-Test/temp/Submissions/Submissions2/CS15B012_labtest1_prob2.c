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
   /* here size of stack is zero*/
   int i1 = -1;//tops of stacks
   int i2 = -2;
      // Write C-code Here
   }
   else { // for colliding strategy
      // Write C-code Here
      int i1=-1;
      int i2 =32;//tops of stacks
   }
   for (i=0; i<MAX_SIZE; ++i) store[i] = '_';
}

void pushStack ( int which , char what , int option )
{
   if (option == 0) { //for odd-even strategy
      // Write C-code Here
      if(which==1)
      {
      	int i=0;
      	for(i=0;i<MAX_SIZE;)
      	{
      		if(store[i]!='_')      		
      		{
      		i=i+2;
      		}
      		else
      		{
      		store[i]=what;
      		break;
      		}
      	}
      	if(i==32)
      	{
      	printf("Error: Overflow in Stack %d.\n",which);
      	exit(1);
      	}
      }
      if(which==2)
      {
      	      	int i=1;
      	for(i=1;i<MAX_SIZE;)
      	{
      		if(store[i]!='_')      		
      		{
      		i=i+2;
      		}
      		else
      		{
      		store[i]=what;
      		break;
      		}
      	}
      	if(i==33)
      	{
      	printf("Error: Overflow in Stack %d.\n",which);
      	exit(1);
      	}
      }
      
   }
   else { // for colliding strategy
      // Write C-code Here
            if(which==1)
      {
      	int i=0;
      	for(i=0;i<MAX_SIZE;)
      	{
      		if(store[i]!='_')      		
      		{
      		i=i+1;
      		}
      		else
      		{
      		store[i]=what;
      		break;
      		}
      	}
      	if(i==32)
      	{
      	printf("Error: Overflow in Stack %d.\n",which);
      	exit(1);
      	}
      }
                  if(which==2)
      {
      	int i=31;
      	for(i=31;i>=0;)
      	{
      		if(store[i]!='_')      		
      		{
      		i=i-1;
      		}
      		else
      		{
      		store[i]=what;
      		break;
      		}
      	}
      	if(i==-1)
      	{
      	printf("Error: Overflow in Stack %d.\n",which);
      	exit(1);
      	}
      }
   }
}

void popStack ( int which , int option )
{
   if (option == 0) { //for odd-even strategy
      // Write C-code Here
            if(which==1)
      {
      	int i=0;
      	for(i=0;i<MAX_SIZE;)
      	{
      		if(store[i]=='_')      		
      		{
      		break;
      		}
      		else
      		{
      		i=i+2;
      		}
      		
      	}
      	i = i-2;
      	
      	if(i==-2)
      	{
      	printf("Error: Underflow in Stack %d.\n",which);
      	exit(1);
      	}
      	store[i]='_';
      	
      }
 
            if(which==2)
      {
      	int i=1;
      	for(i=1;i<MAX_SIZE;)
      	{
      		if(store[i]=='_')      		
      		{
      		break;
      		}
      		else
      		{
      		i=i+2;
      		}
      		
      	}
      	i = i-2;
      	if(i==-1)
      	{
      	printf("Error: Underflow in Stack %d.\n",which);
      	exit(1);
      	}
      	
       	store[i]='_';     	
      }      

      
   }
   else { // for colliding strategy
      // Write C-code Here
                  if(which==1)
      {
      	int i=0;
      	for(i=0;i<MAX_SIZE;)
      	{
      		if(store[i]=='_'||store[i]=='A'||store[i]=='B'||store[i]=='C'||store[i]=='D'||store[i]=='E'||store[i]=='F'||store[i]=='G'||store[i]=='H'||store[i]=='I'||store[i]=='J'||store[i]=='K'||store[i]=='L'||store[i]=='M'||store[i]=='N'||store[i]=='O'||store[i]=='P'||store[i]=='Q'||store[i]=='R'||store[i]=='S'||store[i]=='T'||store[i]=='U'||store[i]=='V'||store[i]=='W'||store[i]=='X'||store[i]=='Y'||store[i]=='Z')      		
      		{
      		break;
      		}
      		else
      		{
      		i=i+1;
      		}
      		
      	}
      	i = i-1;
      	if(i==-1)
      	{
      	printf("Error: Underflow in Stack %d.\n",which);
      	exit(1);
      	}
        	store[i]='_';    	
      	
      }
                        if(which==2)
      {
      	int i=31;
      	for(i=31;i>=0;)
      	{
      		if(store[i]=='_'||store[i]=='a'||store[i]=='b'||store[i]=='c'||store[i]=='d'||store[i]=='e'||store[i]=='f'||store[i]=='g'||store[i]=='h'||store[i]=='i'||store[i]=='j'||store[i]=='k'||store[i]=='l'||store[i]=='m'||store[i]=='n'||store[i]=='o'||store[i]=='p'||store[i]=='q'||store[i]=='r'||store[i]=='s'||store[i]=='t'||store[i]=='u'||store[i]=='v'||store[i]=='w'||store[i]=='x'||store[i]=='y'||store[i]=='z')      		
      		{
      		break;
      		}
      		else
      		{
      		i=i-1;
      		}
      		
      	}
      	i = i+1;
      	if(i==32)
      	{
      	printf("Error: Underflow in Stack %d.\n",which);
      	exit(1);
      	}
        	store[i]='_';    	
      	
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

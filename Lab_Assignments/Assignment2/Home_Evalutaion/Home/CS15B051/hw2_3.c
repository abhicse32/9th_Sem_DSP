#include <stdio.h>
int count=0;
int p,q,r;
void towerOfHanoi(int n, char fp, char tp, char ap) //fp is the from peg, tp is to to peg, ap is auxilary peg
{
    if (n == 1)
    {
        
    if(fp=='A')
    { 
      p--;                 //If A or B pr C are from pegs then the value decrements which implies that when we move a disk from peg the number of disks decreases by 1
	} 
    if(fp=='B')
    { 
      q--;
	}
   if(fp=='C')
    { 
      r--;
       } 
    if(tp=='A')
    { 
      p++;              //If A or B pr C are to pegs then the value increments which implies that when we move a disk from peg the number of disks increases by 1
 	}
    if(tp=='B')
    { 
      q++;
	}
   if(tp=='C')
    { 
      r++;
	} 
	
        count++;       //Count counts number of steps
        printf("\n%c -> %c %d %d %d", fp, tp,p,q,r);
        return;
    }
    
   
    towerOfHanoi(n-1, fp, ap, tp);
     if(fp=='A')
    { 
      p--;
	}
    if(fp=='B')
    { 
      q--;
	}
   if(fp=='C')
    { 
      r--;
	} 
	if(tp=='A')
    { 
      p++;
	}
    if(tp=='B')
    { 
      q++;
	}
   if(tp=='C')
    { 
      r++;
	} 
	
     printf("\n%c -> %c %d %d %d", fp, tp,p,q,r);
    towerOfHanoi(n-1, ap, tp, fp);
    count++;
}
 
int main()
{
    int n; // Number of disks
    scanf("%d",&n);
    p=n;                          //p,q,r are the values of the numver of disks in A B anc C
    q=0;
	r=0;
    towerOfHanoi(n, 'A', 'C', 'B'); 
	printf("\n%d",count);// A, B and C are names of pegs
    return 0;
}

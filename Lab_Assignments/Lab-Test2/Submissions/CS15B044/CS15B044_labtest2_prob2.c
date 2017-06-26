#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
   int n1, n2, capacity;
   int *val;
} medHeap;

medHeap insMaxHeap ( medHeap H, int x )
{
   int i, p, t;

   H.val[H.n1] = x;
   i = H.n1;
   while (i > 0) {
      p = (i - 1) / 2;
      if (H.val[p] >= H.val[i]) break;
      t = H.val[p]; H.val[p] = H.val[i]; H.val[i] = t;
      i = p;
   }
   H.n1++;
   return H;
}

medHeap insMinHeap ( medHeap H, int x )
{
   int i, p, t;

   H.val[H.capacity-1-H.n2] = x;
   i = H.n2;
   while (i > 0) {
      p = (i - 1) / 2;
      if (H.val[H.capacity-1-p] <= H.val[H.capacity-1-i]) break;
      t = H.val[H.capacity-1-p];
      H.val[H.capacity-1-p] = H.val[H.capacity-1-i];
      H.val[H.capacity-1-i] = t;
      i = p;
   }
   H.n2++;
   return H;
}

medHeap delMaxHeap ( medHeap H )
{
   int i, l, r, m, t;

   H.n1--; H.val[0] = H.val[H.n1]; i = 0;
   while (i < H.n1) {
      l = 2*i + 1; r = 2*i + 2;
      if (l >= H.n1) break;
      if (l == H.n1 - 1) m = l;
      else m = (H.val[l] >= H.val[r]) ? l : r;
      if (H.val[i] >= H.val[m]) break;
      t = H.val[i]; H.val[i] = H.val[m]; H.val[m] = t;
      i = m;
   }
   return H;
}

medHeap delMinHeap ( medHeap H )
{
   int i, l, r, m, t;

   H.n2--; H.val[H.capacity-1] = H.val[H.capacity-1-H.n2]; i = 0;
   while (i < H.n2) {
      l = 2*i + 1; r = 2*i + 2;
      if (l >= H.n2) break;
      if (l == H.n2 - 1) m = l;
      else m = (H.val[H.capacity-1-l] <= H.val[H.capacity-1-r]) ? l : r;
      if (H.val[H.capacity-1-i] <= H.val[H.capacity-1-m]) break;
      t = H.val[H.capacity-1-i];
      H.val[H.capacity-1-i] = H.val[H.capacity-1-m];
      H.val[H.capacity-1-m] = t;
      i = m;
   }
   return H;
}

// COMPLE THE FOLLOWING FIVE (initMedHeap, getMedian, insMedHeap, delMedHeap
// and medHeapSort) FUNCTIONS
medHeap initMedHeap ( int n )
{
   // Write C-code Here
   medHeap H;
   H.val=(int *)malloc(sizeof(int)*n);
   H.capacity=n;
   H.n1=0;
   H.n2=0;
   return H;
}

int getMedian ( medHeap H )
{
   // Write C-code Here
   if(H.n1==H.n2)
   	return H.val[0];
   return H.val[H.capacity-1];
}

medHeap insMedHeap ( medHeap H, int x )
{
   // Write C-code Here
   						// part of code deleted
   if(H.n1==H.n2)
   {
   	if(x<=getMedian(H))
   	{
   		H=insMaxHeap(H,x);
   		H=insMinHeap(H,H.val[0]);
   		H=delMaxHeap(H);
   	}
   	else
   	{
   		H=insMinHeap(H,x);
   	}
   	return H;
   }
   else if(H.n1==H.n2-1)
   {
   	if(x<=getMedian(H))
   	{
   		H=insMaxHeap(H,x);
   		
   	}
   	else
   	{
   		H=insMinHeap(H,x);
   		H=insMaxHeap(H,H.val[H.capacity-1]);
   		H=delMinHeap(H);
   	}
   	return H;
   }
}

medHeap delMedHeap ( medHeap H )
{
   // Write C-code Here
   if(H.n1==H.n2)
   {
   	H=delMaxHeap(H);
   }
   else if(H.n1==H.n2-1)
   {
   	H=delMinHeap(H);
   }
   return H;      // Inserted now
}

medHeap medHeapSort ( medHeap H )
{
   // Write C-code Here
  	while(H.n2>0)    // Earlier 1 was there
   {
		int temp;
		temp=getMedian(H);
		H=delMedHeap(H);
		if(H.n1==H.n2)
		{
			H.val[H.capacity-1-H.n2]=temp;
		}
		else
		{
			H.val[H.n1]=temp;
		}
   }
}

void printArray ( medHeap H )
{
   int i;

   printf("    ");
   for (i=0; i<H.capacity; ++i) {
      printf("%5d", H.val[i]);
      if (i % 15 == 14) printf("\n    ");
   }
   if (i % 15) printf("\n");
}

int main ( int argc, char *argv[] )
{
   int n, i, x;
   medHeap H;

   scanf("%d", &n);
   H = initMedHeap(n);
   printf("\n+++ MedHeap initialized\n");

   printf("\n+++ Going to insert elements one by one in MedHeap\n");
   for (i=0; i<n; ++i) {
      scanf("%d",&x);
      H = insMedHeap(H,x);
      printf("    Insert(%4d) done. Current median = %4d.\n", x, getMedian(H));
   }

   H = medHeapSort(H);
   printf("\n+++ Median Heap Sort done\n");
   printArray(H);
   
   free(H.val);

   return(0);
}

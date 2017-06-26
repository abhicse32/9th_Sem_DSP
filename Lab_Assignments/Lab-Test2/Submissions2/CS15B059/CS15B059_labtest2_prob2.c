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
	medHeap m;
	m.val=(int *)malloc(sizeof(int)*n);	//to allocate space
	m.n1=0;
	m.n2=0;
	m.capacity = n;
	printf("%d",m.capacity);
	return m;	//to return the medheap created

   // Write C-code Here
}

int getMedian ( medHeap H )
{
	int med=0;
	
	if(H.n1 == H.n2)	//have same number of elements, delete last element on max heap
	{
		med = H.val[0];
	}
	else if(H.n1+1 == H.n2)
	{	
		med = H.val[H.capacity -1];	//the first element of the min heap
	}
	else;
	
	return med;
   // Write C-code Here
}

medHeap insMedHeap ( medHeap H, int x )
{
   // Write C-code Here
   int med;
   int i;
   med = getMedian(H);
   
   if(H.n1 + H.n2 < H.capacity)
   {
   if(H.n1 == H.n2 )
   {
   	if( x >= med )
   	{
   		H=insMinHeap(H,x);	//directly insert it into the minHeap
   	}
   	else
   	{
	   	for(i=0;i <= H.n1-2 ;i++)
		{
			H.val[i] = H.val[i+1];	//replace it with the value of the next element
		}
		
   		H.n1--;		//to delete the median 
   		H = insMaxHeap(H,x);
   		H = insMinHeap(H,med);	//insert the median in the min heap
   	}
   
   }
   else if(H.n1+1 == H.n2)
   {
   	if(x >=med)
   	{
   		for(i= H.capacity - 2 ; i >= H.capacity - H.n2 ; i--)
		{
			H.val[i+1]= H.val[i];
		}
   		H.n2--;		//delete the median from the min heap
   		H = insMaxHeap(H,med);
   		H = insMinHeap(H,x);
   	}
	else   
   	{
		H = insMaxHeap(H,x);   	
   	}
   }
   else;
   }
   return H;
}

medHeap delMedHeap ( medHeap H )
{
	int elm;
	int i;
	
	if(H.n1 != H.n2)
	{
		elm = H.val[H.capacity - 1];	//store the last element
		for(i= H.capacity - 2 ; i >= H.capacity - H.n2 ; i--)
		{
			H.val[i+1]= H.val[i];
		}
		
		H.val[H.capacity - H.n2] = elm;	//the new median
		H.n2--;
	}
	else
	{
		elm = H.val[0];
		for(i=0;i <= H.n1-2 ;i++)
		{
			H.val[i] = H.val[i+1];	//replace it with the value of the next element
		}
		
		H.val[H.n1-1] = elm;
		H.n1--;
	}
	return H;
   // Write C-code Here
}

medHeap medHeapSort ( medHeap H )
{

	int i=0;
	while(i < H.capacity)
	{
		H = delMedHeap(H);	//keep deleting the median but keep it in its own place
		i++;
	}
	return H;	
   // Write C-code Here
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

   srand((unsigned int)time(NULL));
   if (argc > 1) n = atoi(argv[1]);
   else {
      printf("Enter capacity (n) of the array: "); scanf("%d", &n);
   }

   H = initMedHeap(n);
   printf("\n+++ MedHeap initialized\n");

   printf("\n+++ Going to insert elements one by one in MedHeap\n");
   for (i=0; i<n; ++i) {
      x = 1 + rand() % 99;
      H = insMedHeap(H,x);
      printf("    Insert(%4d) done. Current median = %4d.\n", x, getMedian(H));
   }

   H = medHeapSort(H);
   printf("\n+++ Median Heap Sort done\n");
   printArray(H);
   
   free(H.val);

   return(0);
}

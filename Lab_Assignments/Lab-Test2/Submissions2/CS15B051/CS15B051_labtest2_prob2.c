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
  medHeap* med_heap=(medHeap*)malloc(sizeof(medHeap));
  med_heap->val=(int*)malloc(n*sizeof(int));
    med_heap->n1=0;
    med_heap->n2=0;
      med_heap->capacity=n;
    return(*med_heap);
  
  // Write C-code Here
}

int getMedian ( medHeap H )
{
  int n= H.n1+H.n2;
  if(n%2==0)
    return(H.val[0]);
  else
    return( H.val[H.capacity-1]);
  // Write C-code Here
}

medHeap insMedHeap ( medHeap H, int x )
{
   if(H.n1+H.n2==0){
    insMinHeap (  H, x );
    return H;
   }
   else{
    int med=getMedian ( H );
    int n= H.n1+H.n2;
     if(med>x){
        if(n%2==0){
         int temp=H.val[n-1];
        delMinHeap ( H );
        insMinHeap (  H,  x );
        insMaxHeap (  H, temp ); return(H);
       }
      else{
        insMaxHeap (  H,  x ); return(H);
      }
      
     }
     else if(med<x)
     {
        if(n%2==0)
        {
        insMinHeap (  H,  x ); return(H);
        }
        else{
          int temp=H.val[0];
          delMaxHeap ( H );
          insMaxHeap (  H,  x );
          insMinHeap (  H, temp ); return(H);
        }
         
     }
      if(med==x){
         if(n%2==0)
        {
        insMinHeap (  H,  x ); return(H);
        }
       else{
        insMaxHeap (  H,  x ); return(H);
      }
      }
   }
  
    // Write C-code Here
}

medHeap delMedHeap ( medHeap H )
{
   if(H.n1==H.n2)
    {
       delMaxHeap (  H ); return(H);
    }
    else{
       delMinHeap ( H );
     return(H);
}// Write C-code Here
}

medHeap medHeapSort ( medHeap H )
{
   int array[H.n1+H.n2];
   int i,j;
   for(j=0;j<H.n1+H.n2;j++)
   {
     int temp=getMedian ( H );
     delMedHeap ( H );
     for(i=0;i<H.n1+H.n2;i++)
      {
         if(H.val+i==NULL)
           H.val[i]=temp;
      }
   }
     return H;
    
  /*int a[n1],b[n2];
  int i;
   for(i=0;i<n1/2;i++)
   {
        a[i]=a[n1-i];
   } 
   for(i=H.capacity-1;i>n2;i--)
   {
        
   }*/ // Write C-code Here
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
      x = 1 + rand() % 9999;
      H = insMedHeap(H,x);
      printf("    Insert(%4d) done. Current median = %4d.\n", x, getMedian(H));
   }

   H = medHeapSort(H);
   printf("\n+++ Median Heap Sort done\n");
   printArray(H);
   
   free(H.val);

   return(0);
}

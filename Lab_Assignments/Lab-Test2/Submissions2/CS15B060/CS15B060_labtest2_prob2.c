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
    H.n1=0;
    H.n2=0;
    H.capacity=n;
    H.val=(int*)malloc(n*sizeof(int));
    return H;
   
 }

int getMedian ( medHeap H )
{ //int maxl=H.val[0];
  int minr=H.val[H.capacity-1];
 
   return minr;
   
   // Write C-code Here
}

medHeap insMedHeap ( medHeap H, int x )
{  
   if(H.n2!=0)
  {
   int m=getMedian(H);
     if(x>m)
      { if(H.n1==H.n2)
        { H=insMinHeap(H,x);
          //printf("n1=n2,x>m,%d,%d\n",H.n1,H.n2);
          }
          else
          { 
          H=insMinHeap(H,x);
          int min=H.val[H.capacity-1];
           H=delMinHeap(H);
            H= insMaxHeap(H,min);
             
            // printf("n1<n2,x>m%d,%d\n",H.n1,H.n2);
             }  
           }
         else
         {  if(H.n1==H.n2)
             {  
             H=insMaxHeap(H,x);
             int max=H.val[0];
           H=delMaxHeap(H);
             H=insMinHeap(H,max);
             
             //printf("n1=n2,x<m%d%d\n",H.n1,H.n2);
             }
             else
             { H=insMaxHeap(H,x);//printf("n1<n2,x<m%d%d\n",H.n1,H.n2);
             }
              }
         }
         else
         { H=insMinHeap(H,x);}
         
         

     return H;
  
   // Write C-code Here
}

medHeap delMedHeap ( medHeap H )
{
   // Write C-code Here
   
   if(H.n2>H.n1)
    H=delMinHeap(H);
   else
    H=delMaxHeap(H);
    return H;
   
   
   
}

medHeap medHeapSort ( medHeap H )
{ int i;    
 for(i=0;i<H.capacity;i++)
       { int m=getMedian(H);
           if(H.n2>H.n1)
           {H=delMedHeap(H);
             H.val[H.capacity-H.n2]=m;
             }
             else
             {H=delMedHeap(H);
              H.val[H.n1]=m;
              }
              }
              printArray(H);
              }
            


  
   // Write C-code Here


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
   // printf("%d",H.capacity);
    //H = insMedHeap(H,1);
     // printf("    Insert(%4d) done. Current median = %4d.\n", 1, getMedian(H));
    
   

 H = medHeapSort(H);
   printf("\n+++ Median Heap Sort done\n");
 //  printArray(H);
   
   //free(H.val);

   return(0);
}

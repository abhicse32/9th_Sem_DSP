#include<stdio.h>
#include<sys/time.h>
#include"q2_sort.h"
FILE *fp;
int main()
{
	int n,t,z;
	scanf("%d",&t);
	for(z=0;z<t;z++)
	{
	scanf("%d",&n);
	int unsort[n],asort[n],dsort[n];
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&unsort[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&asort[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&dsort[i]);
	}
	
	fp=fopen("out3_selection.txt","a");

	struct timeval  tv1, tv2;
	gettimeofday(&tv1, NULL);
	selection_sort(unsort,n);
	gettimeofday(&tv2, NULL);
	fprintf (fp,"%lf,",
         (double) (tv2.tv_usec - tv1.tv_usec)*1000000 +
         (double) (tv2.tv_sec - tv1.tv_sec)*1000000);
	
	gettimeofday(&tv1, NULL);
	selection_sort(asort,n);
	gettimeofday(&tv2, NULL);
	fprintf (fp,"%lf,",
         (double) (tv2.tv_usec - tv1.tv_usec)*1000000 +
         (double) (tv2.tv_sec - tv1.tv_sec)*1000000);

	gettimeofday(&tv1, NULL);
	selection_sort(dsort,n);
	gettimeofday(&tv2, NULL);
	fprintf (fp,"%lf,",
         (double) (tv2.tv_usec - tv1.tv_usec)*1000000 +
         (double) (tv2.tv_sec - tv1.tv_sec)*1000000);
	fprintf(fp,"\n");
	fclose(fp);
	
	
	fp=fopen("out3_bubble.txt","a");
	
	gettimeofday(&tv1, NULL);
	bubble_sort(unsort,n);
	gettimeofday(&tv2, NULL);
	fprintf (fp,"%lf,",
         (double) (tv2.tv_usec - tv1.tv_usec)*1000000 +
         (double) (tv2.tv_sec - tv1.tv_sec)*1000000);

	gettimeofday(&tv1, NULL);
	bubble_sort(asort,n);
	gettimeofday(&tv2, NULL);
	fprintf (fp,"%lf,",
         (double) (tv2.tv_usec - tv1.tv_usec)*1000000 +
         (double) (tv2.tv_sec - tv1.tv_sec)*1000000);

	gettimeofday(&tv1, NULL);
	bubble_sort(dsort,n);
	gettimeofday(&tv2, NULL);
	fprintf (fp,"%lf,",
         (double) (tv2.tv_usec - tv1.tv_usec)*1000000 +
         (double) (tv2.tv_sec - tv1.tv_sec)*1000000);
	fprintf(fp,"\n");
	fclose(fp);
	
	
	fp=fopen("out3_insertion.txt","a");

	gettimeofday(&tv1, NULL);
	insertion_sort(unsort,n);
	gettimeofday(&tv2, NULL);
	fprintf (fp,"%lf,",
         (double) (tv2.tv_usec - tv1.tv_usec)*1000000 +
         (double) (tv2.tv_sec - tv1.tv_sec)*1000000);

	gettimeofday(&tv1, NULL);
	insertion_sort(asort,n);
	gettimeofday(&tv2, NULL);
	fprintf (fp,"%lf,",
         (double) (tv2.tv_usec - tv1.tv_usec)*1000000 +
         (double) (tv2.tv_sec - tv1.tv_sec)*1000000);

	gettimeofday(&tv1, NULL);
	insertion_sort(dsort,n);
	gettimeofday(&tv2, NULL);
	fprintf (fp,"%lf,",
         (double) (tv2.tv_usec - tv1.tv_usec)*1000000 +
         (double) (tv2.tv_sec - tv1.tv_sec)*1000000);
	fprintf(fp,"\n");
	fclose(fp);
	
	struct timeval tv3,tv4,tv5,tv6;
	fp=fopen("out3_mergesort.txt","a");
	
	gettimeofday(&tv1,NULL);
	merge_sort(unsort,0,n);
	gettimeofday(&tv2,NULL);
	fprintf(fp,"%lf,",(double) (tv2.tv_usec - tv1.tv_usec) +
         (double) (tv2.tv_sec - tv1.tv_sec)*1000000);
         
	gettimeofday(&tv3,NULL);
	merge_sort(asort,0,n);
	gettimeofday(&tv4,NULL);
	fprintf(fp,"%lf,",(double) (tv4.tv_usec - tv3.tv_usec) +
         (double) (tv4.tv_sec - tv3.tv_sec)*1000000);
	
	gettimeofday(&tv5,NULL);
	merge_sort(dsort,0,n-1);
	gettimeofday(&tv6,NULL);
	fprintf(fp,"%lf",(double) (tv6.tv_usec - tv5.tv_usec) +
         (double) (tv6.tv_sec - tv5.tv_sec)*1000000);
	fprintf(fp,"\n");
         
	fclose(fp);
	
	struct timeval tv7,tv8,tv9,tv10,tv11,tv12;
	fp=fopen("out3_quicksort.txt","a");
	
	gettimeofday(&tv7,NULL);
	quick_sort(unsort,0,n-1);
	gettimeofday(&tv8,NULL);
	fprintf(fp,"%lf,",(double) (tv8.tv_usec - tv7.tv_usec) +
         (double) (tv8.tv_sec - tv7.tv_sec)*1000000);
	
	gettimeofday(&tv9,NULL);
	quick_sort(asort,0,n-1);
	gettimeofday(&tv10,NULL);
	fprintf(fp,"%lf,",(double) (tv10.tv_usec - tv9.tv_usec) +
         (double) (tv10.tv_sec - tv9.tv_sec)*1000000);
	
	gettimeofday(&tv11,NULL);
	quick_sort(dsort,0,n-1);
	gettimeofday(&tv12,NULL);
	fprintf(fp,"%lf",(double) (tv12.tv_usec - tv11.tv_usec) +
         (double) (tv12.tv_sec - tv11.tv_sec)*1000000);
	fprintf(fp,"\n");
	fclose(fp);
	
}

	return 0;
	
}

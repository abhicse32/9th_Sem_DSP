#include<stdio.h>
#include<sys/time.h>
#include"q2_sort.h"
int main()
{
	int n,i,t,z;
	scanf("%d",&t);
	FILE *fp;
	fp=fopen("out2.txt","w");
	for(z=0;z<t;z++)
	{
	scanf("%d",&n);
	int arr[n],copy1[n],copy2[n],copy3[n],copy4[n],copy5[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++)
	{
		copy1[i]=arr[i];
		copy2[i]=arr[i];
		copy3[i]=arr[i];
		copy4[i]=arr[i];
		copy5[i]=arr[i];
	}
	
	
	{
	struct timeval tv1,tv2,tv3,tv4,tv5,tv6,tv7,tv8,tv9,tv10;
	
	fprintf(fp,"%d ",n);
	gettimeofday(&tv1,NULL);
	selection_sort(copy1,n);
	gettimeofday(&tv2,NULL);
	fprintf(fp,"%lf ",(double)(tv2.tv_usec-tv1.tv_usec)+(double)(tv2.tv_usec-tv1.tv_usec)*1000000);
	
	gettimeofday(&tv3,NULL);
	bubble_sort(copy2,n);
	gettimeofday(&tv4,NULL);
	fprintf(fp,"%lf ",(double)(tv4.tv_usec-tv3.tv_usec)+(double)(tv4.tv_usec-tv3.tv_usec)*1000000);
	
	gettimeofday(&tv5,NULL);
	insertion_sort(copy3,n);
	gettimeofday(&tv6,NULL);
	fprintf(fp,"%lf ",(double)(tv6.tv_usec-tv5.tv_usec)+(double)(tv6.tv_usec-tv5.tv_usec)*1000000);
	
	gettimeofday(&tv7,NULL);
	merge_sort(copy4,0,n-1);
	gettimeofday(&tv8,NULL);
	fprintf(fp,"%lf ",(double)(tv8.tv_usec-tv7.tv_usec)+(double)(tv8.tv_usec-tv7.tv_usec)*1000000);
	
	gettimeofday(&tv9,NULL);
	quick_sort(copy5,0,n-1);
	gettimeofday(&tv10,NULL);
	fprintf(fp,"%lf",(double)(tv10.tv_usec-tv9.tv_usec)+(double)(tv10.tv_usec-tv9.tv_usec)*1000000);
	fprintf(fp,"\n");
}

	for(i=0;i<n;i++)
	{
		printf("%d ",copy1[i]);
	}
	printf("\n");
	
	for(i=0;i<n;i++)
	{
		printf("%d ",copy2[i]);
	}
	printf("\n");
	
	for(i=0;i<n;i++)
	{
		printf("%d ",copy3[i]);
	}
	printf("\n");

	for(i=0;i<n;i++)
	{
		printf("%d ",copy4[i]);
	}
	printf("\n");
	
	for(i=0;i<n;i++)
	{
		printf("%d ",copy5[i]);
	}

	
}
fclose(fp);
	return 0;
	
}

#include <stdio.h>
#include "hash_map.h"
#include <stdlib.h>

int main()
{
	int t;
	int n;
	int k;
	int i;
	int flag;
	scanf("%d",&t);
	while(t>0)
	{
		scanf("%d %d",&n,&k);
		int *arr= (int*)malloc(n*sizeof(int));
		map *Map=new_map();
		flag=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		for(i=0;i<n;i++)
		{
			if(find(Map,k-arr[i])==k-arr[i])
			{
				if(arr[i]>(k/2))
				{
					printf("%d %d\n", k-arr[i],arr[i]);
				}
				else
					printf("%d %d\n", arr[i],k-arr[i]);
					flag=1;
					break;
				}
				else
					put(Map,arr[i],arr[i]);
						
			}
		if(flag==0)
			printf("-1\n");
		clear(Map);
		free(arr);
		t--;
	}
}

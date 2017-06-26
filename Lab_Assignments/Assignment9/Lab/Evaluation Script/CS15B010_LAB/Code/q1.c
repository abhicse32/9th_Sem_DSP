#include <stdio.h>
#include <limits.h>
#include "hash_map.h"


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n = 0;
		int low= 0;
		int high = 0;
		scanf("%d",&n);
		scanf("%d",&low);
		scanf("%d",&high);
		int data = 0;
		int i = 0;
		map *m = new_map(); 
		while(i < n)
		{
			scanf("%d",&data);
			put(m,data,data);
			i++;
		}
		i = low;
		int count = 0;
		while(i <= high)
		{
			if(find(m,i) == INT_MIN)
			{
				printf("%d ",i);
				count++;
			}
			i++;
		}
		if(count == 0)
			printf("-1");
		printf("\n");
	}
	return 0;
}

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
		int k= 0;
		scanf("%d",&n);
		scanf("%d",&k);
		int data = 0;
		int i = 0;
		map *m = new_map(); 
		int flag = 0;
		while(i < n)
		{
			scanf("%d",&data);
			if(find(m,data) == INT_MIN)
			{
				put(m,data,i);
			}
			else
			{
				if((i - find(m,data)) <= k)
					flag = 1;
				put(m,data,i);
			}
			i++;
		}
		if(flag == 0)
			printf("false\n");
		else
			printf("true\n");
	}
	return 0;
	
}

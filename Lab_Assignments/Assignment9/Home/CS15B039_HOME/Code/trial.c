#include "set.c"

int main()
{
	int i ;
	scanf("%d" , &SIZE) ;

	int* arr = (int*)malloc(SIZE*sizeof(int)) ;
	for (i = 0; i < SIZE; ++i)
		scanf("%d" , &arr[i]) ;

	initializeMap (arr) ;
    
    Union(3, 4);
    Union(5, 6);
    Union(3, 5);
    printNode(getNode(6));
    findWithPathCompression(6);
    printNode(getNode(6));
    return 0;
    
}

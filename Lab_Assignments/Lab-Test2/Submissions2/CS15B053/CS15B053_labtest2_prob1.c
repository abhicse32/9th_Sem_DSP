#include <stdio.h>
#include <string.h>
#include<stdlib.h>

#define MAX_SIZE 100

typedef struct _node {
   char label;
   struct _node *L;
   struct _node *R;
} node;


int indexof(char *s, char c)//Utility function to find index of character in string
{
	int i;
	for(i=0; s[i]!='\0'; i++)
		if(s[i] == c)
			return i;
	return -1;
}
	



// COMPLETE THE FOLLOWING gentree FUNCTION
node *gentree ( char *inlist , char *prelist )
{
   int l = strlen(inlist), i, rk=0, lk=0, inlist_root_index;
   if(l == 0)
   	return NULL;
   else
   {
   
	node *root; root = (node *)malloc(sizeof(node)); root->label = prelist[0]; root->L = NULL; root->R = NULL;
	inlist_root_index = indexof(inlist, root->label);
	
	char *left_inlist; left_inlist = (char *)malloc(inlist_root_index * sizeof(char));
	for(i=0; i<inlist_root_index; i++)
		left_inlist[i] = inlist[i];
	left_inlist[i] = '\0';
	char *right_inlist; right_inlist = (char *)malloc((l - 1 - inlist_root_index) * sizeof(char));
	for(i=inlist_root_index+1; i<l; i++)
		right_inlist[i - inlist_root_index - 1] = inlist[i];
	right_inlist[i] = '\0';
		
	char *left_prelist; left_prelist = (char *)malloc(inlist_root_index * sizeof(char));
	char *right_prelist; right_prelist = (char *)malloc((l - 1 - inlist_root_index) * sizeof(char));
	for(i=0; i<l; i++)
	{
		if(indexof(left_inlist, prelist[i]) != -1)
			left_prelist[lk++] = prelist[i];
		if(indexof(right_inlist, prelist[i]) != -1)
			right_prelist[rk++] = prelist[i];
	}
	left_prelist[lk] = '\0';
	right_prelist[rk] = '\0';
	   
	root->L = gentree(left_inlist, left_prelist);
	root->R = gentree(right_inlist, right_prelist);
   
   	return root;   
   }
}

void printtree ( node *root )
{
   if (root == NULL) return;
   printf("Node : %c, ",root->label);
   printf("Left child : ");
   if (root->L == NULL) printf("NULL, ");
   else printf("   %c, ",root->L->label);
   printf("Right child : ");
   if (root->R == NULL) printf("NULL.\n");
   else printf("   %c.\n",root->R->label);
   printtree(root->L);
   printtree(root->R);
}

int main ()
{
   char inlist[MAX_SIZE], prelist[MAX_SIZE];
   node *root;

   printf("Inorder listing  : "); scanf("%s",inlist);
   printf("Preorder listing : "); scanf("%s",prelist);
   root = gentree(inlist,prelist);
   printtree(root);
   return(0);
}

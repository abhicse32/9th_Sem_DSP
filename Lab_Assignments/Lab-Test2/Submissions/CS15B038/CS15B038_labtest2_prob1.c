#include <stdio.h>
#include <string.h>
#include<stdlib.h>

#define MAX_SIZE 100

typedef struct _node {
   char label;
   struct _node *L;
   struct _node *R;
} node;

// COMPLETE THE FOLLOWING gentree FUNCTION
node *gentree ( char *inlist , char *prelist )
{
   // Write C-code Here
	
	if(strlen(inlist) == 0) return NULL;

	char A = prelist[0];
	char temp;
	char* s1, *s2, *s3, *s4;

	s1 = (char*)malloc(sizeof(char)*strlen(inlist));
	s2 = (char*)malloc(sizeof(char)*strlen(inlist));
	s3 = (char*)malloc(sizeof(char)*strlen(inlist));
	s4 = (char*)malloc(sizeof(char)*strlen(inlist)); 

	int i, j;

	i = 0;
	j = 0;

	while(1)
	{
		temp = inlist[i];
		if(temp == A) break;
		s1[i] = inlist[i];
		i++;
	}
	
	s1[i] = '\0';

	i++;

	while(i < strlen(inlist))
	{
		temp = inlist[i];
		s2[j] = inlist[i];
		j++;
		i++;
	}

	s2[j] = '\0';	

	i = 1;
	j = 0;

	while(j < strlen(s1))
	{
		s3[j] = prelist[i];
		j++;
		i++;
	}

	s3[j] = '\0';
	j = 0;

	while(i < strlen(prelist))
	{
		s4[j] = prelist[i];
		j++;
		i++;
	}

	s4[j] = '\0';
	
	node* x = (node*)malloc(sizeof(node*));

	x->label = A;
	x->L = gentree(s1, s3);
	x->R = gentree(s2, s4);

	return x;
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

 scanf("%s",inlist);
 scanf("%s",prelist);
   root = gentree(inlist,prelist);
   printtree(root);
   return(0);
}

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
int l=strlen(inlist);
if(l==0)
return NULL;
node* A=malloc(sizeof(node));
A->label=prelist[0];
char* B_in=malloc(l*sizeof(char));
char* B_pre=malloc(l*sizeof(char));

int i=0;
	while(inlist[i]!=prelist[0])
	{
	B_in[i]=inlist[i];
	i++;
	}
B_in[i]='\0';
int j=0;
l=strlen(B_in);
	while(j<l)
	{
	B_pre[j]=prelist[j+1];
	j++;
	}
B_pre[j]='\0';

A->L=gentree(B_in,B_pre);

int k=0;
i++;
	while(inlist[i]!='\0')
	{
	B_in[k]=inlist[i];
	i++;
	k++;
	}

B_in[k]='\0';
k=0;

l=strlen(prelist);

	while(j<=l)
	{
	B_pre[k]=prelist[j+1];
	k++;
	j++;
	}
B_pre[k]='\0';

A->R=gentree(B_in,B_pre);
return A;
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

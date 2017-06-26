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
	if(strlen(inlist)==0) return NULL;
	if(strlen(inlist)==1){
		node* temp=(node*)malloc(sizeof(node));
		temp->label=inlist[0];
		temp->R=NULL;
		temp->L=NULL;
		return temp;
	}
	int i;
	for(i=0;i<strlen(inlist);i++){
		if(inlist[i]==prelist[0]) break;
	}
	node* temp=(node*)malloc(sizeof(node));
	temp->label=prelist[0];
	char* inl=(char*)malloc((i+1)*sizeof(char));
	strncpy(inl,inlist,i);
	inl[i]='\0';
	++prelist;
	char* prel=(char*)malloc((i+1)*sizeof(char));
	strncpy(prel,prelist,i);
	prel[i]='\0';
	temp->L=gentree(inl,prel);
	free(inl);
	free(prel);
	int j;
	++inlist;
	for(j=0;j<i;j++){
		++inlist;
		++prelist;
	}
	temp->R=gentree(inlist,prelist);
	return temp;
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

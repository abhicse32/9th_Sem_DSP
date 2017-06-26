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
   if(strlen(inlist)==0) return NULL;
   char root=prelist[0];
   int i;
   for(i=0;i<strlen(inlist);i++){
   	if(inlist[i]==root) break;
   }
   node* r=(node*)malloc(sizeof(node));
   r->label=root;
   char* newin1=(char*)calloc(sizeof(char),i+1);
   char* newpre1=(char*)calloc(sizeof(char),i+1);
   int j=0,k=1;
   for(;j<i;j++,k++){
   	newin1[j]=inlist[j];
	newpre1[j]=prelist[j+1];
   }
   r->L=gentree(newin1,newpre1);
   r->R=gentree(inlist+i+1,prelist+i+1);
   return r;

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

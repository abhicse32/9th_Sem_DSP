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
   if(strlen(inlist) == 0)
   {
    return NULL;
   }
   node* root = (node*)malloc(sizeof(node));
   root->label = prelist[0];
   int i = 0;
   for(i = 0; i < strlen(inlist); i++)
   {
    if(inlist[i] == prelist[0])
        break;
   } 
   
   char* leftIn = strndup(inlist, i);
   char* rightIn = strdup(inlist + i + 1); 
   
   char* leftPre = strndup(prelist + 1, i);
   char* rightPre = strdup(prelist + i + 1);
   
   root->L = gentree(leftIn, leftPre);
   root->R = gentree(rightIn, rightPre);
   
   return root;
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

#include <stdio.h>
#include <string.h>
#include<stdlib.h>

#define MAX_SIZE 100

typedef struct _node {
   char label;
   struct _node *L;
   struct _node *R;
} node;

node *gentree ( char *inlist , char *prelist )
{
   node *head;
   char *inp, *prep, ch;

   if ((strlen(inlist)==0)||(strlen(prelist)==0)) return(NULL);

   head = (node *)malloc(sizeof(node));
   head->label = prelist[0];
   inp = strchr(inlist,prelist[0]);
   if (inp == NULL) {
      free(head);
      fprintf(stderr, "Malformed expression(s)...\n");
      return(NULL);
   }
   *inp = '\0';
   prelist++;
   prep = prelist + strlen(inlist);
   ch = *prep;
   *prep = '\0';
   head->L = gentree(inlist,prelist);
   *prep = ch;
   inp++;
   head->R = gentree(inp,prep);
   return(head);
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

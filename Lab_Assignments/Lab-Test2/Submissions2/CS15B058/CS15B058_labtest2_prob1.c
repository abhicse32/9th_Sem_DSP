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
	if(prelist[0]=='\0')
		return NULL;
   char rootchar=prelist[0];
   node* newnode=(node*)malloc(sizeof(node));
   newnode->L=NULL;
   newnode->R=NULL;
   newnode->label=rootchar;
   int l=strlen(inlist);
   char* inlist1=(char*)malloc((l)*sizeof(char));
   char* inlist2=(char*)malloc((l)*sizeof(char));
   char* prelist1=(char*)malloc((l)*sizeof(char));
   char* prelist2=(char*)malloc((l)*sizeof(char));
   int i;
   for(i=0;i<inlist[i]!='\0';i++)
   {
   	if(inlist[i]==rootchar)
   		break;
   	inlist1[i]=inlist[i];
   }
   inlist1[i]='\0';
   int rootposinlist=i;
   int j=0;
   for(i=rootposinlist+1;inlist[i]!='\0';i++,j++)
   {
   	inlist2[j]=inlist[i];
   }
   inlist2[j]='\0';
   int l1=strlen(inlist1);
   int l2=strlen(inlist2);
   
   for(i=1;i<=l1;i++)
   {
   	prelist1[i-1]=prelist[i];
   }
   prelist1[i-1]='\0';
   for(j=0;prelist[i]!='\0';i++,j++)
   {
   	prelist2[j]=prelist[i];
   }
   prelist2[j]='\0';
  newnode->L=gentree(inlist1,prelist1);
  newnode->R=gentree(inlist2,prelist2);   
   
   return newnode;
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

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
   char *linlist,*rinlist;
   char *lprelist,*rprelist;	//the new strings
   
   linlist=(char*)malloc(sizeof(char)*MAX_SIZE);
   rinlist=(char*)malloc(sizeof(char)*MAX_SIZE);
   lprelist=(char*)malloc(sizeof(char)*MAX_SIZE);
   rprelist=(char*)malloc(sizeof(char)*MAX_SIZE);	//allocate space for the new strings
   
   int l=strlen(inlist);	//to preform the operation only if a string is passed
   
   int l1;
   int i=0;
   int j=0;
   if(l>0)
   {
   	while(inlist[i]!=prelist[0])	//extracting the lprelist
   	{
   		linlist[j]=inlist[i];	
   		i++;
   		j++;
   	}
   	linlist[j]='\0';
   	
   	j=0;
   	i++;	//to skip the root
   	
   	while(inlist[i]!='\0')
   	{
   		rinlist[j]=inlist[i];
   		j++;
   		i++;
   	}
   	rinlist[j]='\0';
   	
   	l1=strlen(linlist);		//length of the prelist and inlist would be the same 
   	
   	i=1;		//skipping the root
   	j=0;
   	while(i<=l1)
   	{
   		lprelist[j]=prelist[i];
   		j++;
   		i++;
   	}
   	lprelist[j]='\0';
   	
   	j=0;
   	while(prelist[i]!='\0')
   	{
   		rprelist[j]=prelist[i];
   		j++;
   		i++;
   	}
   	rprelist[j]='\0';
   	
   	node* root=(node*)malloc(sizeof(node));
   	root->label = prelist[0];
   	root->L=gentree(linlist,lprelist);
   	root->R=gentree(rinlist,rprelist);
   	return root;
   }
   
   return NULL;
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

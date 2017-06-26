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
node *gentree ( char *inlist , char *prelist ){
	if(prelist[0]==0)
		return NULL;
	char root_label=prelist[0];
	int i=0,idx1=0,idx2=0;
	int flag=0;
	char *in_left=(char *)malloc(MAX_SIZE*sizeof(char));
	char *pre_left=(char *)malloc(MAX_SIZE*sizeof(char));
	char *in_right=(char *)malloc(MAX_SIZE*sizeof(char));
	char *pre_right=(char *)malloc(MAX_SIZE*sizeof(char));
	while(inlist[i]!=0){
		if(inlist[i]==root_label){
			flag=1;
			i++;
			continue;
		}
		if (flag){
			in_right[idx2]=inlist[i];
			pre_right[idx2]=prelist[i];
			idx2++;
		}
		else{
			in_left[idx1]=inlist[i];
			pre_left[idx1]=prelist[i+1];
			idx1++;
		}
		i++;
	}
	node* root=(node *)malloc(sizeof(node));
	root->label=root_label;
	root->L=gentree(in_left,pre_left);
	root->R=gentree(in_right,pre_right);
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

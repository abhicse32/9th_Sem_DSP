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
  char c;
  node *root;
  char *array;
  root=(node*)malloc(sizeof(node));
  int i=0;
  c=prelist[i];
  node* temp;
  root->label=prelist[0];
  temp=root;
  //int t=0;
  int j=0;
  while(prelist[0]!=inlist[j]){   
        i=1;
       if(prelist[i]==inlist[j]){
          int k=0;
         root->L->label=prelist[i];
         while(inlist[k]){
         if(prelist[i]==inlist[k])
            inlist[k]=-1;
            k++;
          }
         root=root->L;
         i++;
         j++;                                              
        }
        else if(inlist[j]==-1){
              j++;
         if(prelist[i]==inlist[j]){
         root->R->label=prelist[i];
          root=root->R;
             i++; j++;
          }
       }
        else{
          root->R->label=prelist[i];
          root=root->R;
           int k=0;
          while(inlist[k]){
           
         if(prelist[i]==inlist[k])
          inlist[k]=-1;
              k++;
          }
           i++;
       } 
   }
   root=temp;
    while(prelist[i])
    {
       root->R->label= prelist[i];
          i++;
         if(prelist[i]==inlist[j]){
         root->L->label=prelist[i];  
        int k=0;
         while(inlist[k]){
           
         if(prelist[i]==inlist[k])
            inlist[k]=-1; k++;
          }
         root=root->L;
         i++;
         j++;                                              
        }
        else if(inlist[j]==-1){
              j++;
         if(prelist[i]==inlist[j]){
         root->R->label=prelist[i];
          root=root->R;
             i++; j++;
          }
       }
        else{
          root->R->label=prelist[i];
          root=root->R;   
           int k=0;
          while(inlist[k]){
            
         if(prelist[i]==inlist[k])
          inlist[k]=-1; k++;
          }
           i++;
       } 
    }
   return(temp);
  // Write C-code Here
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

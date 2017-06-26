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
{   node *t=(node*)malloc(sizeof(node));
      t->label=prelist[0];
      // if(strlen(inlist)==2 || strlen(prelist)==1)
       // return t;
         if(strlen(inlist)==1||strlen(prelist)==1)
         return NULL;
      
      
      
       int i;
        for(i=0;i<strlen(inlist);i++)
         { if(inlist[i]==prelist[0])
             break;
             }
             if(i==strlen(inlist))
              return NULL;
      
      char *r=(char*)malloc(sizeof(MAX_SIZE*sizeof(char)));
      char *s=(char*)malloc(sizeof(MAX_SIZE*sizeof(char)));
       int lsize=i-1;
        //if(lsize<0)
         //return NULL;
         
        for(i=0;i<=lsize;i++)
        { r[i]=inlist[i];}
          r[i]='\0';
         for(i=lsize+2;i<strlen(inlist);i++)
        { s[i-lsize-2]=inlist[i];}
          s[i-lsize-2]='\0'; 
           //for(i=0;i<strlen(r);i++)
            printf("R:%s\n",r);
            printf("S:%s\n",s);
          
          
          
          char *v=(char*)malloc(sizeof(MAX_SIZE*sizeof(char)));
      char *u=(char*)malloc(sizeof(MAX_SIZE*sizeof(char)));
            if(lsize>=0)
           {char mid=inlist[lsize];
            for(i=1;prelist[i]!=mid;i++)
              u[i-1]=prelist[i];
              u[i-1]=mid;
               u[i]='\0';
                int midind=i+1;
                for(i=midind;i<strlen(prelist);i++)
                 v[i-midind]=prelist[i];
                 v[i-midind]='\0';}
                  else
                  {  for(i=1;i<strlen(prelist);i++)
                     v[i-1]=prelist[i];
                      v[i-1]='\0';
                  }
                  
                  
                  
                  
                 
                     
                 printf("U:%s\n",u);
            printf("V:%s\n",v);
                 
       
      
        if(lsize>=0)
       t->L=gentree(r,u);
        if(lsize<0)
        t->L=NULL;
        
        t->R=gentree(s,v);
          return t;


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

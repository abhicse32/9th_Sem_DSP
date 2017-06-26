#include "CList.h"
#include<stdio.h>
#include<stdlib.h>

CNode* cnode_new( int data){

	CNode* new;					
	
	new = (CNode*)malloc(sizeof(CNode));			//Allocates space for the node in the heap using malloc
	
	new->data = data;
	new->next = NULL;
	
	return new;
}

CList* clist_new(){							//Creates new list

	CList* lst = (CList*)malloc(sizeof(CList));
	
	lst->head = NULL;
	
	return lst;
}

int clist_size( CList* lst ){

	CNode* a = lst->head;
	
	if(a == NULL) return 0;						//If an empty list returns size as 0
	
	int c = 1;
	
	while(a->next != lst->head){					//Loops and increments c until the counter comes back to the first element
		c++;
		a = a->next;
	}
	
	return c;
}

void clist_print( CList* lst ){

	CNode* a = lst->head;
	
	if(a == NULL) {printf("\n");return ;}			//If empty list

	printf("%d ",a->data);						
	a = a->next;
	
	while(a != lst->head){						//Loops and prints data until it reaches the first element again
		printf("%d ",a->data);
		a = a->next;
	}
	
	printf("\n");
	
	return ;
}

int clist_get( CList* lst, int idx ){

	int c = 0;
	CNode* a = lst->head;			
	
	while(c != idx){							//Loops till it gets to the ith node
		a = a->next;
		c++;	
	}
	
	return a->data;
}

void clist_append( CList* lst, int data ){

	CNode* a = lst->head;
	
	CNode* new = cnode_new(data);
	
	if(a ==  NULL){							//If empty list just add the node to the lst head
		lst->head = new;
		new->next = lst->head;
		return ;
	}
		
	while((a->next) != (lst->head)) a = a->next;		//Else add element at the end with its next pointing at first element
	
	a->next = new;
	new->next = lst->head;
	
	return ;		
}

void clist_prepend( CList* lst, int data ){

	CNode* a = lst->head;
	CNode*  new = cnode_new(data);
	if(a==NULL)	{							//If empty list
	
		lst->head = new;
		new->next = lst->head;
		return ;
		}
				
	new->next = a;

	while((a->next) != (lst->head)) a = a->next;		//Loops until u get to the last elemenyt and changes its next to the new 
	lst->head = new;							//element added
	a->next = new;
	
	return ;
}

void clist_insert( CList* lst, int idx, int data ){		//Inserts element at the ith index

	CNode* a = lst->head;
	
	CNode* new = cnode_new(data);
	
	int c;
	
	if(idx == 0){
		
		clist_prepend(lst,data);
		return;
	}
	
	else if(idx == clist_size(lst)) {clist_append(lst,data); return;}		//Appends the data to the list if is to be inserted at the end
	
	for(c = 0; c != (idx-1); c++) a = a->next;
	
	new->next = a->next;
	a->next = new;
	
	return ;
}

void clist_remove_last( CList* lst ){				//removes last element and changes its preceeding node's next to the list->head

	CNode* a = lst->head;
	if(a != NULL){
	
		if(a->next == lst->head){		
			lst->head = NULL;
			return ;
		}
			
		while((a->next)->next != lst->head) a = a->next;
	
		a->next = lst->head;
	}

	return ;	
}

void clist_remove_first( CList* lst ){				//Removes the first element

	if(lst->head == NULL) return ;

	CNode* a = lst->head;
	
	if(a->next == lst->head){
		lst->head = NULL;
		return ;
	}
		
	while(a->next != lst->head) a = a->next;			//Changes the last elements next to the new first element
		
		a->next = (lst->head)->next;
	
	lst->head = (lst->head)->next;
	
	return ;
}

void clist_remove( CList* lst, int idx ){				//Removes ith element from the list

	CNode* a = lst->head;
	
	int c;
	
	if(idx == 0){							
		clist_remove_first(lst);
		return ;
	}
	
	for(c = 0; c < idx-1; c++) a = a->next;			//Bypasses the link from over ith element
	
	a->next = (a->next)->next; 	
	
	return ;
}

void clist_reverse(CList* lst)  			//Reverses the list by removin the existing links and adding new ones
{

    if((clist_size(lst)==1) || (clist_size(lst)==0));   
    else    {
                CNode* a = lst->head;     
                int i = 0;                      
                while(i!=(clist_size(lst)-1))
                    {
                        a = a->next;
                        i++;
                    }
                CNode* last_element = a;

                for(i = clist_size(lst)-1; a != (lst->head); i--)
                    {
                        CNode* c = lst->head;
                        int j = 0;
                        while(j!=(i-1))
                            {
                                c = c->next;
                                j++;
                            }
                        a->next = c;
                        a = c;
                    }
                (lst->head)->next = last_element;
                lst->head = last_element;
            }
}

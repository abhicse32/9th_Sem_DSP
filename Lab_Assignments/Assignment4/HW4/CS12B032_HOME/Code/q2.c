#include "CList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFF_SIZE 20

int main(int argc, char* argv[]){
    CList* lst= clist_new();
    char buff[BUFF_SIZE];
    while(fgets(buff,BUFF_SIZE-1,stdin)!=NULL){
      
        buff[strlen(buff)-1]='\0';
        char* delimiter=" ";
        char* temp= strtok(buff,delimiter);
        if(!strcmp(temp,"size")){
          printf("%d\n",clist_size(lst));

        }else if(!strcmp(temp,"get")){
            temp= strtok(NULL,delimiter);
            printf("%d\n",clist_get(lst,atoi(temp)));

        }else if(!strcmp(temp,"append")){
          temp= strtok(NULL,delimiter);
          clist_append(lst,atoi(temp));
          clist_print(lst);

        }else if(!strcmp(temp,"prepend")){
          temp= strtok(NULL,delimiter);
          clist_prepend(lst,atoi(temp));
          clist_print(lst);

        }else if(!strcmp(temp,"insert")){
          char* index= strtok(NULL,delimiter);
          temp= strtok(NULL,delimiter);
          clist_insert(lst,atoi(index),atoi(temp));
          clist_print(lst);

        }else if(!strcmp(temp,"remove_first")){
            clist_remove_first(lst);
            clist_reverse(lst);
            clist_print(lst);

        }else if(!strcmp(temp,"remove_last")){
           clist_remove_last(lst);
           clist_reverse(lst);
           clist_print(lst);

        }else if(!strcmp(temp,"remove")){
          temp= strtok(NULL, delimiter);
           clist_remove(lst,atoi(temp));
           clist_reverse(lst);
           clist_print(lst);
        }
    }
}
#include "DList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFF_SIZE 20
int main(int argc, char* argv[]){
    DList* lst= dlist_new();
    char buff[BUFF_SIZE];
    while(fgets(buff,BUFF_SIZE-1,stdin)!=NULL){
      
        buff[strlen(buff)-1]='\0';
        char* delimiter=" ";
        char* temp= strtok(buff,delimiter);
        if(!strcmp(temp,"size")){
          printf("%d\n",dlist_size(lst));

        }else if(!strcmp(temp,"get")){
            temp= strtok(NULL,delimiter);
            printf("%d\n",dlist_get(lst,atoi(temp)));

        }else if(!strcmp(temp,"append")){
          temp= strtok(NULL,delimiter);
          dlist_append(lst,atoi(temp));
          dlist_reverse(lst);
          dlist_print(lst);

        }else if(!strcmp(temp,"prepend")){
          temp= strtok(NULL,delimiter);
          dlist_prepend(lst,atoi(temp));
          dlist_reverse(lst);
          dlist_print(lst);

        }else if(!strcmp(temp,"insert")){
          char* index= strtok(NULL,delimiter);
          temp= strtok(NULL,delimiter);
          dlist_insert(lst,atoi(index),atoi(temp));
          dlist_reverse(lst);
          dlist_print(lst);

        }else if(!strcmp(temp,"remove_first")){
            dlist_remove_first(lst);
            dlist_print(lst);

        }else if(!strcmp(temp,"remove_last")){
           dlist_remove_last(lst);
           dlist_print(lst);

        }else if(!strcmp(temp,"remove")){
          temp= strtok(NULL, delimiter);
           dlist_remove(lst,atoi(temp));
           dlist_print(lst);
        }
    }
}
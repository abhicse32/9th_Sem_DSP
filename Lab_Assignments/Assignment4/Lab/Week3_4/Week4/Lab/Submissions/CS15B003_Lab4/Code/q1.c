/*
 * Author: Abhishek Yadav
 * Linked list test program
 */

#include "List.h"
#include <string.h>
#include <stdio.h>
#include <string.h>
#define BUFF_SIZE 20

int main(int argc, char* argv[]){
    LList* lst= llist_new();
    char buff[BUFF_SIZE];
    while(fgets(buff,BUFF_SIZE-1,stdin)!=NULL){
      
        buff[strlen(buff)-1]='\0';
        char* delimiter=" ";
        char* temp= strtok(buff,delimiter);
        if(!strcmp(temp,"size")){
          printf("%d\n",llist_size(lst));

        }else if(!strcmp(temp,"get")){
            temp= strtok(NULL,delimiter);
            printf("%d\n",llist_get(lst,atoi(temp)));

        }else if(!strcmp(temp,"append")){
          temp= strtok(NULL,delimiter);
          llist_append(lst,atoi(temp));
          llist_print(lst);

        }else if(!strcmp(temp,"prepend")){
          temp= strtok(NULL,delimiter);
          llist_prepend(lst,atoi(temp));
          llist_print(lst);

        }else if(!strcmp(temp,"insert")){
          char* index= strtok(NULL,delimiter);
          temp= strtok(NULL,delimiter);
          llist_insert(lst,atoi(index),atoi(temp));
          llist_print(lst);

        }else if(!strcmp(temp,"remove_first")){
            llist_remove_first(lst);
            llist_print(lst);

        }else if(!strcmp(temp,"remove_last")){
           llist_remove_last(lst);
           llist_print(lst);

        }else if(!strcmp(temp,"remove")){
          temp= strtok(NULL, delimiter);
           llist_remove(lst,atoi(temp));
           llist_print(lst);
        }
    }
}
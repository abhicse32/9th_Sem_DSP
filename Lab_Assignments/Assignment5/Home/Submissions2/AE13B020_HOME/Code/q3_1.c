//
// Created by phani on 18/9/16.
//
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

#define BUFEER_SIZE 1000

int evaluate(char* );
//void get_expression(char* ,char**);
void main(){
    char temp_string[BUFEER_SIZE];
    while(fgets(temp_string,BUFEER_SIZE,stdin)!=NULL)
        printf("%d\n",evaluate(temp_string));
    return;
}

int evaluate(char* expression){
    if(expression[strlen(expression)-1]=='\n')
        expression[strlen(expression)-1]=0;
    char **temp=(char**)malloc(sizeof(char)*BUFEER_SIZE);
    int i=0;
    int temp1,temp2;
    stack* st=stack_new();
    char array[100][100],*a;
    strcpy(array[i],strtok_r(expression," ",temp));
    while(array[i]!=NULL && temp[0][0]!=0){
        a=strtok_r(NULL," ",temp);
        strcpy(array[++i],a);
    }
    i=0;
//    while(array[i][0]!=0)
//        printf("%s ",array[i++]);
    while(array[i][0]!=0){
        if(!strcmp(array[i],"+")){
            temp1=stack_pop(st);
            temp2=stack_pop(st);
            stack_push(st,temp1+temp2);
        }
        else if(!strcmp(array[i],"-")){
            temp1=stack_pop(st);
            temp2=stack_pop(st);
            stack_push(st,temp2-temp1);
        }
        else if(!strcmp(array[i],"*")){
            temp1=stack_pop(st);
            temp2=stack_pop(st);
            stack_push(st,temp1*temp2);
        }
        else if(!strcmp(array[i],"/")){
            temp1=stack_pop(st);
            temp2=stack_pop(st);
            stack_push(st,temp2/temp1);
        }
        else if(!strcmp(array[i],"|")){
            temp1=stack_pop(st);
            temp2=stack_pop(st);
            stack_push(st,temp1|temp2);
        }
        else if(!strcmp(array[i],"&")){
            temp1=stack_pop(st);
            temp2=stack_pop(st);
            stack_push(st,temp1&temp2);
        }
        else if(!strcmp(array[i],"^")){
            temp1=stack_pop(st);
            temp2=stack_pop(st);
            stack_push(st,temp2^temp1);
        }
        else if(!strcmp(array[i],"%")){
            temp1=stack_pop(st);
            temp2=stack_pop(st);
            stack_push(st,temp2%temp1);
        }
        else{
            stack_push(st,atoi(array[i]));
        }
        i++;
    }
    return llist_get(st->top,0);
}
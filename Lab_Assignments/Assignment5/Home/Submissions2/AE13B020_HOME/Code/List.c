#include "List.h"
#include <stdlib.h>
#include <stdio.h>

Node *node_new(int data) {
    Node *head = (Node *) malloc(sizeof(Node));
    head->data = data;
    head->next = NULL;
    return head;
}

LList *llist_new() {
    LList *lst = (LList *) malloc(sizeof(LList));
    lst->head = NULL;
    return lst;
}

int llist_size(LList *lst) {
    int length = 0;
    Node *head = lst->head;
    while (head != NULL) {
        head = head->next;
        length++;
    }
    return length;
}

void llist_print(LList *lst) {
    Node *head = lst->head;
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
    return;
}

int llist_get(LList *lst, int idx) {
    Node *head = lst->head;
    int i = 0;
    while (head != NULL && i != idx) {
        head = head->next;
        i++;
    }
    if (head != NULL)
        return head->data;
    else
        return 0;
}

void llist_append(LList *lst, int data) {
    int size = llist_size(lst);
    Node *head = lst->head;
    Node *node = node_new(data);
    if (head == NULL) {
        lst->head = node;
        return;
    }
    if (head != NULL) {
        while (head->next != NULL)
            head = head->next;
    }
    head->next = node;
    return;
}

void llist_prepend(LList *lst, int data) {
    Node *node = node_new(data);
    node->next = lst->head;
    lst->head = node;
    return;
}

void llist_remove_last(LList *lst) {
    Node *head = lst->head;
    if (head == NULL)
        return;
    else if (head->next == NULL) {
        lst->head = NULL;
        return;
    }
    while (head->next->next != NULL)
        head = head->next;
    head->next = NULL;
    return;
}

void llist_remove_first(LList *lst) {
    lst->head = lst->head->next;
    return;
}

void llist_insert(LList *lst, int idx, int data) {
    Node *head;
    head = lst->head;
    Node *node = node_new(data);
    Node *temp_node = (Node *) malloc(sizeof(Node));
    int i = 0;
    if (idx == 0) {
        lst->head = node;
        if (head != NULL)
            node->next = head;
        return;
    }
    else if (idx == 1) {
        if (head->next != NULL) {
            temp_node = head->next;
            head->next = node;
            node->next = temp_node;
        }
        else
            head->next = node;
        return;
    }
//    head=head->next;
    while (i < idx - 1) {
        if (head->next->next == NULL)
            break;
        head = head->next;
        i++;
    }
    if (head->next->next != NULL) {
        temp_node = head->next;
        head->next = node;
        node->next = temp_node;
        return;
    }
    else {
        head->next->next = node;
        return;
    }
}

void llist_remove(LList *lst, int idx) {
    Node *head = lst->head;
    Node *temp_node = (Node *) malloc(sizeof(Node));
    if (idx == 0) {
        llist_remove_first(lst);
        return;
    }
    else if (idx == 1) {
        if (head->next != NULL) {
            if (head->next->next != NULL) {
                temp_node = head->next->next;
                head->next = temp_node;
                return;
            }
            else {
                head->next = NULL;
                return;
            }
        }
        else {
            head->next = NULL;
            return;
        }
    }
    int i = 2;
    while (i <= idx) {
        if (head->next->next == NULL)
            break;
        head = head->next;
        i++;
    }
    if (head->next->next != NULL) {
        temp_node = head->next->next;
        head->next = temp_node;
        return;
    }
    else {
        head->next = NULL;
        return;
    }
}



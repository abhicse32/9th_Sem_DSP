#include <stdio.h>
#include <stdlib.h>
#include "List.h"

Node* node_new(int data) {
	Node *node = (Node*) malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node;
}

LList* llist_new() {
	LList *list = (LList*) malloc(sizeof(LList));
	list->head = NULL;
	return list;
}

int llist_size(LList* lst) {
	Node *tmp = lst->head;
	int size = 0;
	while (tmp != NULL) {
		size++;
		tmp = tmp->next;
	}
	return size;
}

void llist_print(LList* lst) {
	Node *tmp = lst->head;
	while (tmp != NULL) {
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
}

int llist_get(LList* lst, int idx) {
	Node *tmp = lst->head;
	int i = 0;
	int size = llist_size(lst);
	if (idx >= size || idx < 0) {
		return -1;
	}
	while (i != idx) {
		tmp = tmp->next;
		i++;
	}
	return tmp->data;
}

void llist_append(LList* lst, int data) {
	Node *new = node_new(data);
	if (lst->head == NULL) {
		lst->head = new;
		return;
	}
	Node *tmp = lst->head;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = new;
}

void llist_prepend(LList* lst, int data) {
	Node *new = node_new(data);
	new->next = lst->head;
	lst->head = new;
}

void llist_insert(LList* lst, int idx, int data) {
	int size = llist_size(lst);
	if (idx > size || idx < 0) {
		return;
	} else if (idx == 0) {
		llist_prepend(lst, data);
		return;
	}
	Node *new = node_new(data);
	Node *tmp = lst->head;
	int i = 0;
	while (i != idx - 1) {
		tmp = tmp->next;
		i++;
	}
	new->next = tmp->next;
	tmp->next = new;
}

void llist_remove_last(LList* lst) {
	if (lst->head == NULL) {
		return;
	} else if ((lst->head)->next == NULL) {
		lst->head = NULL;
		return;
	}
	Node *tmp = lst->head;
	while ((tmp->next)->next != NULL) {
		tmp = tmp->next;
	}
	free(tmp->next);
	tmp->next = NULL;
}

void llist_remove_first(LList* lst) {
	if (lst->head == NULL) {
		return;
	}
	Node *tmp = lst->head;
	lst->head = tmp->next;
	free(tmp);
}

void llist_remove(LList* lst, int idx) {
	int size = llist_size(lst);
	if (idx >= size || idx < 0) {
		return;
	} else if (idx == 0) {
		llist_remove_first(lst);
		return;
	}
	Node *tmp = lst->head;
	int i = 0;
	while (i != idx - 1) {
		tmp = tmp->next;
		i++;
	}
	Node *rm = tmp->next;
	tmp->next = (tmp->next)->next;
	free(rm);
}

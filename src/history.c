#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List *init_history() {
  List *list = (List *) malloc(sizeof(List));
  list->root = malloc(sizeof(Item));
  list->last = malloc(sizeof(Item));
  return list;
}

void add_history(List *list, char *str, int i) {
  if (list->root->str == 0) {
    list->root->str = str;
    list->root->id = i;
    list->last = list->root;
  } else {
    list->last->next = malloc(sizeof(Item));
    list->last->next->str = str;
    list->last->next->id = i;
    list->last = list->last->next;
    list->last->next = 0;
  }
}
char *get_history(List *list, int id) {
  Item *dummy = malloc(sizeof(Item));
  dummy = list->root;
  while (dummy != 0) {
    if (dummy->id == id) {
      char *s = dummy->str;
      printf("the item at %d is: ", id);
      printf("%s", dummy->str);
      free(dummy);
      return s;
    }
    dummy = dummy->next;
  }
  free(dummy);
  return "item not found";
}

void print_history(List *list) {
  Item *dummy = malloc(sizeof(Item));
  dummy = list->root;
  while (dummy != 0) {
    printf("> at id %d: %s\n", dummy->id, dummy->str);
    dummy = dummy->next;
  }
  free(dummy);
}

void free_history(List *list) {
  Item *p = list->root;
  Item *temp;
  while (p->next) {
    temp = p->next;
    free(p->str);
    free(p);
    //p = p->next;
    p = temp;
    }
  free(p);
  //free(list);
}

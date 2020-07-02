#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List *init_history() {
  List *list = (List *) malloc(sizeof(List));
  //creating space with size of Item
  list->root = malloc(sizeof(Item));
  list->last = malloc(sizeof(Item));
  return list;
}

void add_history(List *list, char *str) {
  if (list->root->str == 0) {
    list->root->str = str;
    list->root->id = 0;
    list->last = list->root;
  } else {
    //creating space for a new Item
    list->last->next = malloc(sizeof(Item));
    list->last->next->str = str;
    list->last->next->id = list->last->id+1;
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

//iterating through the list
void print_history(List *list) {
  Item *itr = list->root;
  while (itr) {
    printf("> at id %d: %s\n", itr->id, itr->str);
    itr = itr->next;
  }
  printf("finished printing history\n");
}

void free_history(List *list) {
  Item *p = list->root;
  Item *temp;
  //frees the first Item of the list and iterates to the next Item
  while (temp) {
    temp = p->next;
    free(p->str);
    free(p);
    p = temp;
    }
  list->root = 0;
}

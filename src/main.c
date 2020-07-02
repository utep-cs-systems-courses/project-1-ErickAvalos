#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

void main(void) {
  char in_one[100]; //for first user input
  char in_two[100]; //for second user input
  List *history = init_history();
  char **tokens;

  //handling first input
  printf("%s", "> ");
  fgets(in_one, 101, stdin);
  tokens = tokenize(in_one);
  print_tokens(tokens);
  add_history(history, in_one);
  free_tokens(tokens);

  //handling second input
  printf("%s", "> ");
  fgets(in_two, 101, stdin);
  tokens = tokenize(in_two);
  print_tokens(tokens);
  add_history(history, in_two);
  free_tokens(tokens);

  //printing history of user input
  print_history(history);
  free_history(history);
  //print_history(history);
    
}

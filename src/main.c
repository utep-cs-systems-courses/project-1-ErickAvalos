#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

void main(void) {
  char in[100];
  List *history = init_history();


  char **tokens;
  int i = 0;
  //while(1) {
    printf("%s", "> ");
    fgets(in, 101, stdin);

    tokens = tokenize(in);
    print_tokens(tokens);
    while (*tokens != 0) {
      
      add_history(history, *tokens++, i++);
    }
  
    print_history(history);
    free_tokens(tokens);
    //}
    
    //print_tokens(tokens);
    //printf("after free tokens\n");
    //free_history(history);
    print_history(history);
    
}

//#ifndef _TOKENIZER_
#define _TOKENIZER_
#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c) {
  if (c == ' ' || c == '\t' || c == '\0') {
    return 1;
  } else {
    return 0;
  }
}

int non_space_char(char c) {
  if (c == ' ' || c == '\t' || c == '\0') {
    return 0;
  } else {
    return 1;
  }
}

char *word_start(char *str) {
  while (space_char(*str)) {
    str++;
  }
  return str;
}

char *word_terminator(char *word) {
  while (non_space_char(*word)) {
    word++;
  }
  return word;
}

int count_words(char *str) {
  int count = 0;
  char *temp;
  temp = str;
  while (*str) {
    str = word_start(str);
    str = word_terminator(str);
    count++;
  }
  
  /*
  printf("number of words %d\n", count);
  */
    
  return count;
}

char *copy_str(char *inStr, short len) {
  int i = 0;
  char *p;
  p = (char *) malloc(sizeof(char)*(len+1));
  while (i < len) {
    p[i] = inStr[i];
    i++;
  }
  p[i] = '\0';
  return p;
}

char **tokenize(char *str) {
  /*
  //begin test
  printf("from tokenize: ");
  printf(str);
  //end test
  */
  
  int size = count_words(str);

  /*
  printf("%d", size);
  */
    
  char **p = (char **) malloc(sizeof(char *)*(++size));
  int i = 0;
  int difference = 0;
  while (i < size-1) {
    str = word_start(str);
    difference = word_terminator(str) - str;
    p[i] = copy_str(str, difference);
    str = word_terminator(str);
    i++;
  }
  p[i] = 0;
  return p;
}

void print_tokens(char **tokens) {
  int i = 0;
  while (*tokens) {
    printf("tokens[%d] = %s\n", i++, *tokens++);
  }
  printf("tokens[%d] = %s\n", i, *tokens);
}

void free_tokens(char **tokens) {
  int i = 0;
  while (tokens[i]) {
    free(tokens[i]);
    i++;
  }
  
  free(tokens);
}

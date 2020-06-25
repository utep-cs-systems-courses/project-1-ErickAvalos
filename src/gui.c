#include <stdio.h>
#include <stdlib.h>
#define string_size 100

char *gui() {
  char str[string_size];
  char *s;
  printf("$");
  s = fgets(str, string_size, stdin);
  printf("%s", s);
  return s;
}

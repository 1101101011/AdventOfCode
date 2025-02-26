#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *file;
  int floor = 0, current = 0;
  char input;

  file = fopen("input.txt", "r");
  if (file == NULL) {
    printf("File not found\n");
    return 1;
  }

  while ((input = fgetc(file)) != EOF) {

  }
  return 0;
}

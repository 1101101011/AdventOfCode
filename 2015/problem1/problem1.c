#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *part1, *part2;
  int floor = 0, current = 0;
  char input;

  part1 = fopen("input.txt", "r");
  part2 = fopen("input.txt", "r");
  if (part1 == NULL || part2 == NULL) {
    printf("File not found\n");
    return 1;
  }

  while ((input = fgetc(part1)) != EOF) {
    /* if (input=='('){
      floor++;
    } else if (input==')') {
      floor--;
    } */
    floor = (input == '(') ? floor + 1 : input == ')' ? floor - 1 : floor + 0;
  }
  printf("Part 1\n");
  printf("The floor is: %d\n", floor);
  fclose(part1);
  floor = 0;
  while ((input = fgetc(part2)) != EOF) {
    if (floor >= 0) {
      floor = (input == '(') ? floor + 1 : input == ')' ? floor - 1 : floor + 0;
      current++;
    } else if (floor == -1) {
      break;
    }
  }
  printf("\nPart 2\n");
  printf("The floor is: %d\n", current);
  fclose(part2);
  return 0;
}

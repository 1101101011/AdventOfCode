#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *sort(int a[], int len) {
  int *num = malloc(len * sizeof(int));
  for (int i = 0; i < len; i++) {
    num[i] = a[i];
  }
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (num[i] > num[j]) {
        int temp = num[i];
        num[i] = num[j];
        num[j] = temp;
      }
    }
  }
  return num;
}

int main() {
  FILE *file = fopen("input.txt", "r");
  char list1[100], list2[100];
  int a[100], b[100], len, sum = 0, *left, *right, totalDistance = 0;
  while (fscanf(file, "%s %s", list1, list2) != EOF) {
    for (int i = 0; i < strlen(list1); i++) {
      a[i] = list1[i] - '0';
      b[i] = list2[i] - '0';
    }
    left = sort(a, strlen(list1));
    right = sort(b, strlen(list2));
    for (int i = 0; i < strlen(list1); i++) {
      int distance = left[i] - right[i];
      if (distance < 0) {
        distance *= -1;
      }
      sum += distance;
    }
    free(left);
    free(right);
    printf("Distance: %d\n", sum);
    totalDistance += sum;
    sum = 0;
  }
  printf("Total distance: %d\n", totalDistance);
  //expected output : 1530215
  fclose(file);
  return 0;
}

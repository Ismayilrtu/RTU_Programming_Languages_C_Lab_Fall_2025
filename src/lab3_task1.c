/*
 * Lab 3, Task 1
 * Student Name, Student ID
 *
 * Implement array algorithms:
 *   - find minimum value
 *   - find maximum value
 *   - calculate sum
 *   - calculate average
 *
 * Rules:
 *   - Write separate functions for each operation.
 *   - Work with int arrays.
 *   - Average should return a float.
 *
 * Example:
 *   int arr[] = {1, 2, 3, 4, 5};
 *   min = array_min(arr, 5); // 1
 *   max = array_max(arr, 5); // 5
 *   sum = array_sum(arr, 5); // 15
 *   avg = array_avg(arr, 5); // 3.0
 */

#include <limits.h>
#include <stdio.h>

// Function prototypes
int array_min(int arr[], int size);
int array_max(int arr[], int size);
int array_sum(int arr[], int size);
float array_avg(int arr[], int size);

int main(void) {
  int arr[] = {10, 20, 5, 30, 15};
  int size = 5;

  printf("Min: %d\n", array_min(arr, size));
  printf("Max: %d\n", array_max(arr, size));
  printf("Sum: %d\n", array_sum(arr, size));
  printf("Avg: %.2f\n", array_avg(arr, size));

  return 0;
}

// Implement functions below

// minimum axtarış, sadəcə ilk elementi götürüb sonra müqayisə edirik
int array_min(int arr[], int size) {
  int m = arr[0];  // assume first is min
  for (int i = 1; i < size; i++) {
    if (arr[i] < m) {
      m = arr[i];
    }
  }
  return m;
}

// maximum axtarış, eyni qayda
int array_max(int arr[], int size) {
  int m = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] > m) {
      m = arr[i];
    }
  }
  return m;
}

// elementləri bir-bir toplayırıq
int array_sum(int arr[], int size) {
  int s = 0;
  for (int i = 0; i < size; i++) {
    s = s + arr[i];  // toplama
  }
  return s;
}

// orta = cəm / say
float array_avg(int arr[], int size) {
  int s = array_sum(arr, size);  // reuse sum
  float avg = (float)s / size;
  return avg;
}

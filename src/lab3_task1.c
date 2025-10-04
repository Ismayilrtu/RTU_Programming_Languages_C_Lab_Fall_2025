/*
 * Lab 3, Task 1
 * Student Name, Student ID
 *
 * Perform operations on an array:
 *   - find minimum value
 *   - find maximum value
 *   - calculate sum
 *   - calculate average
 *
 * Rules:
 *   - Write a separate function for each operation.
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

  printf("Minimum element of the array: %d\n", array_min(arr, size));
  printf("Maximum element of the array: %d\n", array_max(arr, size));
  printf("Sum of the array elements: %d\n", array_sum(arr, size));
  printf("Average of the array elements: %.2f\n", array_avg(arr, size));

  return 0;
}

// Find the minimum element in the array
int array_min(int arr[], int size) {
  int min = arr[0];  // assume first element is the minimum
  for (int i = 1; i < size; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
  }
  return min;
}

// Find the maximum element in the array
int array_max(int arr[], int size) {
  int max = arr[0];  // assume first element is the maximum
  for (int i = 1; i < size; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

// Calculate the sum of all elements
int array_sum(int arr[], int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += arr[i];  // add each element to sum
  }
  return sum;
}

// Calculate the average of elements
float array_avg(int arr[], int size) {
  int sum = array_sum(arr, size);  // reuse the sum function
  float avg = (float)sum / size;
  return avg;
}

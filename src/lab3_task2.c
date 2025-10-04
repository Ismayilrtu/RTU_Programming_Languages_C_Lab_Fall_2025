/*
 * Lab 3, Task 2
 * Student Name, Student ID
 *
 * Practice using pointers as function parameters.
 * Implement:
 *   - swap (exchange values of two ints)
 *   - modify_value (multiply given int by 2)
 *
 * Rules:
 *   - Use pointers to modify variables in the caller.
 *   - Demonstrate changes in main.
 *
 * Example:
 *   int a = 5, b = 10;
 *   swap(&a, &b);   // now a = 10, b = 5
 *
 *   modify_value(&a); // now a = 20
 */

#include <stdio.h>

// Function prototypes
void swap(int *x, int *y);
void modify_value(int *x);

int main(void) {
  int a = 3, b = 7;

  // Show values before swap
  printf("Before swap: a = %d, b = %d\n", a, b);

  // Swap the values using pointers
  swap(&a, &b);
  printf("After swap: a = %d, b = %d\n", a, b);

  // Modify a by multiplying it by 2
  modify_value(&a);
  printf("After modify_value: a = %d\n", a);

  return 0;
}

// Swap the values of two integers using pointers
void swap(int *x, int *y) {
  int tmp = *x;  // temporarily store the value of x
  *x = *y;       // assign y's value to x
  *y = tmp;      // put original x value into y
}

// Multiply the value pointed to by x by 2
void modify_value(int *x) {
  *x = (*x) * 2;  // double the value
}

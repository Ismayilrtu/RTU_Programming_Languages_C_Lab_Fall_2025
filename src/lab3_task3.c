/*
 * Lab 3, Task 3
 * Student Name, Student ID
 *
 * Implement basic string handling functions.
 * Write your own versions of:
 *   - my_strlen (finds the length of a string)
 *   - my_strcpy (copies string from src to dest)
 *
 * Rules:
 *   - Do not use <string.h> functions like strlen/strcpy.
 *   - Use loops and manual pointer/array access.
 *
 * Example:
 *   char s[] = "hello";
 *   int len = my_strlen(s);   // should return 5
 *
 *   char buffer[100];
 *   my_strcpy(buffer, s);     // buffer now contains "hello"
 */

#include <stdio.h>

// Function prototypes
int my_strlen(const char *str);
void my_strcpy(char *dest, const char *src);

int main(void) {
  char test[] = "Programming in C";
  char copy[100];

  // Calculate length of the string
  int len = my_strlen(test);
  printf("Length: %d\n", len);

  // Copy string into another buffer
  my_strcpy(copy, test);
  printf("Copy: %s\n", copy);

  return 0;
}

// Returns the length of a string
int my_strlen(const char *str) {
  int count = 0;
  // count characters until null terminator
  while (str[count] != '\0') {
    count++;
  }
  return count;
}

// Copies string from src to dest
void my_strcpy(char *dest, const char *src) {
  int i = 0;
  // copy characters one by one
  while (src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }
  // make sure to terminate dest with '\0'
  dest[i] = '\0';
}

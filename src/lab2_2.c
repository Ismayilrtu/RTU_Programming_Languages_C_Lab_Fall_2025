#include <stdio.h>

/*
    Task:
    Write a function `long long factorial(int n)` that computes n!
    using a loop (not recursion).

    In main():
      - Ask user for an integer n
      - If n is negative, print an error and exit
      - Otherwise, call factorial and print the result
*/

long long factorial(int n) {
  //  compute factorial iteratively
  long long result = 1;

  for (int i = 2; i <= n; i++) {
    result *= i;
  }

  return result;
}

int main(void) {
  int n;

  printf("Enter a non-negative integer n: ");
  scanf("%d", &n);

  // validate input, call function, print result
  if (n < 0) {
    printf("Error: Factorial is not defined for negative numbers.\n");
    return 1;
  }

  long long result = factorial(n);
  printf("Factorial of %d is: %lld\n", n, result);

  return 0;
}

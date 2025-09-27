#include <stdio.h>

/*
    ============================================
    Task:
    Write a function `int is_prime(int n)` that returns 1 if n is prime,
    0 otherwise.

    In main():
      - Ask user for an integer n (>= 2)
      - If invalid, print an error
      - Otherwise, print all prime numbers up to n
    ============================================
*/

// Checks if n is prime by testing divisors up to sqrt(n)
int is_prime(int n) {
  if (n < 2) return 0;

  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return 0;  // Not prime if divisible
    }
  }

  return 1;  // Prime if no divisors found
}

int main(void) {
  int n;

  // Welcome message
  printf("Prime Number Finder \n");
  printf("Please enter an integer (≥ 2) to see all prime numbers up to it:\n");

  // Get user input
  printf("Your number: ");
  scanf("%d", &n);

  // Validate input
  if (n < 2) {
    printf(" Warning %d is less than 2, which is the smallest prime number.\n",
           n);
    printf("Please run the program again with a valid number.\n");
    return 1;  // Exit with error
  }

  // Print primes header
  printf("\n  Prime numbers from 2 up to %d:\n", n);

  // Loop through numbers and print primes
  for (int i = 2; i <= n; i++) {
    if (is_prime(i)) {
      printf("%d ", i);
    }
  }

  printf("\n\n All done! Thanks for using the Prime Number Finder.\n");

  return 0;  // Successful exit
}

 /* exp_calculator is a program that calculates
 * a positive base raised to a positive exponent
 * using a recursive algorithm in logarithmic time.
 *
 * Author: Ali Al-Musawi
 * CS 2211a - Assignment 2
 * Fall 2019
 *
 */

 #include <stdio.h>
 #include <stdbool.h>

float exponentiate(float base, int exponent);
int main() {
  float base;
  int exponent;
  do {
  printf("Enter a positive number which you want to raise to a power (i.e. the base): \n");
  scanf("%f", &base);
  if (base <= 0) {
    printf("Invalid input. The base must be greater than zero.\n");
  }
  else break;
  }
  while(true);
  
  do {
    printf("Enter a non-negative integer power (i.e. exponent) to which you want to raise the base to: \n");
    scanf("%d", &exponent);
    if (exponent < 0) {
      printf("Invalid input. The exponent must be greater than or equal to zero.\n");
    }
    else break;
  }
  while(true);
  printf("%f raised to the power %d is: %f \n", base, exponent, exponentiate(base, exponent));
  return 0;
}

/*
 * Function: exponentiate
 * ----------------------------------
 * Recursively raises a base to an exponent.
 * Uses the formula: 
 * a^n = (a^(n/2))^2 for even n
 * a^n = (a^((n-1)/2)^2)*a for odd n
 *
 * base: A positive real number to raise to a power.
 * exponent: A non-negative integer that is used as a power of the base.
 *
 * Returns: The base multiplied by itself n times, where n = exponent.
 */

float exponentiate(float base, int exponent) {
  if ((exponent % 2) == 0) {
    return (exponentiate(base, exponent/2)*exponentiate(base, exponent/2));
  }
  else {
    if (exponent==1) return base;
    else return (base*exponentiate(base, (exponent - 1)/2)*exponentiate(base, (exponent - 1)/2));
  }

}


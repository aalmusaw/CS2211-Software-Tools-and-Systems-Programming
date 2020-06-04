#include <stdio.h>
#include "euler.h"

int main(void) {
double epsilon, e;
printf("Hello! Enter your maximum error tolerance to estimate euler's number: ");
scanf("%lf", &epsilon);
e = compute_e(epsilon);
printf("\nThe estimated value of e with %.15f error is: \n%.14f", epsilon, e);
printf("\nExiting...\n"); 
}

// Input: n, an integer to compute its factorial.
// Output: n!, the factorial of n: n*(n-1)*...*3*2*1.
long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    else return n*factorial(n-1);
}

// Input: error, the maximum error tolerated in the approximation.
// Output: Approximation of euler number using its Maclurin Series.
double compute_e(double error) {
    double e = 0.0;
    int n = 0;
    int done = 0;
    while((double) (1.0/factorial(n)) >= error) n++;
    for(int i = 0; i < n; i++) e += ((double) (1.0/factorial(i)));
    return e;
}
    
    

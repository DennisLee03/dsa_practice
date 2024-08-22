/**
 * greatest common divisor of 2 natural number
 */
#include<stdio.h>

// prototype declaration
int gcd(int a, int b);

int main(void) {
// local definition
    int gcd_ans;
    int a, b;

// statements
    printf("Enter \'(a,b)\' to calculate the greatest common divisor\n");
    printf("==========\n");

    scanf("(%d,%d)", &a, &b);
    printf("ans = %d\n", gcd(a,b));

    printf("==========\n");

    return 0;
}

/**
 * ========== gcd ==========
 * calculate greatest common divisor using the Euclidean algorithm
 *     pre:  a and b are positive integers greater than 0
 *     post: greatest common divisor returned
 */
int gcd(int a, int b) {
// special base case:
    if(a == 0) {
        return b;
    }

// base case:
    if(b == 0) {
        return a;
    }

// general case:
    int r = a % b;
    return gcd(b, r);
}

/**
 * a / b = q ... r
 * a = b*q + r
 * (a, b) = (b, r) recursive relationship 
 */
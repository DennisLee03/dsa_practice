#include<stdio.h>

int iter_gcd(int a, int b) {

    int r;

    for(;;) {
        if(b == 0) break;

        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main(void) {
    int a, b;

    scanf("%d,%d", &a, &b);

    printf("(%d,%d) = %d", a, b, iter_gcd(a, b));

    return 0;
}
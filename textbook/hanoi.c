/**
 * towers of hanoi
 */

#include<stdio.h>

// prototype declaration
void hanoi(int n, char src, char dst, char aux); 

int main(void) {
// local definition
    int numDisks;

// statements
    printf("Enter number of disks: ");
    scanf("%d", &numDisks);

    printf("====================\n");

    hanoi(numDisks, 'A', 'C', 'B');

    printf("====================\n");

    return 0;
}

/**
 * ========== hanoi ==========
 * move disks from src to dst recursively
 *     pre:  the towers(src, dst, aux) consist of n disks
 *     post: steps to be printed
 */
void hanoi(int n, char src, char dst, char aux) {
// local definition
   static int step = 0;

// base case: only 1 disk to be moved
    if(n == 1) {
        step += 1;
        printf("%c -> %c\t", src, dst);
        printf("(step %3d\n", step);
        return;
    }

// general case: n disks to be moved
    hanoi((n - 1), src, aux, dst);
    hanoi(1, src, dst, aux);
    hanoi((n - 1), aux, dst, src);
}
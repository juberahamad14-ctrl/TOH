#include <stdio.h>

// Tower of Hanoi function
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    // Base case: agar sirf 1 disk hai
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }

    // Step 1: (n-1) disks ko source se auxiliary rod par bhejo
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);

    // Step 2: Sabse badi disk (nth disk) ko source se target rod par bhejo
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);

    // Step 3: (n-1) disks ko auxiliary se target rod par bhejo
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n;

    // User se disks ki sankhya input lena
    printf("Enter the number of disks: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Please enter a valid positive integer.\n");
        return 1;
    }

    printf("\nSteps to solve Tower of Hanoi for %d disks:\n\n", n);

    // A = Source, C = Destination, B = Auxiliary (Helper)
    towerOfHanoi(n, 'A', 'C', 'B');

    // Total moves calculate karne ka formula: 2^n - 1
    long long total_moves = (1ULL << n) - 1;
    printf("\nTotal moves required: %lld\n", total_moves);

    return 0;
}

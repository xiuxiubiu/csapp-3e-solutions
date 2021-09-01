#include <stdio.h>

// Divide by power of 2. Assume 0 <= k <= w-1
int divide_power2(int x, int k) {
    int is_neg = x & (1 << 31);
    is_neg && (x = x + ((1 << k) - 1));
    return x >> k;
}

int main() {
    printf("%d, %d\n", -5/2, divide_power2(-5, 1));
    printf("%d, %d\n", 5/2, divide_power2(5, 1));
}
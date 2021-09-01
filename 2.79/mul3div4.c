#include <stdio.h>
#include <assert.h>

// Divide by power of 2. Assume 0 <= k <= w-1
int divide_power2(int x, int k) {
    int is_neg = x & (1 << 31);
    is_neg && (x = x + ((1 << k) - 1));
    return x >> k;
}

int mul3div4(int x) {
    int mul3 = (x << 1) + x;
    return divide_power2(mul3, 2);
}

int main() {
    int x = 0x87654321;
    assert(mul3div4(x) == x * 3 / 4);
    return 0;
}
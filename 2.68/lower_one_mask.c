#include <assert.h>

// 6 -> 0x3F
// 0011 1111 -> 0x3F
// 17 -> 0x1FFFF
// 0001 1111 1111 1111 1111 -> 0x1FFFF
int lower_one_mask(int n) {
    int w = sizeof(int) << 8;
    int mask = (1 << (w - 1)) >> (w - n - 1);
    return ~mask;
}

int main() {
    assert(lower_one_mask(6) == 0x3F);
    assert(lower_one_mask(17) == 0x1FFFF);
    return 0;
}
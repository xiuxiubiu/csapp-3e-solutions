/**
 * 难度4星 耗时37分钟 
**/
#include <assert.h>

int odd_ones(unsigned x) {
    x = x ^ (x >> 16);
    x = x ^ (x >> 8);
    x = x ^ (x >> 4);
    x = x ^ (x >> 2);
    x = x ^ (x >> 1);
    return (0x1 & x);
}

int main() {
    assert(odd_ones(0x10101011));
    assert(!odd_ones(0x01010101));
    return 0;
}
#include <assert.h>

/**
 * Return 1 when x can be represented as an n-bit, 2's-complement
 * number; 0 otherwise.
 * Assume 1 <= n <= w.
 * x是否能有n位的二进制补码表示
*/
int fits_bits(int x, int n);

int main() {
    assert(!fits_bits(0xFF, 8));
    assert(!fits_bits(~0xFF, 8));

    assert(fits_bits(0b0010, 3));
    assert(!fits_bits(0b1010, 3));
    assert(!fits_bits(0b0110, 3));

    assert(fits_bits(~0b11, 3));
    assert(!fits_bits(~0b01000011, 3));
    assert(!fits_bits(~0b111, 3));
    return 0;
}

int fits_bits(int x, int n) {
    /**
     * 假设n位补码可以表示x
     * 则将x左移w-n位后，则第n位为int的符号位
     * 此时右移w-n位，根据第n位判断0或1补齐位数，
     * 也就是移动后的值和x是相同的
    */
    int offset = (sizeof(int) << 3) - n;
    return !(x ^ (x << offset >> offset));
}
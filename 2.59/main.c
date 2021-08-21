#include <stdio.h>

int generate_a_word(int x, int y) {
    int mask = 0xFF;
    return (x & mask) | (y & ~mask);
}

int main() {
    printf("%.8X\n", generate_a_word(0x89ABCDEF, 0x76543210));
}
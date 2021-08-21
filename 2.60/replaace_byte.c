#include <stdio.h>

int is_little_endian();
unsigned replace_byte(unsigned x, int i, unsigned char b);
unsigned bit_replace_byte(unsigned x, int i, unsigned char b);

int main() {
    printf("%0.8X, %0.8X\n", replace_byte(0x12345678, 2, 0xAB), replace_byte(0x12345678, 0, 0xAB));
    printf("%0.8X, %0.8X\n", bit_replace_byte(0x12345678, 2, 0xAB), bit_replace_byte(0x12345678, 0, 0xAB));
}

int is_little_endian() {
    short x = 0x1122;
    typedef unsigned char * byte_pointer;
    byte_pointer p = (byte_pointer) &x;
    return p[0] == 0x22;
}

unsigned replace_byte(unsigned x, int i, unsigned char b) {

    int index = i;
    typedef unsigned char *byte_pointer;
    byte_pointer p = (byte_pointer) &x;

    // 检查i是否超出unsigned字节范围
    if (i >= sizeof(unsigned) || i < 0 ) {
        return x;
    }

    // 大端序
    if (!is_little_endian()) {
        index = sizeof(unsigned) - 1 - i;
    }
    p[index] = b;

    return x;
}

unsigned bit_replace_byte(unsigned x, int i, unsigned char b) {
    if (i >= sizeof(unsigned) || i < 0 ) {
        return x;
    }

    // 1byte = 8bit 第i个byte 就是i*8bit也就是i<<3bit
    unsigned mask = ((unsigned) 0xFF) << (i << 3);

    // 将x的第i个字节置位0x00
    // 将b右移i个字节的位i<<3
    // 将0x00和b取或设置第i个字节为b
    return (x & ~mask) | (b << (i << 3));
}
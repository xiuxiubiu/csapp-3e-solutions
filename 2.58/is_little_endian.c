#include <stdio.h>

int is_little_endian() {
    short x = 0x1122;
    typedef unsigned char *byte_pointer;
    byte_pointer p = (byte_pointer) &x;
    return p[0] == 0x22;
}

int main() {
    printf("%d\n", is_little_endian());
    return 0;
}


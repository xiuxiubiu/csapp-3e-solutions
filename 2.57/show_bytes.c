#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++)
        printf("%.2x", start[i]);
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

// 2.27 start

void show_short(short x) {
    show_bytes((byte_pointer) &x, sizeof(short));
}

void show_long(long x) {
    show_bytes((byte_pointer) &x, sizeof(long));
}

void show_double(double x) {
    show_bytes((byte_pointer) &x, sizeof(double));
}

// 2.27 end


int main() {
    int x = 100;

    /**
     * int:         100 
     * binary:      0110 0100
     */
    show_int(x);

    /**
     * decimal:     100.0
     * binary:      0110 0100
     * float:       0100 0010 1100 1000 0000 0000 0000 0000
     */
    show_float((float)x);

    /**
     * pointer: 0xABCDEF0123456789
     */
    show_pointer(&x);

    // 2.27 start

    show_short((short)x);

    show_long((long)x);

    show_double((double)x);

    // 2.27 end

    return 0;
}
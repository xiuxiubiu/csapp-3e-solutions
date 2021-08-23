#include <stdio.h>
#include <assert.h>
#include <limits.h>

int A(int x) {
    return !~x;
}

int B(int x) {
    return !x;
}

int C(int x) {
    // 左移(sizeof(int) - 1) * 8位只保留x的最低位字节 即0xAB000000
    // 将除最高位以外的位设置为1
    // 取反判断所有位是否为0
    return !~(x << ((sizeof(int) - 1) << 3) | 0x00FFFFFF);
}

int C_new(int x) {
    // 判断x和0xFFFFFF00取或的值是否所有位都为1
    return !~(x | ~0xFF);
}

int D(int x) {
    return !(x >> ((sizeof(int) - 1) << 3));
}

int main() {

    int all_bit_one = ~0;
    int all_bit_zero = 0;

    assert(A(all_bit_one));
    assert(!B(all_bit_one));
    assert(C(all_bit_one));
    assert(C_new(all_bit_one));
    assert(!D(all_bit_one));

    assert(!A(all_bit_zero));
    assert(B(all_bit_zero));
    assert(!C(all_bit_zero));
    assert(!C_new(all_bit_zero));
    assert(D(all_bit_zero));

    assert(!A(0x1234ff));
    assert(!B(0x1234ff));
    assert(C(0x1234ff));
    assert(C_new(0x1234ff));
    assert(D(0x1234ff));

    assert(!A(0x1234));
    assert(!B(0x1234));
    assert(!C(0x1234));
    assert(!C_new(0x1234));
    assert(D(0x1234));

    return 0;
}
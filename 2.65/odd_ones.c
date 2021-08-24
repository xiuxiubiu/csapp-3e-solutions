#include <assert.h>

int odd_ones(unsigned x) {
    /**
     * 利用异或不同的位为1相同为0的特性
     * 每次将未对比的位数的一半的位数进行对比
     * 将对应为1的位数俩俩相抵消
     * 则剩余的一半位数中为未抵消的位数
     * 继续进行对比，直至位数剩余1位
     * 若剩余的1位为1表示为1的位数俩俩相抵消后剩余1位即有奇数个为1的位
    **/
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
#include <assert.h>

unsigned srl(unsigned x, int k) {
    unsigned xsra = (int) x >> k;

    /**
     * xsra是否为正数 1正数 0负数
     * 0xF1234567 >> 3 = 1110 ...
     * 1 << (size(int) - 1) = 1000 ... 0000
     * (1110 ...) & (1000 ... 000) = 1000 ... 0000 负
     * (0001 ...) & (1000 ... 000) = 0000 ... 0000 正
    **/
    unsigned sign = !(1 << ((sizeof(int) << 3) - 1) & xsra);

    /**
     * 正数时逻辑右移和0取异或保留右移结果不变
     * 
     * 负数时使用算术右移的k位用1补齐故将前k位消除为0即为逻辑右移的结果
     * 即将0xFFFFFFFF左移w-k位即用1和前k位对齐使用异或消除
    **/
    unsigned mask = (-1 + sign) << ((sizeof(int) << 3) - k);

    return mask ^ xsra;
}

unsigned srl_new(unsigned x, int k) {
    unsigned xsra = (int) x >> k;

    // int类型总位数
    unsigned w = sizeof(int) << 3;

    // 将0xFFFFFFFF左移w-k位将前k位置为1
    unsigned mask = (int) -1 << (w - k);
    
    /**
     * 将mask取反将前k位置为0后k-w位置为1
     * 利用 1&0 = 0 将前k位置为0
     * 利用 1&1 = 1 保留后k-w位
    **/
    return (xsra & ~mask);
}

unsigned sra(int x, int k) {
    int xsrl = (unsigned) x >> k;

    /**
     * x是否为正数
     * 0xF1234567 >> 3 = 1110 ...
     * 1 << (size(int) - 1) = 1000 ... 0000
     * (1110 ...) & (1000 ... 000) = 1000 ... 0000 负
     * (0001 ...) & (1000 ... 000) = 0000 ... 0000 正
     * 取反后 1正数 0负数
    **/
    unsigned sign = !(1 << ((sizeof(int) << 3) - 1) & x);

    /**
     * 正数时逻辑右移和0取或保留右移结果不变
     * 
     * 负数时使用逻辑右移的k位会用0补齐故将前k位置为1即为算术右移的结果
     * 利用0|1 = 1将右移的k位置为1
     * 利用1|0 = 1将剩余的位数保留
     * 即使用111(k位)000(w-k位)取或
    **/
    unsigned mask = (-1 + sign) << ((sizeof(int) << 3) - k);

    return mask | xsrl;
}

int main() {

    unsigned test_unsigned = 0x12345678;
    int test_int = 0x12345678;

    assert(srl(test_unsigned, 4) == test_unsigned >> 4);
    assert(srl_new(test_unsigned, 4) == test_unsigned >> 4);
    assert(sra(test_int, 4) == test_int >> 4);

    test_unsigned = 0x87654321;
    test_int = 0x87654321;

    assert(srl(test_unsigned, 4) == test_unsigned >> 4);
    assert(srl_new(test_unsigned, 4) == test_unsigned >> 4);
    assert (sra (test_int, 4) == test_int >> 4);

    return 0;
}
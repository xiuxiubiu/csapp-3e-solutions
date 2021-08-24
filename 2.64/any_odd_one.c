#include <assert.h>

int any_odd_one(unsigned x) {
    /**
     * 假设int有32位
     * 则所有的奇数位为1的值为0xAAAAAAAA
     * mask和x取&将偶数位的值忽略
     * 若x中有奇数位为1则结果大于0
     * 两次!!将结果返回置为0或1
    **/
    unsigned mask = 0xAAAAAAAA;
    return !!(mask & x);
}

int main() {
    assert(any_odd_one(0x2));
    assert(!any_odd_one(0x4));
    return 0;
}
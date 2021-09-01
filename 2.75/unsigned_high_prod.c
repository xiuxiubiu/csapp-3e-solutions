#include <stdio.h>
#include <stdint.h>
#include <assert.h>

int signed_high_prod(int x, int y) {

    // 将x转换为int64_t防止乘法溢出
    // 使用int64_t保存x*y结果
    // 右移w位移除低w位
    int64_t r = (int64_t) x * y;
    return r >> (sizeof(int) << 3);
}

unsigned unsigned_high_prod(unsigned x, unsigned y) {
    int mask_x = x >> 31;
    int mask_y = y >> 31;
    int signed_prod = signed_high_prod(x, y);

    // 根据公式2.18推倒高w位
    return signed_prod + mask_x * y + mask_y * x + mask_x * mask_y * (1 << 31);
}

unsigned another_unsigned_high_prod(unsigned x, unsigned y) {
  uint64_t mul = (uint64_t) x * y;
  return mul >> 32;
}

int main() {

    unsigned x = 0x12345678;
    unsigned y = 0xFFFFFFFF;

    assert(another_unsigned_high_prod(x, y) == unsigned_high_prod(x, y));

    return 0;
}
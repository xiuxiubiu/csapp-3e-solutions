#include <stdio.h>
#include <assert.h>

int threefours(int x) {

    /**
     * x除以4则w-1 ~ 2位不会有精度损失
     * 01两位先除后乘会有精度的损失，且乘数越大结果相差越大
     * 
     * 先将w-1 ~ 2位除4乘3
     * 后将01两位乘三除4以避免结果的误差
    */

    int f = x & ~0x3;
    int fd4 = f >> 2;
    int fm3 = (fd4 << 1) + fd4;

    int l = x & 0x3;
    int lm3 = (l << 1) + l;
    int is_neg = x & (1 << 31);
    is_neg && (lm3 += (1 << 2) - 1);
    int ld4 = lm3 >> 2;

    return fm3 + ld4;
}

int main() {

    printf("%d, %d\n", 5 / 4 * 3, threefours(5));
    printf("%d, %d\n", -5 / 4 * 3, threefours(-5));

}
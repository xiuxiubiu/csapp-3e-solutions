#include <stdio.h>
#include <assert.h>
#include <limits.h>

// Determine whether arguments can be substracted without overflow
int tsub_ok(int x, int y) {
    int w = (sizeof(int) << 3) - 1;
    int r = x - y;

    // 正数 - 负数 = 负数 溢出
    int pos_over = !(x >> w) && (y >> w) && (r >> w);

    // 负数 - 正数 = 正数 溢出
    int neg_over = (x >> 2) && !(y >> w) && !(r >> w);

    return !pos_over && !neg_over;
}

int main() {

    assert(!tsub_ok(0x00, INT_MIN));
    assert(tsub_ok(0x00, 0x00));

return 0;
}
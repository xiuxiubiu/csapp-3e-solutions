#include <assert.h>
#include <stdio.h>
#include <limits.h>

// Addition that saturaties to TMin or TMax
int saturating_add(int x, int y) {

    size_t w = (sizeof(int) << 3) - 1;
    int r = x + y;

    /**
     * 正数 + 正数 = 负数 溢出
     * 正数右移(sizeof(int) << 3) - 1位为0
     * 负数右移(sizeof(int) << 3) - 1位为-1
     * 所以当 x >> w = 0, y >> w = 0 , r >> w = -1时 加法正溢出
    */
    int pos = !(x >> w) && !(y >> w) && (r >> w) ;

    /**
     * 负数 + 负数 = 正数 溢出
     * 负数右移(sizeof(int) << 3) - 1位为-1
     * 正数右移(sizeof(int) << 3) - 1位为0
     * 所以当 x >> w = -1, y >> w = -1 , r >> w = 0时 加法负溢出
    */
    int neg = x >> w && y >> w && !(r >> w);

    /**
     * !overflow * r
     * 根据是否溢出判断是否显示相加原结果
     * 
     * overflow * (INT_MAX + pos)
     * INT_MAX + 1 = INT_MIN
     * 当正溢出时INT_MAX + 0返回INT_MAX
     * 当负溢出时INT_MAX + 1返回INT_MIN
    */
    int overflow = pos || neg;
    return overflow * (INT_MAX + neg) + (!overflow * r);
}



// Addition that saturaties to TMin or TMax
int saturating_add_new(int x, int y) {

    size_t w = (sizeof(int) << 3) - 1;
    int r = x + y;

    /**
     * 正数 + 正数 = 负数 溢出
     * 正数右移(sizeof(int) << 3) - 1位为0
     * 负数右移(sizeof(int) << 3) - 1位为-1
     * 所以当 x >> w = 0, y >> w = 0 , r >> w = -1时 加法正溢出
    */
    int pos = !(x >> w) && !(y >> w) && (r >> w) ;

    /**
     * 负数 + 负数 = 正数 溢出
     * 负数右移(sizeof(int) << 3) - 1位为-1
     * 正数右移(sizeof(int) << 3) - 1位为0
     * 所以当 x >> w = -1, y >> w = -1 , r >> w = 0时 加法负溢出
    */
    int neg = x >> w && y >> w && !(r >> w);

    /**
     * 当正溢出时返回INT_MAX
     * 当负溢出时返回INT_MIN
    */
    (pos && (r = INT_MAX)) || (neg && (r = INT_MIN));

    return r;
}

int main() {

    assert(INT_MAX == saturating_add(INT_MAX, 0x1234));
    assert(INT_MIN == saturating_add(INT_MIN, -0x1234));
    assert(0x11 + 0x22 == saturating_add(0x11, 0x22));

    assert(INT_MAX == saturating_add_new(INT_MAX, 0x1234));
    assert(INT_MIN == saturating_add_new(INT_MIN, -0x1234));
    assert(0x11 + 0x22 == saturating_add_new(0x11, 0x22));

    return 0;
}

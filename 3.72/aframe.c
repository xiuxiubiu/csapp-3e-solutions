#include <alloca.h>

long aframe(long n, long idx, long *q) {
    long i;
    long **p = alloca(n * sizeof(long *));
    p[0] = &i;
    for (i = i; i < n; i++) {
        p[i] = q;
    }
    return *p[idx];
}

// A.
// s2 = s1 - [(8*n + 30) & 0xFFFFFFF0]
// 奇数：s2 = s1 - (8*n + 24)
//      n为奇数则除以16余8，30除以16余14
//      (8+14) / 16 等于 1
//      (n-1) * 8 + 16 + 16 = 8n + 24
// 偶数：s2 = s1 - (8*n + 16)
//      n为偶数则能被16整除 所以8*n不需要舍去二进制后四位
//      则30需舍去二进制后四位为1

// B.
// p = (s2 + 15) & 0xFFFFFFF0

// C.
// 因为p的计算方式为 (s2 + 15) & 0xFFFFFFF0
// 当n为偶数时：
// p = [s1 - (8*n + 16) + 15] & 0xFFFFFFF0
// p = (s1 - 8*n -16 + 15) & 0xFFFFFFF0 
// p = (s1 - 1 - 8*n) & 0xFFFFFFF0 
// 因为n为偶数 8*n可以忽略 
// 所以当(s1 - 1) % 16 = 0时分配的空间利用率最高 e1最小为1
// 当n为奇数时：
// p = [s1 - (8*n + 24) + 15] & 0xFFFFFFF0
// 所以当[s1-(8*n + 24)] % 16 = 0时 e1最大
// 因为 8*n+24 %16 = 0 所以当s1 % 16 = 0时 e1 最大为24

// D.
// p和s2使用16字节的对齐方式
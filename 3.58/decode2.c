// x in %rdi
// y in %rsi
// z in %rdx
long decode2(long x, long y, long z) {
    x = (y - z) * x; // %rdi
    long ly = (y << 63) >> 63;    // %rax
    return ly ^ x
}
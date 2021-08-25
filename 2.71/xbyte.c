#include <assert.h>

typedef unsigned packed_t;

// Extract byte from word.
// Return as signed integer.
int xbyte(packed_t word, int bytenum);

int main() {
    assert(xbyte(0x00112233, 0) == 0x33);
    assert(xbyte(0x00112233, 1) == 0x22);
    assert(xbyte(0x00112233, 2) == 0x11);
    assert(xbyte(0x00112233, 3) == 0x00);

    assert(xbyte(0xAABBCCDD, 0) == 0xFFFFFFDD);
    assert(xbyte(0xAABBCCDD, 1) == 0xFFFFFFCC);
    assert(xbyte(0xAABBCCDD, 2) == 0xFFFFFFBB);
    assert(xbyte(0xAABBCCDD, 3) == 0xFFFFFFAA);

    assert(xbyte(0xA0112233, 0) == 0xFFFFFF33);

    return 0;
}

int xbyte(packed_t word, int bytenum) {
    int w = sizeof(packed_t) - 1;
    
    /**
     * (word << ((w - bytenum) << 3) >> (w << 3))
     * 清空指定字节以外的所有字节为 0x000000XX形式
     * 
     * (((int) word >> (w << 3)) && ~0xFF)
     * 根据最高位判断使用0还是1补位然后将最低位字节设置为0 
     * 即0x00000000 或 0xFFFFFF00
     * 
     * 将两次结果取或即为保留word指定字节并根据word最高位判断正负生成的int
    */
    return (word << ((w - bytenum) << 3) >> (w << 3)) | (((int) word >> (w << 3)) & ~0xFF);
}
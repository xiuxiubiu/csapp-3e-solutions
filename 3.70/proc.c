union ele {

    struct {
        long *p;
        long y;
    } e1;

    struct {
        long x;
        union ele *next;
    } e2;
};

void proc (union ele *up) {
    up->e2.x = *(up->e2.next->e1.p) - up->e2.next->e1.y;
}

// A.
// e1.p 的偏移量 0
// e1.y 的偏移量 8
// e2.x 的偏移量 0
// e2.next 的偏移量 8

// B.
// 结构总共需要16个字节

// C.
// 见proc.s
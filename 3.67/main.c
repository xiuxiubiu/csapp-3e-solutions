typedef struct {
    long a[2];
    long *p;
} strA;

typedef struct {
    long u[2];
    long q;
} strB;

strB process(strA s) {
    strB r;
    r.u[0] = s.a[1];
    r.u[1] = s.a[0];
    r.q = *s.p;
    return r;
}

long eval(long x, long y, long z) {
    strA s;
    s.a[0] = x;
    s.a[1] = y;
    s.p = &z;
    strB r = process(s);
    return r.u[0] + r.u[1] + r.q;
}

// A.
// x in %rsp, y in %rsp+8, &z in %rsp+16, z in %rsp+24
// B.
// %rsp+64
// C.
// %rsp+offset
// D. 
// %rsp+64
// E.
// %rax = %rsp+64, %rdi = %rsp+64
// r.u[0] at %rsp+72, r.u[1] at %rsp+64, r.q at %rsp+80
// %rsp in process at %rsp-8 in eval

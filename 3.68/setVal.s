; void setVal(str1 *p, str2 *q)
; p in %rdi, q in %rsi
setVal:

    ; int占用4字节，char占用1字节
    ; array[B]对齐8字节
    ; 则
    ; 4 < B <= 8
    movslq  8(%rsi), %rax

    ; short占用2字节
    ; 32-12 = 20
    ; 则s[A]对齐占用20字节
    ; 10 < 2*A <= 20 
    ; 5 < A <= 10
    addq    32(%rsi), %rax

    ; x[A][B]对齐占用184字节
    ; 176 < 4*A*B <= 184
    ; 44 < A*B <= 46
    movq    %rax, 184(%rdi)
    ret
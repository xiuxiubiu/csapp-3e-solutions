; long aframe(long n, long idx, long *q)
; n in %rdi, idx in %rsi, q in %rdx
aframe:

    ; 保存%rbp
    pushq   %rbp

    ; %rsp放入%rbp
    movq    %rsp, %rbp

    ; 
    subq    $16, %rsp               ; Allocate space for i (%rsp = s1)

    ; 8*n + 30
    leaq    30(, %rdi, 8), %rax

    ; 0x...FFF0 8对齐 8n/8向上取整 + 1
    andq    %-16, %rax


    subq    %rax, %rsp              ; Allocate space for array p (%rsp = s2)
    leaq    15(%rsp), %r8
    andq    $-16, %r8               ; Set %r8 to &p[0]

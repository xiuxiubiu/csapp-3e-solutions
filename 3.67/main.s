; strB pocess(strA s)
process:
    ; %rsp = eval_%rsp - 8

    ; %rax = s.a[0]
    movq    %rdi, %rax

    ; 
    movq    24(%rsp), %rdx

    ; %rdx = z
    movq    (%rdx), %rdx

    ; %rcx = eval_%rsp + 8 = y
    movq    16(%rsp), %rcx

    ; eval_%rsp+64 = y
    movq    %rcx, (%rdi)

    ; %rcx = eval_%rsp = x
    movq    8(%rsp), %rcx

    ; eval_%rsp + 72 = x
    movq    %rcx, 8(%rdi)

    ; eval_%rsp + 80 = z
    movq    %rdx, 16(%rdi)
    ret

; long eval(long x, long y, long z)
; x in %rdi, y in %rsi, z in %rdx
eval:
    ; malloc 104 bytes
    subq    $104, %rsp

    ; z at %rsp + 24
    movq    %rdx, 24(%rsp)

    ; %rax = &z
    leaq    24(%rsp), %rax

    ; x at %rsp
    movq    %rdi, (%rsp)

    ; y at %rsp + 8
    movq    %rsi, 8(%rsp)

    ; &z at %rsp + 16
    movq    %rax, 16(%rsp)

    ; %rdi: first parameter, "s"
    leaq    64(%rsp), %rdi

    call    process
    movq    72(%rsp), %rax
    addq    64(%rsp), %rax
    addq    80(%rsp), %rax
    addq    $104, %rsp
    ret
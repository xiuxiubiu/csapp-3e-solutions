; long loop(long x, int n)
; x in %rdi, n in %esi
; A: x in %rdi, n in %esi, result in %rax, mask in % %rdx
; B: result = 0, mask = 1
; C: mask != 0
; D: maxk = mask << n
; E: result |= (mask & x)
; F: loop.c
loop:
    ; %ecx = n
    movl %esi, %ecx

    ; %edx = 1
    mov1 $1, %edx

    ; %eax = 0
    movl $0, %eax

    ; jump to .L2
    jmp .L2

.L3:
    ; %r8 = x
    movq %rdi, %r8

    ; %r8 = x & 1
    andq %rdx, %r8

    ; %rax = 0 | %r8
    orq %r8, %rax

    ; %rdx = %rax << %cl(%ecx)
    salq %cl, %rdx

.L2:
    ; %rdx & %rdx
    testq %rdx, %rdx

    ; ne zero
    jne .L3

    rep ret
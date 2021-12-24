; long sum_col(long n, long A[NR(n)][NC(n)], long j)
; n in %rdi, A in %rsi, j in %rdx
sum_col:
    ; %r8 = 4n+1
    leaq    1(, %rdi, 4), %r8

    ; %rax = 3n
    leaq    (%rdi, %rdi, 2), %rax

    ; %rdi = %rax = 3n
    ; NR = 3*n
    movq    %rax, %rdi

    ; %rax & %rax
    testq   %rax, %rax

    ; NR(n) <= 0 to .L4 
    jle     .L4

    ; first loop
    ; %r8 = (4n+1) << 3
    ; NC(n) * 8
    salq    $3, %r8

    ; %rcx = 8j + A
    ; A + NC(n)*8
    leaq    (%rsi, %rdx, 8), %rcx

    ; %eax = result = 0
    movl    $0, %eax

    ; i in %edx
    movl    $0, %edx

.L3:
    ; %rax = *%rcx + %rax
    ; %rcx = A[i][j]
    ; result += A[i][j]
    addq    (%rcx), %rax

    ; %rdx += 1
    ; i++
    addq    $1, %rdx

    ; %rcx = %rcx + %r8
    ; NC(n)*8
    addq    %r8, %rcx

    ; %rdx - %rdi
    ; NR(n) in %rdi
    cmpq    %rdi, %rdx

    ; ~ZF
    jne     .L3
    rep; ret

.L4:
    ; result = 0
    movl    $0, %eax
    ret
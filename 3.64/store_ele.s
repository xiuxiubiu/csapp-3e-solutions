; k + j * T + i * S * T = 13j + 65i + k
; T = 13
; S * T = 65, S = 5
; 3640 = R * S * T * 8, R = 3640 / (8 * 13 * 5) = 7

; long store_ele(long i, long j, long k, long *dest)
; i in %rdi, j in %rsi, k in %rdx, dest in %rcx
store_ele:

    ; %rax = 3j
    leaq    (%rsi, %rsi, 2), %rax

    ; %rax = 4 * 3j + j = 13j
    leaq    (%rsi, %rax, 4), %rax

    ; %rsi = i
    movq    %rdi, %rsi

    ; %rsi = i << 6 = 64i
    salq    $6, %rsi

    ; %rdi = %rsi + i = 65i
    addq    %rsi, %rdi

    ; %rdi = 13j + 65i
    addq    %rax, %rdi

    ; %rdx = 13j + 65i + k
    addq    %rdi, %rdx

    ; %rax = A + 8*(13j + 65i + k)
    movq    A(, %rdx, 8), %rax

    ; %rax = %rcx
    movq    %rax, (%rcx)

    ; return size
    movl    $3640, %eax
    ret
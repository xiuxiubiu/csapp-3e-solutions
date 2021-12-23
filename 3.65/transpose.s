.L6:
    ; %rcx = t = A[i][j] 
    movq    (%rdx), %rcx

    ; %rsi = A[j][i]
    movq    (%rax), %rsi

    ; %rdx = A[i][j] = A[j][i]
    movq    %rsi, (%rdx)

    ; %rax = %rcx = t
    movq    %rcx, (%rax)

    ; A[i][j] in %rdx
    ; j++, %rdx + 8
    addq    $8, %rdx

    ; A[j][i] in %rax
    ; j++, %rax + 120, 120/8 = 15, M = 15
    addq    $120, %rax

    ; i in %rax, j in %rdi
    cmpq    %rdi, %rax

    ; %rax - %rdi != 0
    jne     .L6
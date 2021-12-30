; void proc (union ele *up)
; up in %rdi

proc:

    ; y 或 *next
    movq    8(%rdi), %rax

    ; (%rax) 表示 %rax存储的是内存地址
    ; %rax 存储的是 *next
    ; %rdi = e2
    movq    (%rax), %rdx

    ; (%rdx) 表示 *next地址存储的内容也是指针
    ; *next = e1
    movq    (%rdx), %rdx

    ; %rax + 8  = e1 + 8 = y
    ; %rdx = e1 = *p
    ; *p - y
    subq    8(%rax), %rdx

    ; %rdi 为x的地址
    ; e1->x = *p-y
    movq    %rdx, (%rdi)
    ret
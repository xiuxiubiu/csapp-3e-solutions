; p1 in %rdi, p2 in %rsi, action in %edx

; MODE_E
.L8:
    ; %eax = 27
    ; result = 27
    movl $27, %eax
    ret

; MODE_A
.L3:
    ; %rax = *p2
    ; result = *p2
    movq (%rsi), %rax
    ; %rdx = *p1
    movq (%rdi), %rdx
    ; *p2 = *p1
    movq %rdx, (%rsi)
    ret

; MODE_B
.L5:
    ; %rax = *p1
    ; result = *p1
    movq (%rdi), %rax
    ; result = *p2 + *p1
    addq (%rsi), %rax
    ; *p2 = result
    movq %rax, (%rsi)
    ret

; MODE_C
.L6:
    ; *p1 = 59
    movq $59, (%rdi)
    ; result = *p2
    movq (%rsi), %rax
    ret

; MODE_D
.L7:
    ; result = *p2
    movq (%rsi), %rax
    ; *p1 = result
    movq %rax, (%rdi)
    ; result = 27
    movl $27, %eax

; default
.L9:
    ; result = 12
    movl $12, %eax
    ret

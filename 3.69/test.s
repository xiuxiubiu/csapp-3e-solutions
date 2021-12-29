; void test(long i, b_struct *bp)
; i in %rdi, bp in %rsi
0000000000000000 <test>:

    ; last在%rsi地址+288处
    0:  8b 8e 20 01 00 00       mov     0x120(%rsi), %ecx

    ; first在%rsi地址处
    ; n 存储在寄存器 %ecx
    6:  03 0e                   add     (%rsi), %ecx

    ; %rax = 5*i
    8:  48 8d 04 bf             lea     (%rdi, %rdi, 4), %rax

    ; %rsi = (%rsi) + 8*5*i
    ; 40*i 是 a[i]的size大小
    ; a_struct占用40字节
    c:  48 8d 04 c6             lea     (%rsi, %rax, 8), %rax

    ; 加上first对齐后的8字节 则为bp->a[i]的地址
    ; %rdx 存储 bp->a[i]的地址
    ; 所以CNT = (288-8)/40 = 7
   10:  48 8b 50 08             mov     0x8(%rax), %rdx

   ; int -> long
   ; ap->x为long[]类型
   14:  48 63 c9                movslq  %ecx, %rcx

   ; %rdx为idx的值
   ; (%rax + 8)为ap的地址，即idx地址，+0x10（16）为x的地址
   ; 所以x的长度为(40-8)/8 = 4
   ; idx为8位整型 long
   17:  48 89 4c d0 10          mov     %rcx, 0x10(%rax, %rdx, 8)
   1c:  c3                      req
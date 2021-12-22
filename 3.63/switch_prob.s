; (gdb) x/6gx 0x4006f8
; 0x4006f8: 0x00000000004005a1 0x00000000004005c3
; 0x400708: 0x00000000004005a1 0x00000000004005aa
; 0x400718: 0x00000000004005b2 0x00000000004005bf

; long switch_prob(long x, long n)
; x in %rdi, n in %rsi
400590 <switch_prob>:
400590: 48 83 ee 3c             sub  $0x3c, %rsi    ; %rsi = n - (3*16+12)
400594: 48 83 fe 05             cmp  $0x5, %rsi     ; %rsi - 5
400598: 77 29                   ja   4005c3 <switch_prob+0x33>  ; %rsi > 5 to 4005c3
40059a: ff 24 f5 f8 06 40 00    jmpq *0x4006f8(, %rsi, 8)   ; to 8*n + 0x00000000004005a1

; n = 60, 62
4005a1: 48 8d 04 fd 00 00 00    lea  0x0(, %rdi, 8), %rax   ; %rax = 8*x
4005a8: 00
4005a9: c3                      retq    ; return result

; n = 63
4005aa: 48 89 f8                mov  %rdi, %rax ; result = x
4005ad: 48 c1 f8 03             sar  $0x3, %rax ; result = result >> 3
4005b1: c3                      retq    ; return result

; n = 64
4005b2: 48 89 f8                mov  %rdi, %rax ; result = x
4005b5: 48 c1 e0 04             shl  $0x4, %rax ; result = result << 4
4005b9: 48 29 f8                sub  %rdi, %rax ; result = result - x
4005bc: 48 89 c7                mov  %rax, %rdi ; x = result

; n = 65
4005bf: 48 0f af ff             imul %rdi, %rdi ; x = x*x

; default
4005c3: 48 8d 47 4b             lea  $0x4b(%rdi), %rax   ; result = x+0x4b
4005c7: c3                      retq    ; return result

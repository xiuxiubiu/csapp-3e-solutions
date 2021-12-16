; typedef __int128 int128_t;
; void store_prod(int128_t *dest, int64_t x, int64_t y) {
;     *dest = x * (int128_t) y;
; }

; x_128 = x_128_high_64 * 2^64 + x
; y_128 = y_128_high_64 * 2^64 + y

; x_128的高64位由x的第64位决定
; x的第64位为0 则x和x_128为正数 则x_128_64为0
; x的第64位为1 则x和x_128为负数 则x_128_64为-1
; y同理
; x_128_high_64 = -1 * x_64(值为x第64位的64位二进制数)
; y_128_high_64 = -1 * y_64(值为y第64位的64位二进制数)

; 所以
; x_128 = -x_64 * 2^64 + x
; y_128 = -y_64 * 2^64 + y
; x_128 * y_128 = (-x_64*2^64 + x) * (-y_64*2^64 + y)
; x_128 * y_128 = -x_64 * -y_64 * 2^128 + (-x_64*2^64 * y) + x*y + (-y_64*2^64 * x)
; 2^128溢出为0
; x_128 * y_128 = x*y + (-x_64 * y + -y_64 * x) * 2^64
; x*y = x_128*y_128 - (-x_64*y + -y_64*x)*2^64

store_prod:

	; %rdx第三个参数
	; 保存第三个参数 y
	movq %rdx, %rax

	; 读出%rax的符号位，并复制到%rdx的所有位
	; %rdx为高64位 %rax为低64位
	; int128_t y = %rdx, %rax
	; y正数 %rdx = 0
	; y负数 %rdx = -1
	; %rdx = y_64(值为y第64位的64位二进制数)
	cqto

	; %rsi第二个参数 x
	; 保存第二个参数 x
	; %rcx = x
	movq %rsi, %rcx

	; x算术右移63位 保留符号
	; x >> 63 保存在%rcx中
	; 正0 x_64:0, 负-1 x_64:1
	; %rcx = -1 * x_64(值为x第64位的64位二进制数)
	sarq $63, %rcx
	
	; %rcx = y * -x_64
	; %rdx高64位 %rax低64位
	imulq %rax, %rcx

	; %rdx = x * (-y_64)
	imulq %rsi, %rdx

	; %rcx = y * (-x_64) + x * (-y_64)
	addq %rdx, %rcx

	; y * x 的128位表示
	; %rdx高64位
	; %rax低64位
	mulq %rsi

	; (-x_64*y + -y_64*x)*2^64则低64位为0
	; 所以只操作高64位即可
	; %rdx为高64位
	; x_128*y_128的高64位 %rdx + (-x_64*y + -y_64*x)
	addq %rcx, %rdx

	; 低64位保存在%rdi存储的内存地址中
	movq %rax, (%rdi)

	; 高64位保存在%rdi存储的地址+8的内存地址中
	movq %rdx, 8(%rdi)



	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 3	sdk_version 11, 3
	.globl	_store_ele                      ## -- Begin function store_ele
	.p2align	4, 0x90
_store_ele:                             ## @store_ele
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, %rax
	shlq	$9, %rax
	leaq	(%rax,%rdi,8), %rax
	addq	_A@GOTPCREL(%rip), %rax
	imulq	$104, %rsi, %rsi
	addq	%rax, %rsi
	movq	(%rsi,%rdx,8), %rax
	movq	%rax, (%rcx)
	movl	$3640, %eax                     ## imm = 0xE38
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.comm	_A,3640,4                       ## @A
.subsections_via_symbols

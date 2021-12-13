	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 3	sdk_version 11, 3
	.globl	_decode2                        ## -- Begin function decode2
	.p2align	4, 0x90
_decode2:                               ## @decode2
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rsi, %rax
	movq	%rsi, %rcx
	subq	%rdx, %rcx
	imulq	%rdi, %rcx
	andl	$1, %eax
	negq	%rax
	xorq	%rcx, %rax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols

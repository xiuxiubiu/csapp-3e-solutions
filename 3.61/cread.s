	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 3	sdk_version 11, 3
	.globl	_cread                          ## -- Begin function cread
	.p2align	4, 0x90
_cread:                                 ## @cread
	.cfi_startproc
## %bb.0:
	testq	%rdi, %rdi
	je	LBB0_1
## %bb.2:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	(%rdi), %rax
	popq	%rbp
	retq
LBB0_1:
	xorl	%eax, %eax
	retq
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols

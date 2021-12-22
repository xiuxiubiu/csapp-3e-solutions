	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 3	sdk_version 11, 3
	.globl	_switch3                        ## -- Begin function switch3
	.p2align	4, 0x90
_switch3:                               ## @switch3
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	cmpl	$4, %edx
	ja	LBB0_6
## %bb.1:
	movl	$27, %eax
	movl	%edx, %ecx
	leaq	LJTI0_0(%rip), %rdx
	movslq	(%rdx,%rcx,4), %rcx
	addq	%rdx, %rcx
	jmpq	*%rcx
LBB0_2:
	movq	(%rsi), %rax
	movq	(%rdi), %rcx
	movq	%rcx, (%rsi)
	popq	%rbp
	retq
LBB0_6:
	movl	$12, %eax
LBB0_7:
	popq	%rbp
	retq
LBB0_3:
	movq	(%rsi), %rax
	addq	(%rdi), %rax
	movq	%rax, (%rdi)
	popq	%rbp
	retq
LBB0_4:
	movq	$59, (%rdi)
	movq	(%rsi), %rax
	popq	%rbp
	retq
LBB0_5:
	movq	(%rsi), %rcx
	movq	%rcx, (%rdi)
	popq	%rbp
	retq
	.cfi_endproc
	.p2align	2, 0x90
	.data_region jt32
.set L0_0_set_2, LBB0_2-LJTI0_0
.set L0_0_set_3, LBB0_3-LJTI0_0
.set L0_0_set_4, LBB0_4-LJTI0_0
.set L0_0_set_5, LBB0_5-LJTI0_0
.set L0_0_set_7, LBB0_7-LJTI0_0
LJTI0_0:
	.long	L0_0_set_2
	.long	L0_0_set_3
	.long	L0_0_set_4
	.long	L0_0_set_5
	.long	L0_0_set_7
	.end_data_region
                                        ## -- End function
.subsections_via_symbols

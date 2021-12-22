	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 3	sdk_version 11, 3
	.globl	_switch_prob                    ## -- Begin function switch_prob
	.p2align	4, 0x90
_switch_prob:                           ## @switch_prob
	.cfi_startproc
## %bb.0:
	movq	%rdi, %rax
	leaq	-61(%rsi), %rcx
	cmpq	$4, %rcx
	ja	LBB0_6
## %bb.1:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	leaq	LJTI0_0(%rip), %rdx
	movslq	(%rdx,%rcx,4), %rcx
	addq	%rdx, %rcx
	popq	%rbp
	jmpq	*%rcx
LBB0_2:
	sarq	$3, %rax
	retq
LBB0_6:
	shlq	$3, %rax
	retq
LBB0_3:
	movq	%rsi, %rax
LBB0_4:
	imulq	%rax, %rax
LBB0_5:
	addq	$75, %rax
	retq
	.cfi_endproc
	.p2align	2, 0x90
	.data_region jt32
.set L0_0_set_5, LBB0_5-LJTI0_0
.set L0_0_set_6, LBB0_6-LJTI0_0
.set L0_0_set_2, LBB0_2-LJTI0_0
.set L0_0_set_3, LBB0_3-LJTI0_0
.set L0_0_set_4, LBB0_4-LJTI0_0
LJTI0_0:
	.long	L0_0_set_5
	.long	L0_0_set_6
	.long	L0_0_set_2
	.long	L0_0_set_3
	.long	L0_0_set_4
	.end_data_region
                                        ## -- End function
.subsections_via_symbols

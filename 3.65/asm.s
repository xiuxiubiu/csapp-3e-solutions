	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 3	sdk_version 11, 3
	.globl	_transpose                      ## -- Begin function transpose
	.p2align	4, 0x90
_transpose:                             ## @transpose
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	xorl	%r8d, %r8d
	movq	%rdi, %r9
	jmp	LBB0_1
	.p2align	4, 0x90
LBB0_4:                                 ##   in Loop: Header=BB0_1 Depth=1
	incq	%r8
	addq	$120, %r9
	addq	$8, %rdi
	cmpq	$15, %r8
	je	LBB0_5
LBB0_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB0_3 Depth 2
	testq	%r8, %r8
	je	LBB0_4
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	movq	%rdi, %rdx
	xorl	%esi, %esi
	.p2align	4, 0x90
LBB0_3:                                 ##   Parent Loop BB0_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movq	(%r9,%rsi,8), %rax
	movq	(%rdx), %rcx
	movq	%rcx, (%r9,%rsi,8)
	movq	%rax, (%rdx)
	incq	%rsi
	addq	$120, %rdx
	cmpq	%rsi, %r8
	jne	LBB0_3
	jmp	LBB0_4
LBB0_5:
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols

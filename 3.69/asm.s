	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 3	sdk_version 11, 3
	.globl	_test                           ## -- Begin function test
	.p2align	4, 0x90
_test:                                  ## @test
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movslq	(%rsi), %rax
	movslq	288(%rsi), %rcx
	addq	%rax, %rcx
	leaq	(%rdi,%rdi,4), %rax
	leaq	(%rsi,%rax,8), %rdx
	movq	8(%rsi,%rax,8), %rax
	movq	%rcx, 16(%rdx,%rax,8)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols
